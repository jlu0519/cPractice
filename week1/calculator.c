#include <stdio.h>

int main() {
    double a = 0;
    double b = 0;
    double answer = 0;
    int userChoice = 0;
    int quit = 0;

    while(quit != 1){

    // Title and Option Prompt
    printf("This is a Basic Calculator!\n");
    printf("Please Choose an option:\n 1-Add\n 2-Sub\n 3-Multiply\n 4-Quit\n");
    
    // Takes user's choice input
    scanf("%d", &userChoice);
   
    switch(userChoice) {
        case 1:
            printf("Please enter first number!\n"); 
            scanf("%lf", &a);
            printf("Please enter second number!\n"); 
            scanf("%lf", &b);
            answer = a + b;
            printf("Answer: %lf\n", answer);
            break;
        
        case 2:
            printf("Please enter first number!\n"); 
            scanf("%lf", &a);
            printf("Please enter second number!\n"); 
            scanf("%lf", &b);
            answer = a - b;
            printf("Answer: %lf\n", answer);
            break;

        case 3:
            printf("Please enter first number!\n"); 
            scanf("%lf", &a);
            printf("Please enter second number!\n"); 
            scanf("%lf", &b);
            answer = a * b;
            printf("Answer: %lf\n", answer);
            break;

        case 4:
            printf("Goodbye!\n");
            quit = 1;
            break;
        
        default:
            printf("Incorrect Entry Please. Please Try again!");
            break;
    }
    }
    return 0;
}
