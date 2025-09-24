#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Functions Intialized
void strCat();

int sLength(const char string[]); 

bool strCompare();

// Main program
int main(){
    const char word1[] = "Luke";
    const char word2[] = "Timothy";
    const char word3[] = "Young";

    printf("%d\t%d\t%d\t\n",sLength(word1),sLength(word2),sLength(word3));
}

// Function defintions
void strCat(){

}

int sLength(const char string[]) {
    int count = 0;
    
    while(string[count] != '\0')
        ++count;

    return count;
}

bool strCompare() {

}

