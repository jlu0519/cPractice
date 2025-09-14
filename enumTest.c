#include <stdio.h> 

enum Company{GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};

int main(){
    enum Company a = MICROSOFT;
    enum Company b = XEROX;
    enum Company c = EBAY;
    

    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);

    return 0;

}
