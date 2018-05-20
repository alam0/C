#include <stdio.h>
#include <unistd.h>
#include "gfx.h"
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

int main(){
	int wd = 1000;
	int ht = 800;
	int loop = 1, i, j, k, l; //loop variable and iteration variables
	double angle;
	double x[5];
	double y[5];
	double x1 = 500, y1 = 400; //coordinates of the center of the wheel
	double r = 300; //radius of wheel
	double da = 0.05, a = 0;
	char c;
	
	angle = (2*PI)/6;
	for(i = 0; i <= 5; i++){
		x[i] = x1 + (r*cos(i*angle));
		y[i] = y1 - (r*sin(i*angle));
	}
	for(k = 0; k <= 5; k++){
		//printf("%lf ", x[k]);
	}
		//printf("\n");

	for(l = 0; l <= 5; l++){
		//printf("%lf ", y[l]);
	}
		//printf("\n");
		
	gfx_open(wd, ht,"A Ferris Wheel");
	while(loop){
		for(i = 0; i <= 5; i++){
			x[i] = x1 + (r*cos(i*angle + a));
			y[i] = y1 - (r*sin(i*angle + a));
		}
		a = a + da;
		gfx_clear();
		gfx_color(255,255,255); //color of the base
		gfx_line(200, 800, 800, 800); //bottom of base
		gfx_line(220, 780, 780, 780); //top of base
		gfx_line(200, 800, 220, 780);	//left of base
		gfx_line(780, 780, 800, 800); //right of base
		gfx_line(260, 780, 500, 350); //left of triangle
		gfx_line(500, 350, 740, 780); //right of triangle
		gfx_line(300, 780, 500, 450); //lower left of triangle 
		gfx_line(500, 450, 700, 780); //lower right of triangle
		gfx_line(440, 550, 560, 550); //middle arch
		gfx_line(410, 600, 590, 600);	//middle arch
		for(j = 0; j <= 5; j++){
			gfx_color(0,102,204); //color of the wheel and cars
			gfx_line(x1, y1, x[j],y[j]);
			gfx_circle(x[j],y[j],50);
		}
		gfx_circle(500, 400, 300); //big wheel
		gfx_flush();
		usleep(100000);
		if(gfx_event_waiting()){ 
			c = gfx_wait(); 
			if(c == 'R')
				da = da + 0.005;
			if(c == 'T')
				da = da - 0.005;
			if(c == 'q') 
				break;
		}
	}
	return 0;
}

