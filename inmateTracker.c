#include <stdio.h>
#include <string.h>

enum Classification{GP, PC, ADSEG, CIVIL, SVP};

struct Inmate{
        int age;
        enum Classification Class;
        char firstName[25];
        char lastName[25];

    };

int main(int argc,char *argv[]){
   
        struct Inmate john;
        john.age =25;
        john.Class = GP;
        strcpy(john.firstName,  "John");
        strcpy(john.lastName, "Miller");


        printf("John is %d years old!\n", john.age);

    
    

    return 0;
}

    
        
