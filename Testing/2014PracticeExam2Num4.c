#include <stdio.h>
#include <string.h>

int main(){
	int m = 5;
	int n = 7;
	char arr[8];
	
	printf("enter a line: ");
	fgets(arr, 15, stdin);
	
	printf(" m: %d\n", m);
	printf(" n: %d\n", n);
	printf(" line: %s\n", arr);
}
