//Polar Coordinates and Quadrants from Cartesian Coordinates
#include <stdio.h>
#include <math.h>

//Prototypes
float getRadius(int X, int Y);
float getTheta(int X, int Y);
int getQuadrant(int X, int Y);
//Main
int main() {
	int X, Y, Quadrant;
	float Radius, Theta;
	//Prompts
	printf("Please enter the x coordinate for a point on the cartesian plane: ");
	scanf("%d", &X);
	printf("Please enter the y coordinate for the same point: ");
	scanf("%d", &Y);
	//Use of Functions
	Radius = getRadius(X, Y);
	Theta = getTheta(X, Y);
	Quadrant = getQuadrant(X, Y);
	printf("In polar coordinates, the radius is %f and theta is %f radians.", Radius, Theta);
	if( Quadrant == 5 ) {
		printf("The point is located on the Y axis.");
	} else if( Quadrant == 6) {
		printf("The point is located on the X axis.");
	} else if(Quadrant == 0) {
		printf("The point is located at the origin.");
	} else {
		printf("The point is located in quadrant %d.", Quadrant);
	}
	return 0;
}

//getRadius Function Definition
float getRadius(int X, int Y){
	float Radius;
	Radius = sqrt( pow(X, 2) + pow(Y, 2));
	return Radius;
}

//getTheta Function Definition
float getTheta(int X, int Y){
	float Theta;
	if( (Y > 0 ||  Y < 0)&& X != 0 ) {
		Theta = atan(Y/X);
	} else if( X > 0 && Y == 0) {
		Theta = 0;
	} else if (X < 0 && Y == 0) {
		Theta = 3.14159265;
	} else if (X == 0 && Y == 0) {
		Theta = 0;
	} else if( X == 0 && Y > 0) {
		Theta = 1.57079633;
	} else { 
		Theta = (1.5 * 3.14159265);
	}
return Theta;
}

//getQuadrant Function Definition
int getQuadrant(int X, int Y){
	int Quadrant;
	if( X > 0 && Y > 0){
		Quadrant = 1;
	} else if( X < 0 && Y > 0) {
		Quadrant = 2;
	} else if( X < 0 && Y < 0) {
		Quadrant = 3;
	} else if( X > 0 && Y < 0) {
		Quadrant = 4;
	} else if( X == 0 && Y != 0) {
		Quadrant = 5;
	} else if( X != 0 && Y == 0) {
		Quadrant = 6;
	} else {
		Quadrant = 0;
	}
	return Quadrant;
}
	
	
