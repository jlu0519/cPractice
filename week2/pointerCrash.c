#include <stdio.h>

int main() {
    int *p;

    p = (int *)100;  // Force pointer to point to address 100 (probably invalid)
    
    printf("Pointer p is set to address: %p\n", (void *)p);

    // Now try to write 42 to *p
    *p = 42;  // WARNING: This is almost guaranteed to crash your program!

    printf("Value at address 100 is now %d\n", *p);

    return 0;
}
