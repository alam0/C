#include <stdio.h>

// Custom Calculator for the equation for Coulombs Law: F = k*Q1*Q2/(R*R)
int main (void)
{
	// Initialize Variables
	float F; // Electric Field Force
	long k = 8987551787; // Coulombs constant in N*m^2
	float Q1; // first electric charge value to be entered by user in coulombs
	float Q2; // second electric charge value to be entered by user in coulombs
	float R; // distance between charges entered by user in meters to be entered by the user in meters
	
	// Program Description
	printf( "This program calculates the Electric Field Strength with the equation E = k*Q1*Q2/(R*R) after prompting the user for inputs. \n" );
	
	// Prompt user for information and set variables
	printf( "Please enter the value of charge 1: " );
	scanf( "%f", &Q1 );
	
	printf( "Please enter the value of charge 2: " );
	scanf( "%f", &Q2 );
	
	printf( "Please enter the value of the distance between the charges: ");
	scanf( "%f", &R );
	
	//Calculate and display Electric Field Force
	F = k*Q1*Q2/(R*R);
	printf( "The Electric Field Force is equal to: %.2f Newtons. \n", F);
	
}

