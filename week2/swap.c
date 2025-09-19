#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    int a = 0;
    int b = 0;
    
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif


    printf("This is a basic Integer swap program that utilizes pointers!\n\n\n");

    printf("Please enter a value for a\n");
    scanf("%d", &a);

    printf("Please enter a value for b\n");
    scanf("%d", &b);
    printf("\n");


    printf("a is %d before swap.\n", a);
    printf("b is %d before swap.\n", b);
    printf("\n");

    swap(&a,&b);

    printf("a is now %d\n", a);
    printf("b is now %d\n", b);

    return 0;
}
