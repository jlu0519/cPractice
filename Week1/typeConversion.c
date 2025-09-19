#include <stdio.h>

int main(){
    float a = 23.00;
    char b = 'b';
    int c = 24;
    int d;
    int e;
    // The cast Operator has a higher pecedence over eveything 
    // execpt unary minus and unary plus
    
    // Cast Operator
    
    d = ((int) a);
    e = (int) b;
    

    // sizeof operator
    // Evaluated at compile time and not at runtime, unless variable length
    // Array is used in its argument

    // This outputs the number of bytes occupied by a variable of type int
    c = sizeof(c);

    // Asterisk "*" is an operator that represents a pointer to a variable


    // ? is a ternary operator


    printf("The value of a is %d\n", d);
    printf("The value of b is %d\n", e);
    printf("The value of c is %d\n", c);
    
    return 0;

}
