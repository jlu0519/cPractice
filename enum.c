#include <stdio.h>

int main(){

    enum month {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
    enum month thisMonth = Sep;

    printf("%s","You compiled without seg fault!\n");
    printf("%d", thisMonth);
    printf("\n");

    return 0;

}
