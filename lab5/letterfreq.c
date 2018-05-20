#include<stdio.h>
#include<ctype.h>

int alpharray[26];
int main(){
	FILE *fp;
	char afile[20];
	printf("Please enter your file name: ");
	scanf("%s", afile);
	
	fp = fopen(afile, "r");
	if(!fp){ //checks if file exists
		printf("error in opening file %s\n", afile);
		return 1;
	}
	
	double s=0; 
	double total = -1; //-1 to account for the eof iteration
	char c;
	//Accumulate the Alphabet Array
	while(!feof(fp)){ //until the end of the text
		c = fgetc(fp);
		if(c == 32){
			s = s++;
		}
		c = tolower(c); //make all lowercase
		if( c >= 'a' && c <= 'z' ){ //only use letters
			alpharray[c - 'a']++;	
		}
		if( c != 10 )
			total++;
	}
//Print Results
	int i, totalL = 0;
	double spacePercent;
	for(i = 0; i <= 25; i++){
		totalL = totalL + alpharray[i]; //Accumulate total letters
		printf("alpharray[%c] = %d\n", 97 + i,  alpharray[i]);
	}
	spacePercent = (s/total)* 100;
	printf("The total number of letters is: %d\n", totalL);
	printf("The total number of characters is: %.0lf\n", total);
	printf("The number of white spaces is: %.0lf\n", s);
	printf("The space percentage is: %.1lf\n %", spacePercent);
	fclose(fp);
	
	return 0;
}
	
