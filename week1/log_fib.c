#include <stdio.h>
#include <gmp.h>

void multiply(mpz_t result[2][2], mpz_t a[2][2], mpz_t b[2][2]) {
    mpz_t x, y, z, w, t1, t2;
    mpz_inits(x, y, z, w, t1, t2, NULL);

    // x = a00 * b00 + a01 * b10
    mpz_mul(t1, a[0][0], b[0][0]);
    mpz_mul(t2, a[0][1], b[1][0]);
    mpz_add(x, t1, t2);

    // y = a00 * b01 + a01 * b11
    mpz_mul(t1, a[0][0], b[0][1]);
    mpz_mul(t2, a[0][1], b[1][1]);
    mpz_add(y, t1, t2);

    // z = a10 * b00 + a11 * b10
    mpz_mul(t1, a[1][0], b[0][0]);
    mpz_mul(t2, a[1][1], b[1][0]);
    mpz_add(z, t1, t2);

    // w = a10 * b01 + a11 * b11
    mpz_mul(t1, a[1][0], b[0][1]);
    mpz_mul(t2, a[1][1], b[1][1]);
    mpz_add(w, t1, t2);

    // Set result matrix
    mpz_set(result[0][0], x);
    mpz_set(result[0][1], y);
    mpz_set(result[1][0], z);
    mpz_set(result[1][1], w);

    mpz_clears(x, y, z, w, t1, t2, NULL);
}

// Matrix exponentiation: raise matrix to power n
void matrix_power(mpz_t result[2][2], int n) {
    mpz_t base[2][2], temp[2][2];
    for (int i = 0; i < 2; i++) {
        mpz_init(temp[i][0]);
        mpz_init(temp[i][1]);
        mpz_init(base[i][0]);
        mpz_init(base[i][1]);
    }

    // Initialize base matrix: [1 1; 1 0]
    mpz_set_ui(base[0][0], 1);
    mpz_set_ui(base[0][1], 1);
    mpz_set_ui(base[1][0], 1);
    mpz_set_ui(base[1][1], 0);

    // Initialize result as identity matrix: [1 0; 0 1]
    mpz_set_ui(result[0][0], 1);
    mpz_set_ui(result[0][1], 0);
    mpz_set_ui(result[1][0], 0);
    mpz_set_ui(result[1][1], 1);

    while (n > 0) {
        if (n % 2 == 1) {
            multiply(temp, result, base);
            // Copy temp to result
            mpz_set(result[0][0], temp[0][0]);
            mpz_set(result[0][1], temp[0][1]);
            mpz_set(result[1][0], temp[1][0]);
            mpz_set(result[1][1], temp[1][1]);
        }
        multiply(temp, base, base);
        // Copy temp to base
        mpz_set(base[0][0], temp[0][0]);
        mpz_set(base[0][1], temp[0][1]);
        mpz_set(base[1][0], temp[1][0]);
        mpz_set(base[1][1], temp[1][1]);

        n /= 2;
    }

    for (int i = 0; i < 2; i++) {
        mpz_clear(temp[i][0]);
        mpz_clear(temp[i][1]);
        mpz_clear(base[i][0]);
        mpz_clear(base[i][1]);
    }
}

// Compute Fibonacci number using matrix exponentiation
void fibonacci_log_gmp(int n) {
    if (n == 0) {
        printf("F(0) = 0\n");
        return;
    }

    mpz_t result[2][2];
    mpz_init(result[0][0]);
    mpz_init(result[0][1]);
    mpz_init(result[1][0]);
    mpz_init(result[1][1]);

    matrix_power(result, n - 1);

    gmp_printf("F(%d) = %Zd\n", n, result[0][0]);

    mpz_clear(result[0][0]);
    mpz_clear(result[0][1]);
    mpz_clear(result[1][0]);
    mpz_clear(result[1][1]);
}

int main() {
    int n;
    printf("Enter Fibonacci term number (n): ");
    scanf("%d", &n);
    fibonacci_log_gmp(n);
    return 0;
}
