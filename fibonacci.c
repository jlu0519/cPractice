#include <stdio.h>

long long fibonacciSequence(long long a, long long b){
    return (a + b);
}

int main(){
    int i;
    long long firstNumber = 1;
    long long nextNumber = 1;
    long long temp = 0;
    int userInput = 90;

    for(i = 0; i < userInput; i++){
        temp = nextNumber;
        nextNumber = fibonacciSequence(firstNumber, nextNumber);
        firstNumber = temp;
        printf("%lld\n", nextNumber);
    }

    return 0;
}
