#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MONTHS 12
#define YEARS 5

int main(){
   //intialize rainfall data for 2011-2016 
    float rain[YEARS][MONTHS] = 
    {
        {2.3, 2, 4, 4, 8.6, 2.4, 1.32, 2.98, 1.2, 4, 12, 2},
        {0.3, 2, 4, 2, 1.0, 3.4, 1.2, 3.98, 2.2, 4, 2, 1},
        {0.3, 1.2, 0.32, 2, 8.6, 3.4, 1.32, 3.98, 4.2, 3, 2.2, 4},
        {0.3, 2, 4, 4, 0.6, .4, 1, 2.8, 2.2, 4, 1.2, 0.1},
        {3.3, 2, 2, 2, 8.6, 2.4, 9.32, 0.98, 0.2, 0.9, 12, 2}
    };

    int year, month;
    float subtot, total;

    printf("YEAR\t  RAINFALL\t(inches)\n");

    for(year = 0, total =0; year < YEARS; year++)
    {
           for(month = 0, subtot =0; month < MONTHS; month++)
           {
                subtot+= rain[year][month];
           }
        printf("%5d \t\t%15.1f\n", 2011 +year, subtot);
        total += subtot;
    }

    printf("\nThe yearly average %.1f inches.\n", total/YEARS);

    printf("MONTHLY AVERAGES: \n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

    for(month = 0; month < MONTHS; month++)
    {
        for(year = 0, subtot = 0; year < YEARS; year++)
            subtot =+ rain[year][month];

        printf("%4.1f ", subtot/YEARS);
    }

    printf("\n");

    return 0;
}
    
