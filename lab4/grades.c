//grades.c
#include<stdio.h>
#include<math.h>

int sum(int a[], int size);

int main() {
	int i, s= 0, n = 0;
	int grades[50];
	// read in data from array
	scanf("%d", &grades[n]);
	while(grades[n] > 0) {
		n++;
		scanf("%d", &grades[n]);
	}
	// Finding Average
	int std = 0;
	double Avg, stdAvg, stdDev;
	s = sum(grades, n);
	Avg = s/n;
	printf("The average is: %lf\n", Avg); //Display Avg
	
	// Finding Standard Deviation
	for(i = 0; i < n; i++){
		std = std + (pow((grades[i] - Avg), 2)); //accumulate sum into variable "std"
	}
	stdAvg = std/n; //obtain Avg for Standard Deviation
	stdDev = sqrt(stdAvg);
	printf("The Standard Deviation is: %lf\n", stdDev);
	
	return 0;
}

//sum Function Definition
int sum(int a[], int size) {
	int i, s=0;
	for(i = 0; i < size; i++) 
		s = s + a[i];
	
	return s;
}


		
