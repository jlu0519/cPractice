#include <stdio.h>
#include <stdlib.h>

void printBoard(char board[3][3]);
int checkWin(char board[3][3]);

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int gameOver = 0;
    int row = 0;
    int column = 0;

    while (gameOver != 1) {
        // Player 1 move
        printBoard(board);
        printf("Player 1 (x), pick a place (row column): ");
        scanf("%d %d", &row, &column);

        //Changed for user to go by normal row numbering
        row = row - 1;
        column = column - 1;

        if (board[row][column] == ' ') {
            board[row][column] = 'x';
        } else {
            printf("That spot is taken. Try again.\n");
            continue;
        }

        printBoard(board);
        gameOver = checkWin(board);
        if (gameOver == 1) {
            printf("Player 1 Wins!\n");
            break;
        }

        // Player 2 move
        printf("Player 2 (o), pick a place (row column): ");
        scanf("%d %d", &row, &column);
        
        //Changed for user to go by normal row numbering
        row = row - 1;
        column = column - 1;

        if (board[row][column] == ' ') {
            board[row][column] = 'o';
        } else {
            printf("That spot is taken. Try again.\n");
            continue;
        }

        gameOver = checkWin(board);
        if (gameOver == 1) {
            printf("Player 2 Wins!\n");
            break;
        }
    }

    return 0;
}

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("-----------\n");
    }
    printf("\n");
}

int checkWin(char board[3][3]) {
    char *cursor;
    int gameOver = 0;

    // Check rows
    for (int i = 0; i < 3; i++) {
        cursor = &board[i][0];
        if (*cursor != ' ' && *cursor == *(cursor + 1) && *cursor == *(cursor + 2)) {
            gameOver = 1; 
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        cursor = &board[0][i];
        if (*cursor != ' ' && *cursor == *(cursor + 3) && *cursor == *(cursor + 6)) {
            gameOver = 1; 
        }
    }

    // Check diagonals
    cursor = &board[0][0];
    if (*cursor != ' ' && *cursor == board[1][1] && *cursor == board[2][2]) {
        gameOver = 1; 
    }

    cursor = &board[0][2];
    if (*cursor != ' ' && *cursor == board[1][1] && *cursor == board[2][0]) {
        gameOver = 1; 
    }

    return gameOver;
}
