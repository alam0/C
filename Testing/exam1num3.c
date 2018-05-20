#include <stdio.h>
#include <math.h>

int main(){
	int a, b = 3;
	for(a = 2;a <= 3; a++){
		if(a==b) b = 2;
		if(a!=b) b = 3;
		printf("%d %d \n", a, b);
	}
}
