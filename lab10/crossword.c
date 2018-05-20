//Crossword Anagram
//Author: Aron Lam
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int maxwords = 20;
int maxchar = 15;
int boardsize = 15;

//Function Prototypes
void initializeBoard(char board[maxwords][maxchar]);
void printBoard(char board[boardsize][boardsize]);
void printWords(char words[maxwords][maxchar]);
int promptUserForInput(char words[maxwords][maxchar]);
void sortWords(char words[maxwords][maxchar], int numwords);
void makeUppercase(char words[maxwords][maxchar]);
void placeFirstWord(char board[boardsize][boardsize], char FirstWord[]);
int can_place_word(char word[maxwords][maxchar],char board[boardsize][boardsize], int row, int col);
int place_word(char word[], char board[][boardsize]);
void print_solution_board(char board[][boardsize]);
void print_puzzle_board(char board[][boardsize]);
void print_clues(char clues[][boardsize]);

//Main
int main(void){
	char words[maxwords][maxchar];
	char board[boardsize][boardsize];
	char clues[boardsize][boardsize];
	//Initialize
	printf("Anangram Crossword Puzzle Generator\n------------------------------------\n");
	initializeBoard(board);
	int numwords = promptUserForInput(words);
	printWords(words);
	//Sort Words
	sortWords(words, numwords);
	printWords(words);
	makeUppercase(words);
	printWords(words);
	placeFirstWord(board, words[0]);
	printBoard(board);
	return 0;
}

//Function Definitions
void initializeBoard(char board[boardsize][boardsize]){
	int i, j;
	for(i = 0; i < boardsize; i++){
		for(j = 0; j < boardsize; j++){
			board[i][j] = '#';
		}
	}
}
void printBoard(char board[boardsize][boardsize]){
	int i, j;
	for(i = 0; i < boardsize; i++){
		for(j = 0; j < boardsize; j++){
		printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
void printWords(char words[maxwords][maxchar]){
  printf("************PRINTING WORDS CHAR ARRAY********\n");
  int i,j;
  for(i=0; i<maxwords; i++){
    printf("i=%i: ", i);
    for(j=0; j<maxchar; j++){
      char *ch = &words[i][j];
			if(ch=='\0'){
			  printf("null char reached.\n");
			  break;
			}
			if(*ch=='.'){
			  printf(". reached.\n");
			  return;
			}
      printf("%c", *ch);
    }
    printf("\n");
  }
}

int promptUserForInput(char words[maxwords][maxchar]){
	int i = 0, numwords = 0;
	printf("Please enter a list of words:\n");
	while(numwords<maxwords){
		scanf("%s", words[numwords]);
		for(i=0; i<strlen(words[numwords]); i++){
		  char c = words[numwords][i];
		  if((c<'A' || c>'Z')&&(c<'a'  || c>'z')&&(c!='.'))
		    printf("invalid char\n");
		}
		if(strcmp(words[numwords], ".") == 0){
			break;
		}
		numwords++;
	}
	printf("\n");
	/*for(r = 0; r < i; r++){
		for(c = 0; c < maxchar; c++){
			char *ch = &words[r][c];
			if(ch=='\0') break;
			printf("%c", ch);
		}
		printf("\n");
	}*/
	return numwords;
}

void sortWords(char words[maxwords][maxchar], int numwords){
	int i, j;
	char string[maxchar];
	for(i = 1;i < numwords; ++i){
		for(j = 0;j < numwords; ++j){
			if(strlen(words[j]) < strlen(words[j+1])){
				strcpy(string, words[j]);
				strcpy(words[j], words[j+1]);
				strcpy(words[j+1], string);
			}
		}
	}
}

void makeUppercase(char words[maxwords][maxchar]){
	int i, j;
	for(i = 0;i < maxwords;i++){
		for(j = 0;j < maxchar;j++){
			char *c = &words[i][j];
			if(*c >= 'a' && *c <='z')
				*c = toupper(*c);
		}
	}
}

void placeFirstWord(char board[boardsize][boardsize], char FirstWord[]){
	int i;
	int xpos = boardsize/2 - strlen(FirstWord)/2;
	int ypos = 8;
		for(i = 0;i < strlen(FirstWord);i++)
			board[ypos][xpos + i] = FirstWord[i];
}

/*int can_place_word(char words[maxwords][maxchar],char board[boardsize][boardsize], int row, int col){
return 0;
}*/ 

/*int place_word(char words[maxwords][maxchar], char board[][boardsize]){
	int row, col, boardsize = 15;
	//Loop through board to see if word can be placed
	for(row = 0; row < boardsize; row++){
		for(col = 0; col < boardsize; col++){
			if(can_place_word(words[], board[], row, col){
				return 0;
			}
		}
	}
	return 1;
}*/

void print_solution_board(char board[][boardsize]){
}

void print_puzzle_board(char board[][boardsize]){
}

void print_clues(char clues[][boardsize]){
}

