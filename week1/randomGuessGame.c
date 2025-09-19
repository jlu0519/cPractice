#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(){

    //Clear the Screen for clean game play
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    //Generates random seed for the rand function
    srand(time(NULL));

    int answer = (rand() % 20) + 1;
    int userAnswer = 0;
    int i;

    // Program title and instructions 
    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20 which you must guess.\n\n");

    // For Testing only
    // printf("%d\n",answer);

    // Loop for the 5 tries to git Answer 
    for (i = 5; i > 0; i--){
        
            printf("You have %d tr%s left.\n", i, i == 1 ? "y" : "ies");
            printf("Enter a Guess: ");
            scanf("%d", &userAnswer);
         
            if(userAnswer == answer)
                {
                printf("\nCongratulations. You Guessed it!\n");

                // Ends loop early
                break;
                }
                else if(answer > userAnswer) // Checks to give user a hint 
                {
                printf("Sorry, %d is wrong. My number is greater than that.\n\n", userAnswer);
                }
                else if(answer < userAnswer) // Checks to give user a hint
                {
                printf("Sorry, %d is wrong. My number is less than that.\n\n", userAnswer);
                }
    }
}

int main(){
    char playAgain = 'a';

    do{
        playGame();
        printf("Do you want to play again? Y/N: ");
        scanf(" %c",&playAgain);
        printf("\n\n");
    }while(playAgain == 'y' || playAgain == 'Y');

    // Clears Screen Once game is finished
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    
  return 0;
}
