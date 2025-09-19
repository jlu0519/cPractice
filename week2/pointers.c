#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;

    printf("a = %d\n", a);           // prints: a = 10
    printf("*p = %d\n", *p);         // prints: *p = 10
    printf("&a = %p\n", (void*)&a);  // prints address of a
    printf("p = %p\n", (void*)p);    // same as &a
    printf("&p = %p\n", (void*)&p);  // address of the pointer itself

    *p = 20;                         // sets a = 20 via pointer
    printf("a (after *p = 20) = %d\n", a);  // prints: a = 20

    return 0;
}
