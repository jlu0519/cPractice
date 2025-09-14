#include <stdio.h>
#include <string.h>

int main(){

    int intA[10];
    int i = 0;


for(i = 0; i < sizeof(intA) / sizeof(intA[0]); i++) {
    intA[i] = i+1;
    printf("%d\n", intA[i]);
    printf("%p\n", (void*)&intA[i]);
}


    return 0;
}
