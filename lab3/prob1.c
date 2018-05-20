//prob1.c
//Description: This program asks the user to enter two integer numbers and finds the greatest common divisor between them. The program containsa function called getgcd() which takes two integers as inputs and returns an integer as an output.
#include <stdio.h>
#include <math.h>

//Function Prototype
int getgcd(int a, int b);
//Main
int main() {
int a, b, c;
	//Prompt for inputs
	printf("Please input two integers: ");
	scanf("%d%d", &a, &b);
	//Use function to get output
	c = getgcd(a, b);
	printf("The gcd of %d and %d is %d.", a,b,c);
	return 0;
}

//Function Definition
int getgcd(int a, int b) 
{
	int c;
	int t;
	while(b != 0) 
	  {
		t = b;
		b = b % a;
		a = t;
		}
		c = a;
return c;
}



