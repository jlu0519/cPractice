#include <stdio.h>

// Tax bracket structure
typedef struct {
    double limit;   // income limit for bracket
    double rate;    // tax rate
} Bracket;

// Function to calculate progressive tax
double calcTax(double income, Bracket brackets[], int size) {
    double tax = 0.0;
    double prevLimit = 0.0;

    for (int i = 0; i < size; i++) {
        if (income > brackets[i].limit) {
            tax += (brackets[i].limit - prevLimit) * brackets[i].rate;
            prevLimit = brackets[i].limit;
        } else {
            tax += (income - prevLimit) * brackets[i].rate;
            break;
        }
    }
    return tax;
}

int main() {
    double payRate = 33.173;   // hourly base rate (change as needed)
    double hoursWorked = 0;
    double regularPay = 0, overtimePay = 0, grossPay = 0;

    // Ask for hours worked in 2-week pay period
    printf("Enter hours worked in this 2-week pay period: ");
    scanf("%lf", &hoursWorked);

    // Overtime (time-and-a-half over 80 hrs/2 weeks)
    if (hoursWorked <= 80) {
        regularPay = payRate * hoursWorked;
    } else {
        regularPay = payRate * 80;
        overtimePay = (payRate * 1.5) * (hoursWorked - 80);
    }
    grossPay = regularPay + overtimePay;

    // ---- TAX BRACKETS (scaled to per-paycheck) ----

    // Federal brackets (26 paychecks/year)
    Bracket federal[] = {
        {11600.0/26, 0.10},
        {47150.0/26, 0.12},
        {100525.0/26, 0.22},
        {191950.0/26, 0.24},
        {243725.0/26, 0.32},
        {609350.0/26, 0.35},
        {1e9, 0.37} // large number for "infinity"
    };

    // California brackets (26 paychecks/year)
    Bracket california[] = {
        {11999.0/26, 0.01},
        {28999.0/26, 0.02},
        {45999.0/26, 0.04},
        {62999.0/26, 0.06},
        {78999.0/26, 0.08},
        {541499.0/26, 0.093},
        {649999.0/26, 0.103},
        {1000000.0/26, 0.113},
        {1e9, 0.123} // ignore +1% surcharge for simplicity
    };

    int fedSize = sizeof(federal)/sizeof(federal[0]);
    int caSize = sizeof(california)/sizeof(california[0]);

    // Calculate taxes
    double federalTax = calcTax(grossPay, federal, fedSize);
    double caTax = calcTax(grossPay, california, caSize);

    // FICA
    double socialSecurity = grossPay * 0.062;
    double medicare = grossPay * 0.0145;

    // Totals
    double totalTax = federalTax + caTax + socialSecurity + medicare;
    double netPay = grossPay - totalTax;

    // ---- OUTPUT ----
    printf("\n--- Pay Summary (2-week period) ---\n");
    printf("Hours worked: %.2lf\n", hoursWorked);
    printf("Regular pay: $%.2lf\n", regularPay);
    printf("Overtime pay: $%.2lf\n", overtimePay);
    printf("Gross pay: $%.2lf\n", grossPay);
    printf("Federal tax: $%.2lf\n", federalTax);
    printf("CA state tax: $%.2lf\n", caTax);
    printf("Social Security: $%.2lf\n", socialSecurity);
    printf("Medicare: $%.2lf\n", medicare);
    printf("Total tax: $%.2lf\n", totalTax);
    printf("Net pay: $%.2lf\n", netPay);
    printf("Effective tax rate: %.2lf%%\n", (totalTax/grossPay)*100);

    return 0;
}
