#include<stdio.h>
#include<stdlib.h>


int main(){

	double payRate = 33.173;
	double taxRate[3]= {0.15,0.20,0.25};
	double hoursWorked = 0;
	double regularTimePay = 0;
	double overtimePay = 0;
	double overtimeHours = 0;

	// Pay
	double grossPay = 0;
	double taxesOwed = 0;
	double netPay = 0;

	//Loop flag
	int userChoice = 1;

	while(userChoice !=0){
	// While Loop that ensures correct user input
	do{
		printf("Please enter the hours you worked this week:\n");
		scanf("%lf", &hoursWorked);

		if(hoursWorked < 0){
			printf("Invalid Input Please try again.\n");
		}

	}while(hoursWorked < 0);

	//Pay Calculations
	
	if(hoursWorked <= 40){
		regularTimePay = payRate * hoursWorked;
		grossPay = regularTimePay;
	
	} else {
		regularTimePay = payRate * 40;
		overtimeHours = hoursWorked - 40;
		overtimePay = (payRate * 1.5) * overtimeHours;

		grossPay = regularTimePay + overtimePay;
	}

	// Tax Brackets
	

	if (grossPay <= 300.00){
		taxesOwed = grossPay * taxRate[0];
		netPay = grossPay - taxesOwed;
	}else if(grossPay <=450){
		taxesOwed = (300 * taxRate[0]) + ((grossPay - 300) * taxRate[1]);
		netPay = grossPay - taxesOwed;
	}else{
		taxesOwed = (300 * taxRate[0]) + (150 * taxRate[1])+ ((grossPay - 450) * taxRate[2]);
		netPay = grossPay - taxesOwed;
	}

	printf("You worked %.2lf hours\nYour gross pay is %.2lf\nTaxes owed: %.2lf\nWeekly net pay: %.2lf\n", hoursWorked, grossPay, taxesOwed, netPay);

	printf("Would you like to preform another calculation? 1 - Yes, 0 - No\n");
	scanf("%d",&userChoice);
	}
	

	return 0;
}
