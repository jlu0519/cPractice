#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000000  // 1 Billion elements

// Function declarations
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
int isSorted(int arr[], int n);  // <--- forward declaration

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Check if sorted
int isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int main() {
    static int arr[SIZE];
    srand(time(NULL));

    // Fill array with random numbers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    printf("Sorting %d random numbers...\n", SIZE);

    clock_t start = clock();
    quicksort(arr, 0, SIZE - 1);
    clock_t end = clock();

    printf("Done! Time taken: %.2f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    if (isSorted(arr, SIZE))
        printf("Array is sorted correctly.\n");
    else
        printf("Array is NOT sorted!\n");

    return 0;
}
