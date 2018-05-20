//bounce.c a program that simulates a ball bouncing around the screen
#include <stdio.h>
#include <unistd.h>
#include "gfx.h"
#include <stdlib.h>
#include <math.h>

int main(){
	int wd = 600; //width of window
	int ht = 600; 
	double xc, yc; //x-coord and y-coord
	int vx, vy, loop = 1;
	double dx, dy; //delta-x and delta-y
	int r = 25; //radius of circle
	double dt = 0.05; //deltat
	char c;
	
	gfx_open(wd, ht, "Bounce");
	gfx_clear();
	gfx_color(255,255,255); 
	xc = wd/2;
	yc = ht/2;
	srand(time(NULL));
	vx = rand() % 100 -50; //random number from -50 to 50
	vy = rand() % 100 - 50;
	dx = vx * dt;
	dy = vy * dt;
	
	while(loop){
		xc = xc + dx;
		yc = yc + dy;
		if(xc > (wd - r)){ //collision checking right border
			xc = (wd - r);
			dx = -dx;
		}
		if(xc < r){ //left border
			xc = r;
			dx = -dx;
		}
		if(yc > (ht - r)){ //bottom border
			yc = (ht -r);
			dy = -dy;
		}
		if(yc < r){ //top border
			yc = r;
			dy = -dy;
		}
		gfx_clear();
		gfx_circle(xc, yc, r); 
		gfx_flush();
		usleep(1200); //pause for 1.2 milliseconds
		if(gfx_event_waiting()){ 
			c = gfx_wait(); 
			if(c == 1){ //left mouse click = new ball at mouse position with new random velocity
				xc = gfx_xpos();
				yc = gfx_ypos();
				srand(time(NULL));
				vx = rand() % 100 - 50;
				vy = rand() % 100 - 50;
				dx = vx * dt;
				dy = vy * dt;
			}
			if(c == 'q') 
				break;
		}
	}
	return 0;
}
