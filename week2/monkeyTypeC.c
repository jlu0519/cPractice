// typetest.c
// Simple terminal typing test (MonkeyType-like) for POSIX terminals.
// Compile: gcc -O2 -std=c11 -o typetest typetest.c
// Run: ./typetest

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>

static struct termios orig_termios;

void disable_raw_mode(void) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode(void) {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disable_raw_mode);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG); // no echo, non-canonical
    raw.c_iflag &= ~(IXON | ICRNL); // disable ctrl-s/q and CR->NL
    raw.c_oflag &= ~(OPOST);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1; // 0.1s read timeout
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

long diff_millis(struct timespec a, struct timespec b) {
    long sec = b.tv_sec - a.tv_sec;
    long nsec = b.tv_nsec - a.tv_nsec;
    return sec * 1000 + nsec / 1000000;
}

void clear_screen() {
    write(STDOUT_FILENO, "\x1b[2J\x1b[H", 7);
}

void sigint_handler(int sig) {
    (void)sig;
    disable_raw_mode();
    clear_screen();
    printf("Interrupted. Exiting.\n");
    exit(1);
}

int main(void) {
    // Example passages (add or load from file if desired)
    const char *passages[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Typing tests measure words per minute and accuracy. Practice daily to improve.",
        "C is a small, efficient language that gives you fine-grained control.",
        "This is a short passage for testing your typing speed on the terminal."
    };
    const size_t PASSAGE_COUNT = sizeof(passages) / sizeof(passages[0]);

    // Pick random passage
    srand((unsigned int)time(NULL) ^ (unsigned int)getpid());
    const char *target = passages[rand() % PASSAGE_COUNT];
    size_t target_len = strlen(target);

    // Prepare terminal
    signal(SIGINT, sigint_handler);
    enable_raw_mode();
    clear_screen();

    printf("Simple MonkeyType clone (terminal)\n");
    printf("Type the passage shown below. Backspace works. Press Ctrl-C to quit.\n\n");
    printf("PASSAGE:\n%s\n\n", target);
    printf("Typed:\n");

    // buffers
    char *typed = calloc(target_len + 1, 1);
    if (!typed) {
        perror("calloc");
        disable_raw_mode();
        return 1;
    }

    size_t pos = 0;
    size_t typed_chars = 0;
    size_t correct_chars = 0;
    int finished = 0;
    struct timespec start_time, end_time;
    int started = 0;

    // show initial typed line
    write(STDOUT_FILENO, "\n", 1);

    while (!finished) {
        char c;
        ssize_t n = read(STDIN_FILENO, &c, 1);
        if (n == -1) {
            perror("read");
            break;
        } else if (n == 0) {
            // timeout - continue
            continue;
        } else {
            // start timer on first keypress
            if (!started) {
                clock_gettime(CLOCK_MONOTONIC, &start_time);
                started = 1;
            }

            // handle printable chars
            if ((unsigned char)c >= 32 && c <= 126) {
                if (pos < target_len) {
                    typed[pos] = c;
                    pos++;
                    typed_chars++;
                }
                // if pos >= target_len we still consume but ignore extra
            } else if (c == 127 || c == 8) { // backspace
                if (pos > 0) {
                    pos--;
                    typed[pos] = '\0';
                    // note: typed_chars doesn't decrement because user did type previously;
                    // for WPM along many implementations we count keystrokes. We'll track typed_chars as typed keystrokes (including backspace)
                    typed_chars++;
                }
            } else if (c == '\r' || c == '\n') {
                // ignore newline; we rely on finishing at target length
            } else {
                // ignore other control keys
            }

            // check finished
            if (pos >= target_len) {
                finished = 1;
                clock_gettime(CLOCK_MONOTONIC, &end_time);
            }

            // compute correctness per-character for display
            correct_chars = 0;
            for (size_t i = 0; i < pos && i < target_len; ++i) {
                if (typed[i] == target[i]) correct_chars++;
            }

            // redraw typed line with simple coloring
            // Move cursor up one line, clear it, print typed with coloring, then move to next line
            // Use: green for correct, red for incorrect, reset for rest
            // ANSI: \x1b[32m = green, \x1b[31m = red, \x1b[0m reset
            // We'll rewrite Typed: line entirely
            write(STDOUT_FILENO, "\x1b[s", 3); // save cursor
            write(STDOUT_FILENO, "\x1b[2K\r", 4); // clear line
            // Print each character colored based on correctness
            for (size_t i = 0; i < pos; ++i) {
                if (i < target_len && typed[i] == target[i]) {
                    write(STDOUT_FILENO, "\x1b[32m", 5);
                    write(STDOUT_FILENO, &typed[i], 1);
                    write(STDOUT_FILENO, "\x1b[0m", 4);
                } else {
                    write(STDOUT_FILENO, "\x1b[31m", 5);
                    write(STDOUT_FILENO, &typed[i], 1);
                    write(STDOUT_FILENO, "\x1b[0m", 4);
                }
            }
            // If user hasn't finished, print the remaining target chars (untyped) in dim
            if (pos < target_len) {
                write(STDOUT_FILENO, "\x1b[2m", 4); // dim
                write(STDOUT_FILENO, &target[pos], target_len - pos);
                write(STDOUT_FILENO, "\x1b[0m", 4); // reset
            }
            write(STDOUT_FILENO, "\x1b[u", 3); // restore cursor (keeps cursor at end of line)

            // For terminals that don't handle saved cursor the same, also print a newline status line below:
            // Move cursor to next line and print stats
            write(STDOUT_FILENO, "\r\n", 2);
            // compute elapsed time in milliseconds if started
            long elapsed_ms = 0;
            if (started) {
                struct timespec now;
                clock_gettime(CLOCK_MONOTONIC, &now);
                elapsed_ms = diff_millis(start_time, now);
            }
            double minutes = (elapsed_ms > 0) ? (elapsed_ms / 60000.0) : 0.0;
            double wpm = 0.0;
            if (minutes > 0.0) {
                // WPM = (correct_chars / 5) / minutes
                wpm = (correct_chars / 5.0) / minutes;
            }
            int accuracy_pct = (pos > 0) ? (int)((correct_chars * 100.0) / (double)pos + 0.5) : 100;

            // clear status line and print
            write(STDOUT_FILENO, "\x1b[2K\r", 4);
            dprintf(STDOUT_FILENO, "Progress: %zu/%zu | WPM (live): %.1f | Accuracy: %d%%\n", pos, target_len, wpm, accuracy_pct);
            // move cursor up to typed line to continue overwriting (so typed line remains top)
            write(STDOUT_FILENO, "\x1b[A", 3);
        }
    }

    // Finished: compute final stats
    if (!started) {
        clock_gettime(CLOCK_MONOTONIC, &end_time);
    }

    long total_ms = diff_millis(start_time, end_time);
    double minutes = total_ms / 60000.0;
    if (minutes <= 0.0) minutes = 1.0/60000.0; // avoid div by zero (very fast)
    // recompute correct chars (full)
    correct_chars = 0;
    for (size_t i = 0; i < target_len; ++i) if (typed[i] == target[i]) correct_chars++;

    double final_wpm = (correct_chars / 5.0) / minutes;
    int final_accuracy = (int)((correct_chars * 100.0) / (double)target_len + 0.5);

    // restore terminal and print results
    disable_raw_mode();
    write(STDOUT_FILENO, "\n\n", 2);
    printf("RESULTS\n");
    printf("Target: %s\n", target);
    printf("Typed : %s\n", typed);
    printf("Time  : %ld ms\n", total_ms);
    printf("WPM   : %.1f\n", final_wpm);
    printf("Acc   : %d%% (%zu/%zu correct chars)\n", final_accuracy, correct_chars, target_len);

    free(typed);
    return 0;
}
