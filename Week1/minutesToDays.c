#include <stdio.h>

int main(){
    const double minutesInAYear = 525600;
    const double minutesInADay = 1440;
    double minutes = 0;
    double days = 0;
    double years = 0;


    printf("Please Enter Minutes to be converted to days and years\n");
    scanf("%lf", &minutes);

    days = minutes / minutesInADay;

    while (days > 365){
        ++years;
        days = days - 365;
    }


    printf("%.2lf : Minutes is equal to %.2lf : Years and %.2lf : Days!\n", minutes, years, days);

    return 0;
}
