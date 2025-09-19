#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    printf("Please Enter your name!");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < 10000000; i++) {
        printf("Hello ");
        for (int j = 0; j < strlen(name); j++) {
            printf("%c", name[j]);
        }
        printf("\n"); // Newline for readability
    }

    return 0;
}
