//animate.c
//Author: Aron Lam 
//This is program that creates a ferris wheel that speeds up (pressing the up arrow key) and slows down (pressing the down arrow key) with interchangable polygon cars. Pressing any of the numbers from 3 to 9 when the program is running will change the cars to a polygon of that many sides.
#include <stdio.h>
#include <unistd.h>
#include "gfx.h"
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

//Function Prototype
void drawpolygon(int side, double xcoord, double ycoord);

//Main
int main(){
	int wd = 1000;
	int ht = 700;
	int loop = 1, i, j, k, l; //loop variable and iteration variables
	double angle;
	double x[5];
	double y[5];
	double x1 = 500, y1 = 300; //coordinates of the center of the wheel
	double r = 250; //radius of wheel
	double da = 0.05, a = 0;
	char c;
	int s = 3; //s-sided polygon car
	
	angle = (2*PI)/6;
	for(i = 0; i <= 5; i++){
		x[i] = x1 + (r*cos(i*angle));
		y[i] = y1 - (r*sin(i*angle));
	}
		
	gfx_open(wd, ht,"A Ferris Wheel");
	while(loop){
		for(i = 0; i <= 5; i++){
			x[i] = x1 + (r*cos(i*angle + a));
			y[i] = y1 - (r*sin(i*angle + a));
		}
		a = a + da;
		gfx_clear();
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
		for(j = 0; j <= 5; j++){
			gfx_color(200,0,0);
			drawpolygon(s, x[j], y[j]);
		}
		for(j = 0; j <= 5; j++){
			gfx_color(0,102,204);
			gfx_line(x1, y1, x[j], y[j]);
		}
		gfx_circle(500, 300, 250); //big wheel
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
					s = (c - '0'); //change number of sides of polygon cars
			} //should have put these last three in the switch/case structure
			if(c == 'R') //speed up if up arrow key is pressed
				da = da + 0.002;
			if(c == 'T') //slow down if down arrow key is pressed
				da = da - 0.002;
			if(c == 'q') //quit if q is pressed
				break;
		}
	}
	return 0;
}
//Function Definition
void drawpolygon(int side, double xcoord, double ycoord){ //number of sides and the coordinates of where the polygon will be centered
	#define PI 3.141592
	int n;
	double r = 50, angle, x1, y1, x2, y2, a = 0;
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

