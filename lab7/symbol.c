//symbol.c a program that generates shapes when certain keys and buttons are pressed
#include <stdio.h>
#include <unistd.h>
#include "gfx.h"
#include <math.h>

//Function Prototype
void drawpolygon(int side, int xcoord, int ycoord);
//Main
int main(){
	int wd = 600; //window width
	int ht = 500;	//window height
	int loop = 1, Xs, Ys;
	int s = 30; //side length(half)
	char c;
	
	gfx_open(wd, ht, "Symbols"); //Open window with title Symbols
	gfx_clear();
	
	while(loop){  
		gfx_flush();
		c = gfx_wait();//Wait for user input
		switch(c){
			case 1:
				gfx_color(0,0,255); //Set drawing color to blue
				Xs = gfx_xpos(); //Grab the X and Y coordinates of the mouse pointer when last key or button was pressed
				Ys = gfx_ypos();
				gfx_line(Xs-s,Ys-s,Xs-s,Ys+s); //Draw a square with side length 2s
				gfx_line(Xs-s,Ys+s,Xs+s,Ys+s);
				gfx_line(Xs+s,Ys+s,Xs+s,Ys-s);
				gfx_line(Xs+s,Ys-s,Xs-s,Ys-s);
				break;
			case 't':
				gfx_color(0,255,0); //green
				Xs = gfx_xpos();
				Ys = gfx_ypos();
				gfx_line(Xs,Ys-s,Xs-s,Ys+s); 
				gfx_line(Xs-s,Ys+s,Xs+s,Ys+s);
				gfx_line(Xs,Ys-s,Xs+s,Ys+s);
				break;
			case 'c':
				gfx_color(255,255,255); //white
				Xs = gfx_xpos();
				Ys = gfx_ypos();
				gfx_circle(Xs,Ys,s);
				break;
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				gfx_color(127,0,255); //purple
				drawpolygon(c-'0',Xs,Ys); //work through ASCII values to get desired number
				break;
			case 'q': //when q is pressed, breaks out of while loop and end
				loop = 0;
		}
	}
	return 0;
}

//Function Definition
void drawpolygon(int side, int xcoord, int ycoord){ //number of sides and the coordinates of where the polygon will be centered
	#define PI 3.141592
	int n;
	double r = 40, angle, x1, y1, x2, y2, a = 0;
	angle = (2*PI)/side; //angle in radians
	//draw first side of polygon
	x1 = gfx_xpos() + r; //starting at 3 o'clock position
	y1 = gfx_ypos();
	a = angle;
	x2 = gfx_xpos() + cos(a)*r; 
	y2 = gfx_ypos() - sin(a)*r;
	gfx_line(x1, y1, x2, y2);
	//repeat for number of sides
	for (n = 2; n<=side; n++){
		a = angle + a; //angle increment
		x1 = x2;
		y1 = y2;
		x2 = gfx_xpos() + cos(a)*r; 
		y2 = gfx_ypos() - sin(a)*r;
		gfx_line(x1, y1, x2 ,y2);
	}
}




