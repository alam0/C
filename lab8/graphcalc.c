//Lab 8 Part 1
//graphcalc.c a program that draws a detailed graph of the Taylor-series expansion of sin(x), where the user will control how many terms are being used in the graph.
//Author: Aron Lam
//Written with assistance from Mr. Pennycuff

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "gfx3.h"

//Function Prototypes
char *num2str(int n);
void drawAxes(int wd, int ht, int ticks, int tickseparation);
double calcTaylorValue(double x, int term);
double coordConvertx(int wd, double x);
double coordConverty(int ht, double y);
void plotTaylorFunc(int wd, int ht, int term);

//Main
int main(){
	int wd = 700;
	int ht = 700;
	int loop = 1;
	char c;
	int ticks = 10;
	int tickseparation = 30;
	int term = 1;
	
	gfx_open(wd, ht, "Graph of Taylor Expansion for Sin");
	while(loop){
		gfx_clear();
		gfx_color(255,255,255);
		drawAxes(wd, ht, ticks, tickseparation);
		gfx_color(0,102,204);
		plotTaylorFunc(wd, ht, term);
		gfx_flush();
		printf("The number of terms currently used in the Taylor Approximation is: %d.\n", term);
		c = gfx_wait(); //wait for input
		switch(c){
			case '=':
				term++;
				break;
			case '-':
				term--;
				break;
			case 'q':
				break;
		}
	}
}

//Function Definitions
char *num2str(int n){
	static char a[10], *p = a;
	snprintf(p, 10, "%d", n);
	return p;
}

void drawAxes(int wd, int ht, int ticks, int tickseparation){
	gfx_line(wd/2, 0, wd/2, ht);
	gfx_line(0, ht/2, wd, ht/2);
	int i, l = tickseparation;
	for(i = -ticks;i <= ticks; i++){
		//y-axis
		gfx_line(wd/2, (ht/2 - l*i), (wd/2 + 10), (ht/2 - l*i)); //ticks have length of 10 pixels
		gfx_text((wd/2 + 5), (ht/2 - l*i), num2str(i));
		gfx_text((wd/2 + 5), 15, "Y");
		//x-axis
		gfx_line((wd/2 + l*i), ht/2, (wd/2 + l*i), (ht/2 - 10));
		gfx_text((wd/2 + l*i + 5), (ht/2 - 5), num2str(i));
		gfx_text((wd - 15), (ht/2 - 5), "X");
	}
}

double calcTaylorValue(double x, int term){
	double y = 0, b;
	int a, i, j; //j and k are for incrementation, a is used to adapt the number of a term to its respective odd number
	a = 2*term - 1; //taylor series works with odd numbers (2nd term uses x^3/3!, 3rd term uses x^5/5! and so on)
	
	for(i = a;i > 0;i-=2){ //loops from greatest a value to 1 by subtracting 2 each time
		b = 1;
		for(j = i;j > 0;j--){
			b = b*(x/j);
		}
		if(term%2 == 0) //terms alternate addition and subtraction
			y = y - b;
		else
			y = y + b;
		term--; //to make sure each term is accounted for
	}
	return y;
}

double coordConvertx(int wd, double x){ //converts x coordinate from cartesian to pixel coordinate
	double nx;
	nx = wd/2 + 30*x;
	return nx;
}

double coordConverty(int ht, double y){ //converts y coordinate from cartesian to pixel coordinate
	double ny;
	ny = ht/2 - 30*y;
	return ny;
}

void plotTaylorFunc(int wd, int ht, int term){
	double x, y, z;
	for(x=-10;x < 10;x+=0.01){ //from -10 to 10 
		z = coordConvertx(wd, x); //z is the variable x value in pixel coordinate
		y = calcTaylorValue(x, term); //calculate y coordinate in cartersian
		y = coordConverty(ht, y); //convert y from cartesian to pixel coordinate
		gfx_point(z,y);
	}
}

