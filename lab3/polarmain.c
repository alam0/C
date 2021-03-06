//PolarMain.c
#include <stdio.h>
#include <math.h>
#include"polarfn.h"
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
