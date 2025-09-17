#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000000  // 1 billion elements

// Comparison function for integers
int compare_ints(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;

    return (int_a > int_b) - (int_a < int_b);
}

// Check if sorted (optional, for verification)
int isSorted(int arr[], size_t n) {
    for (size_t i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int main() {
    // allocate dynamically (stack cannot hold 4GB+)
    int *arr = malloc(sizeof(int) * SIZE);
    if (!arr) {
        printf("Memory allocation failed. Try smaller SIZE.\n");
        return 1;
    }

    srand(time(NULL));
    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    printf("Sorting %zu random numbers with qsort()...\n", (size_t)SIZE);

    clock_t start = clock();
    qsort(arr, SIZE, sizeof(int), compare_ints);
    clock_t end = clock();

    printf("Done! Time taken: %.2f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    if (isSorted(arr, SIZE))
        printf("Array is sorted correctly.\n");
    else
        printf("Array is NOT sorted!\n");

    free(arr);
    return 0;
}
