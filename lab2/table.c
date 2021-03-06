// table.c
// Program description: This program displays an integer multiplication table after asking the user for the size of it on X and Y axes.

#include <stdio.h>

int main( void )
{
	// Initialize Variables
	int xValue; // value of the size of X axis to be entered by user
	int yValue; // value of the size of Y axis to be entered by user
	int incrementX;
	int incrementY;
	
	// Program description 
	printf( "This program will display an integer multiplication table with User-specified X and Y values.\n" );

	// Prompt user for information
	printf( "What size would you like the X axes to be? " ); //prompt
	scanf( "%d", &xValue ); //read an integer
	printf( "What size would you like the Y axes to be? " );
	scanf( "%d", &yValue );
	
	// Create Table
	for( incrementY = 0 ; incrementY < (yValue + 1 ) ; incrementY = incrementY + 1) {
		for( incrementX = 0 ; incrementX < (xValue + 1 ); incrementX = incrementX + 1) {
			if( incrementX == 0 && incrementY == 0){
				printf("*\t");
			}else if(incrementY == 0) {
				printf("%d\t", incrementX);
			}else if(incrementX == 0) {
				printf("%d\t", incrementY); 
			}else{
				printf("%d\t", (incrementX * incrementY));
			}
		}
		printf("\n");
	}
	return 0;
}

