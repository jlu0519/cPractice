#include<stdio.h>
#include<stdlib.h>

int static add(int a, int b){
    return (a + b);
}


int main(){
    int a;
    int b;
    int c = 0;
    printf("Please enter a number for a:\n");
    scanf("%d", &a);

    printf("Please enter a number for b:\n");
    scanf("%d", &b);

    printf("Answer:\n");


    c = add(a,b);

    printf("%d\n", c);

    return 0;
}
