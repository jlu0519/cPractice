
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000

struct person {
    char name[50];  
    int age;
};

int main() {
    struct person People[SIZE];
    int i;

    // Fill array
    for (i = 0; i < SIZE; i++) {
        strcpy(People[i].name, "Name");
        People[i].age = 20 + (i % 50);
    }

    // Print first 10 elements (printing all 100000 is too much)
    for (i = 1; i < SIZE + 1; i++) { 
		printf("Person %d: Name = %s, Age = %d\n", i, People[i].name, People[i].age);
    }

    return 0;
}
