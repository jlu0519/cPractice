#include<stdio.h>
#include<stdlib.h>


int main(){
    int i;
    int p;
    int numbers[3][4] = {
                        {10, 20, 40, 23},
                        {32, 23, 43, 12},
                        {23, 0, 0, 23}
                        };

    for(i = 0; i < 3; ++i)
    {
        for(p = 0; p < 4; ++p)
        {
            printf("%d || ", numbers[i][p]);
        }
        printf("\n");
    }

    return 0;
}
