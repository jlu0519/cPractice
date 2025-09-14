#include <stdio.h>


int main(){
    // Variable Assignment and Intializiation 
    double width = 0;
    double height = 0;
    double perimeter = 0;
    double area = 0;


    // User Input
    printf("Please Enter the width of a rectangle!\n");
    scanf("%lf", &width);

    printf("Please Enter the height of a rectangle!\n");
    scanf("%lf", &height);
    
    // Calculations
    perimeter = (2 * height) + (2 * width);
    area = width * height;
    
    // Final Output
    printf("The perimeter of your rectangle is %lf!\n", perimeter);

    printf("The area of your rectangle is %lf!\n", area);

    return 0;
}

