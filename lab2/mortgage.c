//mortgage.c

#include <stdio.h>
int main ( void )
{
	//Initialize variables
	float principal; //initial amount borrowed (user entered)
	float balance; //balance owed
	float payment; //desired monthly payment (user entered)
	float interest; //interest rate(user entered)
	float interestVal;
	int month = 1;
	//Prompt user for information
	printf( "Please enter the value of the principal in dollars: ");
	scanf( "%f", &principal);
	printf( "Please enter the value of the monthly payment in dollars: ");
	scanf( "%f", &payment);
	printf( "Please enter the value of the interest: ");
	scanf( "%f", &interest);
	
	//Create Amortization Table
	printf("%10s\t%10s\t%10s\t%10s\n", "Month", "Payment", "Interest", "Balance");
	balance = principal;
	while( balance > 0){ //until balance runs out
		interestVal = interest*balance;
		balance = balance + interestVal - payment;
		if( balance < 0){ //so we don't overpay
			payment = payment + balance;
			balance = 0;
			}
		printf("%10d%8.2f%8.2f%8.2f\n", month, payment, interestVal, balance);
		month++;
	}
		
	return 0;
}
