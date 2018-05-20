//carnival.c a program with chained circular and linear axes of motion
//Author: Aron Lam

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "gfx3.h"
#define PI 3.141592

//Function Prototypes
void drawbase();
void getCoordinates(int lines, double x1, double y1, double x[], double y[], double angle, double r, double a);
void drawBlueLines(int lines, double x2, double y2, double x[], double y[]);
void drawSpinningCars(int lines, double b, double angle, double x[], double y[], int s);
void drawpolygon(int side, double xcoord, double ycoord);

//Main
int main(){
	int wd = 1000, ht = 700;
	int loop = 1, lines = 4; //number of blue lines rotating
	double x1 = 500, y1 = 350; //intial center for blue lines
	double x2 = 500, y2 = 350; //changing center
	double x[lines - 1], y[lines - 1]; //arrays for coordinates to draw blue lines
	double r = 200; //angle for blue lines and distance of how far they reach
	double da = 0.1, a = 0; //change in angle for blue lines 
	double d2 = 20; //speed of movement along red line
	double db = 0.5, b = 0; //change in angle for green/yellow spinning lines
	char c;
	double angle = (2*PI)/lines; //angle for rotation
	int s = 3; //s-sided polygon car
	
	gfx_open(wd, ht, "Carnival Ride!");
	while(loop){
		gfx_clear();
		drawbase();
		getCoordinates(lines, x1, y1, x, y, angle, r, a);
		a = a + da; //increment a, for changing the angles of the blue lines
		b = b + db; //increment b, for changing the angles of the green/yellow lines
		x2 = x2 + d2; //change the center of rotation for the blue lines along red line
		if(x2 < 100 || x2 > 900) //to make sure the center of rotation remains on red line
			d2 = -d2;
		drawBlueLines(lines, x2, y2, x, y);
		drawSpinningCars(lines, b, angle, x, y, s); //2 lines spin on the screen, and other 2 spin into it
		gfx_flush();
		usleep(100000);
		if(gfx_event_waiting()){ 
			c = gfx_wait();
			switch(c){
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					s = (c - '0');
				case 'q':
					break;
			}
		}
	}
	return 0;
}

//Function Definitions
void drawbase(){
		gfx_color(255,255,255);
		gfx_line(250, 650, 750, 650); //bottom of base
		gfx_line(280, 630, 730, 630); //top of base
		gfx_line(250, 650, 280, 630);	//left of base
		gfx_line(730, 630, 750, 650); //right of base
		gfx_line(250, 650, 500, 250); //left of triangle
		gfx_line(500, 250, 750, 650); //right of triangle
		gfx_line(300, 630, 500, 350); //lower left of triangle 
		gfx_line(500, 350, 700, 630); //lower right of triangle
		gfx_line(430, 450, 570, 450); //middle arch
		gfx_line(395, 500, 605, 500);	//middle arch
		gfx_line(250, 650, 80, 350); //left lower arm
		gfx_line(750, 650, 920, 350);	//right lower arm
		gfx_line(80, 350, 250, 50); //left upper arm
		gfx_line(920, 350, 750, 50);	//right upper arm
		gfx_line(250, 50, 750, 50); //top
		gfx_color(255,0,0); //red
		gfx_line(80, 350, 920, 350); //red line that blue rotating line will move back and forth across
}		

void getCoordinates(int lines, double x1, double y1, double x[], double y[], double angle, double r, double a){
	int i;
	for(i = 0; i <= (lines - 1); i++){
		x[i] = x1 + (r*cos(i*angle + a));
		y[i] = y1 - (r*sin(i*angle + a));
	}
}

void drawBlueLines(int lines, double x2, double y2, double x[], double y[]){
	int j;
	for(j = 0; j <= (lines-1); j++){
		gfx_color(0,102,204);
		gfx_line(x2, y2, x[j], y[j]);
	}
}

void drawSpinningCars(int lines, double b, double angle, double x[], double y[], int s){ //alternation of axes of motion for each "car"
	int j;
	for(j = 0; j <= (lines - 1); j++){
		if(j%2 == 0){ //these lines will spin "into and out of" the screen
			gfx_color(127,0,255); //purple
			gfx_line(x[j],y[j],x[j]+(60*cos(angle + b)),y[j]+(60*sin(j*angle + b)));
			drawpolygon(s, x[j]+(60*cos(angle + b)),y[j]+(60*sin(j*angle + b)));
			gfx_color(255,128,0); //orange
			gfx_line(x[j],y[j],x[j]-(60*cos(angle + b)),y[j]-(60*sin(j*angle + b)));
			drawpolygon(s, x[j]-(60*cos(angle + b)),y[j]-(60*sin(j*angle + b)));
		}
		else{ //lines in between will spin on the plane of the screen
			gfx_color(0,255,0);//green
			gfx_line(x[j],y[j],x[j]+(60*cos(j*angle + b)),y[j]+(60*sin(j*angle + b)));
			drawpolygon(s, x[j]+(60*cos(j*angle + b)),y[j]+(60*sin(j*angle + b)));
			gfx_color(255,255,0); //yellow
			gfx_line(x[j],y[j],x[j]-(60*cos(j*angle + b)),y[j]-(60*sin(j*angle + b)));
			drawpolygon(s, x[j]-(60*cos(j*angle + b)),y[j]-(60*sin(j*angle + b)));
		}
	}
}

void drawpolygon(int side, double xcoord, double ycoord){ //number of sides and the coordinates of where the polygon will be centered
	#define PI 3.141592
	int n;
	double r = 20, angle, x1, y1, x2, y2, a = 0;
	angle = (2*PI)/side; //angle in radians
	//draw first side of polygon
	x1 = xcoord + r; //starting at 3 o'clock position
	y1 = ycoord;
	a = angle;
	x2 = xcoord + cos(a)*r; 
	y2 = ycoord - sin(a)*r;
	gfx_line(x1, y1, x2, y2);
	//repeat for number of sides
	for (n = 2; n<=side; n++){
		a = angle + a; //angle increment
		x1 = x2;
		y1 = y2;
		x2 = xcoord + cos(a)*r; 
		y2 = ycoord - sin(a)*r;
		gfx_line(x1, y1, x2 ,y2);
	}
}

	
		
		
