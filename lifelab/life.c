//life.c (Conway's Game of Life)
//Initially, program will run in interactive mode; if a data file is present after the executable; (sequence of commands followed by p), program will use that file as its scene

//SIMPLE RULES
//Rule 1: A dead cell with 3 live neighbors becomes live
//Rule 2: Only a live cell with 2 or 3 live neighbors survives
//All others die

//Author: Aron Lam
//CSE20211 FundCompI (C)
//Thanks TA's for their help

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int boardsize = 42; //to account for edges

//FUNCTION PROTOTYPES
void initializeboard(char board[][boardsize]); //initializes blank board
void printInteractive(); //prints options for user
void runGame(FILE *f, char board[][boardsize], char tempboard[][boardsize]); //Main function that run game, in interactive mode or with file
int isalive(int x, int y, char board[][boardsize]); //checks for life of cell
void addlivecell(int x, int y, char board[][boardsize]); 
void killcell(int x, int y, char board[][boardsize]); 
void checkrules(int x, int y, char board[][boardsize], char tboard[][boardsize]); //checks a cell with Rules
int neighbors(int x, int y, char board[][boardsize]); //checks for live neighbors of a certain cell
void next(char board[][boardsize], char tboard[][boardsize]); //rules checkrules on tempboard, and then copies tempboard to currentboard
void copy(char board[][boardsize], char tboard[][boardsize]); //copy 2nd board to 1st
void printcurrentboard(char board[][boardsize]);


//MAIN
int main(int argc, char *argv[]){
	char currentboard[boardsize][boardsize]; //stores current state of the world
	char tempboard[boardsize][boardsize]; //fills in future state of the world
	if(argc == 1){ //Run in interactive mode
		runGame(stdin, currentboard, tempboard); 
	}else if(argc == 2){//If data file is present, use it
		FILE *fp;
		fp = fopen(argv[1], "r"); //opens 2nd element of argv vector
		if(!fp){ //checks if file exists
			printf("error in opening file");
			return 1;
		}
		runGame(fp, currentboard, tempboard);
	}	
	return 0;
}

//FUNCTION DEFINITIONS
void initializeboard(char board[][boardsize]){ //create blank board
	int i, j;
	for(i = 0;i < boardsize;i++)
		for(j = 0;j < boardsize;j++)
			board[i][j] = ' ';
}

void printInteractive(){ //options
	printf("Interactive mode: Choose one of the following:\n");
	printf("a: enter coordinates for where to add a new live cell\n");
	printf("r: enter coordinates for where a cell should be removed\n");
	printf("n: to advance simulation to the next iteration by applying the rules of the game\n");
	printf("p: to play the game continuously(forever, can press ctrl-C to stop)\n");
	printf("q: to quit\n");
}

void runGame(FILE *f, char board[][boardsize], char tboard[][boardsize]){
	initializeboard(board);
	initializeboard(tboard);
	if(f == stdin)
		printInteractive();
	char choice;
	int x, y;
	while(choice != 'q'){ //if q, quit
		int loop = 1;
		if(f == stdin){ //prints only if in interactive mode
			printInteractive();
		}
		fscanf(f, "%c", &choice); //fscanf(stdin, "%d") == scanf("%d")
		switch(choice){
			case 'a': //add live cell at specific coordinate
				fscanf(f, "%d %d", &x, &y); // scans in coordinates after choice
				addlivecell(x + 1, y + 1, tboard);
				copy(board, tboard);
				printcurrentboard(board);
				break;
			case 'r': //kill cell at specific coordinate
				fscanf(f, "%d %d", &x, &y);
				killcell(x + 1, y + 1, tboard);
				copy(board, tboard);
				printcurrentboard(board);
				break;
			case 'n': //one step
				next(board, tboard);	//look at currentboard and apply changes to tempboard
				copy(board, tboard);	//copy tempboard to currentboard
				printcurrentboard(board); //print currentboard
				break;
			case 'p': //go forever
				while(loop){ //no breaks
					next(board, tboard);
					copy(board, tboard);
					printcurrentboard(board);
				}
		}
	}
}
int isalive(int x, int y, char board[][boardsize]){ //checks if cell is dead or alive
	if(board[x][y] == 'X'){
		return 1;
	}else{
		return 0;
	}
}

void addlivecell(int x, int y, char board[][boardsize]){
		board[x][y] = 'X';
}

void killcell(int x, int y, char board[][boardsize]){
	if(isalive(x, y, board))
		board[x][y] = ' ';
}

int neighbors(int x, int y, char board[][boardsize]){ //checks life of 8 cells around current cell
	int liveneighbors; //sum of life surrounding neighbors
	liveneighbors = isalive(x - 1, y - 1, board) + isalive(x, y - 1, board) + isalive(x + 1, y - 1, board) + isalive(x - 1, y, board) + isalive(x + 1, y, board) + isalive(x - 1, y + 1, board) + isalive(x, y + 1, board) + isalive(x + 1, y + 1, board);
	return liveneighbors;
}

void checkrules(int x, int y, char board[][boardsize], char tboard[][boardsize]){ //looks at cboard and changes tboard
	if(isalive(x, y, board)){ //Rule 2: Only a live cell with 2 or 3 live neighbors survives
		if(neighbors(x, y, board) < 2 || neighbors(x, y, board) > 3){
			tboard[x][y] = ' '; //all else dies
		}
	}else if(isalive(x, y, board) != 1){ //Rule 1: A dead cell with 3 live neighbors becomes live
		if(neighbors(x, y, board) == 3){
			tboard[x][y] = 'X';
		}
	}
}

void next(char board[][boardsize], char tboard[][boardsize]){ //run checkrules on board and changes tboard
	int i, j;
	for(i = 1;i < boardsize - 1;i++){
		for(j = 1;j < boardsize - 1;j++){
			checkrules(i, j, board, tboard);
		}
	}
}

void copy(char board[][boardsize], char tboard[][boardsize]){ //copy tboard to board
	int i, j;
	for(i = 1;i < boardsize - 1;i++){
		for(j = 1;j < boardsize - 1;j++){
			board[i][j] = tboard[i][j];
		}
	}
}

void printcurrentboard(char board[][boardsize]){
	int i, j, b;
	system("clear");
	for(i = 1;i < (boardsize - 1);i++){
		for(j = 1;j < (boardsize - 1);j++){
			printf("%c", board[i][j]);	
		}
		printf("\n");
	}
	usleep(50000);
}

