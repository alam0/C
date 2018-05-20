//mysayings.c
//CSE-20211
//Lab6
//Author: Aron Lam
//Description: This program will store and manage many of your favorite sayings.

#include <stdio.h>
#include<ctype.h>
#include<string.h>

//Function Prototype
void addSaying(char a[][80], int row, int size);
void wordSearch(char a[][80], int row);

//Main
int main(){
	//Prompt user and initialize file for reading 
	FILE *fp, *nfp;
	char sayings[100][80], *p, sfile[20], nfile[20];
	printf("Please enter the name of the text file you want to manage: ");
	scanf("%s", sfile);
	fp = fopen(sfile, "r");
	if(!fp){ //checks if file exists
		printf("error in opening file %s\n", sfile);
		return 1;
	}
	
	//Put strings of specified file into sayings 2x2 array
	int i = 0,j = 0; //i will be the number of rows containing strings in the array
	while (!feof(fp)){
		p = sayings[i];
		fgets(p, 78, fp);
		i++;
	}
	i = i-2; //to account for the fact that arrays start at 0 and the extra iteration for \n character
	
	//Print Options until user decides to quit
	int choice = 999, k, junk, l;
	while(choice!= 0){
		printf("\n"); //Makes viewing what is printed easier
		printf("What would you like to do with your sayings? \n1.Display all sayings currently in the database \n2.Enter a new saying into the database \n3.List sayings that contain a given word (substring) entered by the user \n4.Save all sayings in a new text file \n0.Quit the program \nEnter the number of your choice: ");
		scanf("%d",&choice);
		scanf("%c", &junk); //To take care of the extra \n left by the previous scanf
		switch(choice){
			case 1:
				for(k = 0; k < i; k++)
					printf("%d. %s", (k+1), sayings[k]);
				break;
			case 2:
				addSaying(sayings, i, 78); //i is the number of rows with strings and 78 is the max number of characters the new string may have
				i++;
				break;
			case 3:
				wordSearch(sayings, i);
				break;
			case 4:
				printf("What name would you like for your new text file? ");
				scanf("%s", nfile);
				nfp = fopen(nfile, "w");
				for(l = 0; l < 100; l++)
					fprintf(nfp,"%s", sayings[l]);
				break;
		}
	}
	return 0;
}
 
//Function Definitions
void addSaying(char a[][80], int row, int size){ //these variables are used in the fgets operation
	printf("Please enter the saying you would like to add? ");
	fgets(a[row], size, stdin);
}

void wordSearch(char a[][80], int row){
	char word[30], *s; 
	int it;
	printf("What word would you like to use? ");
	scanf("%s", word); //&word is not needed because word is an array, and its address is the first character in it
	for(it = 0;it < row; it++){ //Search through each string
		char *nullornot;
		nullornot = strstr(a[it], word);
		if(nullornot != 0){ //if it does not show that it is not present, print the string from a[] we are working with through *nullornot
			printf("%d. %s", (it+1), a[it]);
		}
	}
}


	
	
