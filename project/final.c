//FINAL PROJECT
//Author: Aron Lam
//CSE20211 Fundamentals of Computing I

//My final project is called "Summer and Winter". It animates summer and winter with a relation to time, days, and year. There are 96 loops of time in a "day", 5 days to each season, and 10 days to a "year". The animation is also interactive, in that the user may add trees, ferns, and snowflakes at the cursor location with the 't', 'f', and 's' keys. The user may also press the '=' key to increase the speed of the animation. The ferns and trees grow over time, but only in the summer. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "gfx5.h"
#define PI 3.141592 //M_PI

int windowwd = 800;
int windowht = 600;

//Typedefinitions
typedef struct trees {
	int x;
	int y;
	double length;
	double angle;
} tree;

typedef struct ferns {
	int x;
	int y;
	double length;
	double angle;
} fern;

typedef struct snowflakes {
	int x;
	double y;
	double length;
} snowflake;

//Initialize arrays for interactive objects Max 50 of trees and ferns, 1000 of snowflakes
tree treearray[50];
fern fernarray[50];
snowflake snowflakearray[1000];

//FUNCTION PROTOTYPES

int daytime(int time);
void drawhorizon(int daytime, int horizon, int season);
void gradientorange(int horizon);
void drawsky(int daytime, int horizon, int season);
void drawstars(int daytime, int horizon, int season, int time);
void gradientblue();
void gradientgray();
void gradientblack();
void drawlandscape(int daytime, int horizon, int season);
void drawsun(int x, int y, double r, double a);
void drawmoon(int x, int y, double r, double a);
void initializetreearray();
void addtree(int x, int y, double r, double angle);
void drawtrees(int treecount, int season);
void incrementtreelength(int treecount);
void initializefernarray();
void addfern(int x, int y, double r, double angle);
void drawferns(int ferncount, int season);
void incrementfernlength(int ferncount);
void initializesnowflakearray(int snowflakecount);
void addsnowflake(int x, double y, double r);
void drawsnowflakes(int snowflakecount);
void incrementsnowflakey(int snowflakecount);
void draw(int daytime, int horizon, int season, int treecount, int ferncount, int snowflakecount, int x, int y, double r, double a, int time);
char *num2str(int n);
void writetext(int time, int day, int year);

//MAIN
int main(int argc, char *argv[]){
	int rotationcenterx = windowwd/2;
	int rotationcentery = windowht + 200;
	int rotationradius = rotationcentery - 50;
	int animate = 1, x, y, season = 0, day = 0, year = 0;
	int time = 0, dtime = 1; //incrementation of hours
	double angle = M_PI/2, da = 0.06545; //2PI/96 radians
	int treecount = 5; //initially 5 trees
	int ferncount = 6; //initially 6 ferns
	int snowflakecount = 420; //initiallty 
	char choice;
	gfx_open(windowwd, windowht, "Summer and Winter");
	initializetreearray();
	initializefernarray();
	initializesnowflakearray(snowflakecount);
	while(animate){
		gfx_clear();
		int horizon = windowht/2 + season*10;
		draw(daytime(time), horizon, season, treecount, ferncount, snowflakecount, rotationcenterx, rotationcentery, rotationradius, angle, time);
		writetext(time, day, year);
		gfx_flush();
		usleep(70000); 
		if(gfx_event_waiting()){ 
			choice = gfx_wait();
			switch(choice){
				 case 't': //add a growing tree
				 	x = gfx_xpos();
				 	y = gfx_ypos();
				 	treearray[treecount].x = gfx_xpos();
				 	treearray[treecount].y = gfx_ypos();
				 	treecount++;
				 	break;
				 case 'f': //add a growing fern
				 	x = gfx_xpos();
				 	y = gfx_ypos();
				 	fernarray[ferncount].x = gfx_xpos();
				 	fernarray[ferncount].y = gfx_ypos();
				 	ferncount++;
				 	break;
				 case 's': //add a falling snowflake
				 	x = gfx_xpos();
				 	y = gfx_ypos();
				 	snowflakearray[snowflakecount].x = gfx_xpos();
				 	snowflakearray[snowflakecount].y = gfx_ypos();
				 	snowflakecount++;
				 	break;
				 case '=':
					da = da + 0.13;
					dtime = dtime + 0.5;
				 	break;
				 case 'q': //quit
				 	break;
			}
		}
		angle = angle + da; //a starts at 0 and increments by 2PI/96 for each loop
		time = time + dtime; 
		if(time > 96){
			day++;
			time = 0;
		}
		if((day/5) % 2 == 0){
			season = 0; 
		}else if((day/5) % 2 == 1){
			season = 1;
		}
		if((day/10) % 2 == 1){
			year++;
		}
	}
	return 0;
}

//FUNCTION DEFINITIONS
int daytime(int time){
	int isday;
	if(time < 24 || time > 72){
		isday = 0; 
	}else{
		isday = 1;
	}
	return isday;
}

void drawhorizon(int daytime, int horizon, int season){
	if(daytime != 0 && season == 0){
		gradientorange(horizon);
	}
}
void gradientorange(int horizon){ //horizon in the summer
	double i, imax = 80;
	for(i = 0;i < imax; i++){
		gfx_color(255, 175 + i, 102 + i);
		gfx_line(0, horizon - 2 - i/1.5, windowwd, horizon - 2 - i/1.5);
	}
}

void drawsky(int daytime, int horizon, int season){
	if(daytime == 1 && season == 0){ //daytime summer
		gradientblue();
	}else if(daytime == 0 && season == 0){ //nighttime summer
		gfx_color(0, 0, 60);
		gfx_fill_rectangle(0, 0, windowwd, windowht - horizon);
	}else if(daytime == 1 && season == 1){ //daytime winter
		gradientgray();
	}else if(daytime == 0 && season == 1){ //nighttime winter
		gradientblack();
	}
}
void drawstars(int daytime, int horizon, int season, int time){
	if(daytime == 0){
		gfx_color(255,255,255);
		int i, stars = 15;
		for(i = 0;i < stars;i++){
			if(time % 2 == 0){
				gfx_point(i*63, 50);
				gfx_point(i*55, 160);
				gfx_point(i*69, 255);
				gfx_point(i*70, 100);
				gfx_point(i*63, 210);
				gfx_point(i*55, 285);
			}else{ //to make the twinkly effect
				gfx_point(i*63, 50);
				gfx_point(i*55, 160);
				gfx_point(i*69, 255);
				gfx_point(i*70, 100);
				gfx_point(i*63, 210);
				gfx_point(i*55, 285);
				gfx_point(i*63+1, 50);
				gfx_point(i*55+1, 160);
				gfx_point(i*69+1, 255);
				gfx_point(i*70+1, 100);
				gfx_point(i*63+1, 210);
				gfx_point(i*55+1, 285);
			}
		} 
	}
}

void gradientblue(){ //for summer days
	double i, imax = 250;
	for(i = 0;i < imax; i++){
		gfx_color(i, 125 + (i/2), 255);
		gfx_line(0, i, windowwd, i);
	}
}	
void gradientgray(){ //for winter days
	double i, imax = 300;
	for(i = 0;i < imax;i++){
		gfx_color(150 + (i/3), 150 + (i/3), 150 + (i/3));
		gfx_line(0, i, windowwd, i);
	}
}
void gradientblack(){
	double i, imax = 300;
	for(i = 0;i < imax;i++){
		gfx_color(25 + (i/3), 25 + (i/3), 25 + (i/3));
		gfx_line(0, i, windowwd, i);
	}
}
	
void drawlandscape(int daytime, int horizon, int season){
	if(daytime != 0){
		gfx_color(0, 153, 76);
		gfx_fill_rectangle(0, horizon - season*10 + 5, windowwd, windowht - horizon + season*10);
	}else{
		gfx_color(0, 75, 37);
		gfx_fill_rectangle(0, horizon - season*10 + 5, windowwd, windowht - horizon + season*10);
	}	
}

void drawsun(int x, int y, double r, double a){
	gfx_color(255,255, 0);
	double xc = x + (r*cos(a));
	double yc = y - (r*sin(a));
	gfx_fill_circle(xc, yc, 50);
}

void drawmoon(int x, int y, double r, double a){
	gfx_color(224, 224, 224);
	double xc = x + (r*cos(a));
	double yc = y - (r*sin(a));
	gfx_fill_circle(xc, yc, 30);
}

//Trees
void initializetreearray(){
	int i;
	for(i = 0;i < 50;i++){
		treearray[i].length = 12;
		treearray[i].angle = 2*M_PI/4;
	}
	treearray[0].x = 90;
	treearray[0].y = 550;
	treearray[1].x = 700;
	treearray[1].y = 500;
	treearray[2].x = 200;
	treearray[2].y = 400;
	treearray[3].x = 600;
	treearray[3].y = 400;
	treearray[4].x = 400;
	treearray[4].y = 530;
}
void addtree(int x, int y, double r, double angle){
	//Draw line
	gfx_line(x, y, x - r*cos(angle), y - r*sin(angle));
	double s = 0.65*r, deltangle = (2*PI)/10;
	//Base case
	if(s < 0.5) return;
	//Recursive calls
	addtree(x - r*cos(angle), y - r*sin(angle), s, (angle - deltangle));
	addtree(x - r*cos(angle), y - r*sin(angle), s, (angle + deltangle));
}

void drawtrees(int treecount, int season){
	if(season == 0)
		gfx_color(51,25,0); //brown
	if(season == 1)
		gfx_color(220,220,220); //white
	int i;
	for(i = 0;i < treecount; i++){
		addtree(treearray[i].x, treearray[i].y, treearray[i].length, treearray[i].angle);
	}
}

void incrementtreelength(int treecount){
	int i;
	for(i = 0;i < treecount; i++){
		treearray[i].length = treearray[i].length * 1.001;
	}
}

//Ferns
void initializefernarray(){
	int i;
	for(i = 0;i < 50;i++){
		fernarray[i].length = 10;
		fernarray[i].angle = 2*M_PI/4;
	}
	fernarray[0].x = 50;
	fernarray[0].y = 350;
	fernarray[1].x = 360;
	fernarray[1].y = 350;
	fernarray[2].x = 550;
	fernarray[2].y = 500;
	fernarray[3].x = 245;
	fernarray[3].y = 580;
	fernarray[4].x = 765;
	fernarray[4].y = 530;
	fernarray[5].x = 745;
	fernarray[5].y = 400;
}
void addfern(int x, int y, double r, double angle){
	//Draw line
	gfx_line(x, y, x - r*cos(angle), y - r*sin(angle));
	double s = 0.33*r, deltangle = (2*PI)/9;
	//Base case
	if(s < 0.5) return;
	//Recursive Calls
	int i;
	for(i = 1; i <= 4; i++){
		addfern(x - i*.25*r*cos(angle), y - i*.25*r*sin(angle), s,(angle - deltangle));
		addfern(x - i*.25*r*cos(angle), y - i*.25*r*sin(angle), s,(angle + deltangle));
	}
}

void drawferns(int ferncount, int season){
	if(season == 0) //if summer
		gfx_color(0,153,0); //green
	if(season == 1) //if winter
		gfx_color(192,192,192); //light gray
	int i;
	for(i = 0;i < ferncount; i++){
		addfern(fernarray[i].x, fernarray[i].y, fernarray[i].length, fernarray[i].angle);
	}
}

void incrementfernlength(int ferncount){
	int i;
	for(i = 0;i < ferncount; i++){
		fernarray[i].length = fernarray[i].length * 1.001;
	}
}

//Snowflakes
void initializesnowflakearray(int snowflakecount){
	int i, j, k;
	for(i = 0;i < 1000;i++){ // setlength for all flakes
		snowflakearray[i].length = 1;
	}
	//set multiple layers of snowflakes
	for(j = 0;j < 30;j++){
		snowflakearray[j].x = j*28 + 2;
		snowflakearray[j].y = 1; 
	}
	for(j = 30;j < 65;j++){
		snowflakearray[j].x = (j-30)*25 + 2;
		snowflakearray[j].y = -30; 
	}
	for(j = 65;j < 95;j++){
		snowflakearray[j].x = (j-65)*28 + 2;
		snowflakearray[j].y = -60; 
	}	
	for(j = 95;j < 130;j++){
		snowflakearray[j].x = (j-95)*25 + 2;
		snowflakearray[j].y = -90; 
	}
	for(j = 130;j < 160;j++){
		snowflakearray[j].x = (j-130)*28 + 2;
		snowflakearray[j].y = -120; 
	}
	for(j = 160;j < 195;j++){
		snowflakearray[j].x = (j-160)*25 + 2;
		snowflakearray[j].y = -150; 
	}
	for(j = 195;j < 225;j++){
		snowflakearray[j].x = (j-195)*28 + 2;
		snowflakearray[j].y = -180; 
	}
	for(j = 225;j < 260;j++){
		snowflakearray[j].x = (j-225)*25 + 2;
		snowflakearray[j].y = -210; 
	}
	for(j = 260;j < 290;j++){
		snowflakearray[j].x = (j-260)*28 + 2;
		snowflakearray[j].y = -240; 
	}
	for(j = 290;j < 325;j++){
		snowflakearray[j].x = (j-290)*25 + 2;
		snowflakearray[j].y = -270; 
	}
	for(j = 325;j < 355;j++){
		snowflakearray[j].x = (j-325)*28 + 2;
		snowflakearray[j].y = -300; 
	}
	for(j = 355;j < 390;j++){
		snowflakearray[j].x = (j-355)*25 + 2;
		snowflakearray[j].y = -330; 
	}
	for(j = 390;j < 420;j++){
		snowflakearray[j].x = (j-390)*28 + 2;
		snowflakearray[j].y = -360; 
	}
}
void addsnowflake(int x, double y, double r){
	int i;
	double s = 0.33*r, angle = (2*PI)/5;
	//Base case
	if(s < 0.1) return;
	//Draw lines
	for(i = 0; i <= 4; i++)
		gfx_line(x, y, x + r*cos(i*angle), y - r*sin(i*angle));
	//Recursive calls
	for(i = 0;i <= 4; i++)
		addsnowflake(x + r*cos(i*angle), y - r*sin(i*angle), s);
}

void drawsnowflakes(int snowflakecount){
	int i;
	for(i = 0;i < snowflakecount; i++){
		addsnowflake(snowflakearray[i].x, snowflakearray[i].y, snowflakearray[i].length);
	}
}

void incrementsnowflakey(int snowflakecount){
	int i;
	for(i = 0;i < snowflakecount; i++){
		snowflakearray[i].y += 0.4;
	}
}

void draw(int daytime, int horizon, int season, int treecount, int ferncount, int snowflakecount, int x, int y, double r, double a, int time){
	drawhorizon(daytime, horizon, season);
	drawsky(daytime, horizon, season);
	drawstars(daytime, horizon, season, time);
	drawlandscape(daytime, horizon, season);
	drawtrees(treecount, season);
	drawferns(ferncount, season);
	if(season == 0){ // trees only grow in summer/spring
	incrementtreelength(treecount);
	incrementfernlength(ferncount);
	}
	if(season == 1){ //if winter, snow
		drawsnowflakes(snowflakecount);
		incrementsnowflakey(snowflakecount);
	}
	drawsun(x, y, -r, a);
	drawmoon(x, y, r, a);
}

char *num2str(int n){
	static char a[10], *p = a;
	snprintf(p, 10, "%d", n);
	return p;
}

void writetext(int time, int day, int year){
	gfx_color(255,255,255);
	gfx_text(711, 545, "Time:");
	gfx_text(750, 545, num2str(time));
	gfx_text(711, 560, "Day:");
	gfx_text(750, 560, num2str(day));
	gfx_text(711, 575, "Year:");
	gfx_text(750, 575, num2str(year));
}


