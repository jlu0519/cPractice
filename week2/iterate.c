#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main(){
	int a = SIZE + 1;
	int b = 0;


	for (int i = 0; i < SIZE; i++){
	  a--;
	  b++;
	  printf("%d,%d\n",a,b);
	}


	return 0;
}
