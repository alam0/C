//ndfootball.c
#include <stdio.h>
#include <math.h>
#include "nd_data.h"

int main(){
	int choice, arraySize;
	arraySize = 115; //Size of array may be efficiently changed over the years
	//Prompt User with Options
	printf("Hello. Which option would you like? \n1: Display the record for a given year. \n2: Display years with at least 'i' losses. \n3: Display years with at least 'i' wins. \n4: Display years with a winning record. \n5: Display years with an equal number of wins and losses. \n6: Quit? \nPlease enter your choice: ");
	scanf("%d", &choice);
	
	//Choice 1: Display record for a given year
	if(choice == 1){
		int year;
		printf("Enter the year: ");
		scanf("%d", &year);
		printf("Wins: %d, Losses: %d\n", wins[year - 1900], losses[year - 1900]);
	}
	//Choice 2: Display years with at least 'i' Losses
	if(choice == 2){
		int minLosses, i;
		printf("Enter minimum number of losses: ");
		scanf("%d", &minLosses);
		printf("Years with at least %d losses: ", minLosses);
		for(i = 0; i < arraySize; i++){
			if(losses[i] >= minLosses){
				printf("%d ", i + 1900);
			}
		}
		printf("\n");
	}
	//Choice 3: Display years with at least 'i' Wins
	if(choice == 3){
		int minWins, i;
		printf("Enter minimum number of wins: ");
		scanf("%d", &minWins);
		printf("Years with at least %d wins: ", minWins);
		for(i = 0; i < arraySize; i++){
			if(wins[i] >= minWins){
				printf("%d ", i + 1900);
			}
		}
		printf("\n");
	}
	//Choice 4: Display years with a winning record
	if(choice == 4){
		int i;
		printf("Years with a winning record: ");
		for(i = 0; i < arraySize; i++){
			if(wins[i] > losses [i]){
				printf("%d ", i + 1900);
			}
		}
		printf("\n");
	}
	//Choice 5: Displays years with an equal number of wins and losses
	if(choice == 5){
		int i;
		printf("Years with an equal number of wins and losses: ");
		for(i = 0; i < arraySize; i++){
			if(wins[i] == losses [i]){
				printf("%d ", i + 1900);
			}
		}
		printf("\n");
	}
	//Choice 6: Quit
	if(choice == 6){
		printf("The undefeated Fight Irish of Notre Dame never quit!\n");
	}
		
	return 0;
}
