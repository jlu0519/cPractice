#include <stdio.h>
#include <gmp.h>

void fibonacci_gmp(int n) {
    mpz_t a, b, temp;
    mpz_init_set_ui(a, 1);  // F(1)
    mpz_init_set_ui(b, 1);  // F(2)
    mpz_init(temp);

    for (int i = 2; i < n; i++) {
        mpz_set(temp, b);        // temp = b
        mpz_add(b, a, b);        // b = a + b
        mpz_set(a, temp);        // a = temp
    }

    gmp_printf("F(%d) = %Zd\n", n, b);

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(temp);
}

int main() {
    int n;
    printf("Enter Fibonacci term: ");
    scanf("%d", &n);
    fibonacci_gmp(n);
    return 0;
}
