//Text Menu Calculator
#include <stdio.h>
#include <math.h>

//Prototypes
float add(int A, int B);
float subtract(int A, int B);
float multiply(int A, int B);
float divide(int A, int B);

//Main
int main(){
	int A, B, Operation, W;
	float Sum, Diff, Prod, Quo;
	printf("Text Menu Calculator\n");
	//Prompt
	W = 1;
	while( W != 0) {
		printf("Do you to Add(1), Subtract(2), Multiply(3), Divide(4), Quit(5)? Please enter the designated value: ");
		scanf("%d", &Operation);
		if(Operation == 5){
		return 0;
	}
		
	printf("Please enter your first number: ");
	scanf("%d", &A);
	printf("Please enter your second number: ");
	scanf("%d", &B);
		
	if( Operation == 1) {
		Sum = add(A, B);
		printf(" %d + %d = %3.2f ", A, B, Sum);
	} else if(Operation == 2) {
		Diff = subtract(A, B);
		printf(" %d - %d = %3.2f ", A, B, Diff);
	} else if(Operation == 3) {
		Prod = multiply(A, B);
		printf(" %d * %d = %3.2f ", A, B, Prod);
	} else if(Operation == 4) {
		Quo = divide(A, B);
		printf(" %d / %d = %3.2f ", A, B, Quo);
	} else if(Operation == 5) {
		W = 0;
		return 0;
		}
	}
return 0;
}

//Function Definitions
float add(int A, int B){
	float sum;
	sum = (A + B);
	return sum;
}

float subtract(int A, int B){
	float diff;
	diff = (A - B);
	return diff;
}

float multiply(int A, int B){

	float prod;
	prod = (A * B);
	return prod;
}

float divide(int A, int B){
	float quo;
	quo = (A/B);
	return quo;
}



