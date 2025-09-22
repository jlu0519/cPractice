#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b); 

float absoluteValue(float a ); 

float squareRoot(float a); 


int main() {
    int firstInt = 16;
    int secondInt = 64;
    int gcdAnswer = 0;

    gcdAnswer = gcd(firstInt, secondInt);

    printf("The gcd of %d and %d is: %d\n\n",firstInt, secondInt, gcdAnswer);
    
    float absolute = -25.39;
    float absoluteAnswer = 0;
    
    absoluteAnswer = absoluteValue(absolute);

    printf("The absolute value of %.2lf is: %.2lf\n\n", absolute, absoluteAnswer);
    
    float squared = 3294239.34;
    float root = 0;

    root = squareRoot(squared);

    printf("The squared root of %.2lf is: %.2lf\n\n", squared, root);

    return 0;
}


int gcd(int a, int b) {
   if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

float absoluteValue(float a ) {
    if(a < 0) {
        a = -a;
    }

    return a;
}


float squareRoot(float a) {
    const float epsilon = .00001;
    float guess = 1.0;
    float returnValue = 0.0;

    if (a < 0){
        printf("Negative argument to Square Root.\n");
        returnValue = -1.0;
    }
    
    if(returnValue != -1.0) {
    while ( absoluteValue(guess * guess - a) >= epsilon )
        guess = ( a / guess + guess) / 2.0;
        returnValue = guess;
    }

    return returnValue;

}
