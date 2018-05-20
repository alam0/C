//PolarFunctionDefinitions
#include<math.h>
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
