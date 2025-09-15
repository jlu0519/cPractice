#include <stdio.h>

enum Classification{GP, PC, ADSEG, CIVIL, SVP};

int main(int argc,char *argv[]){
   

    struct inmate{
        int bookingNumber;
        int age;
        enum Classification Class;
        char firstName[];
        char lastName[];

    };


    return 0;
}

    
        
