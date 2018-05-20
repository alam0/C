#include<math.h>
#include<stdio.h>
int main(){
	int n;
	n = 21;
	do {
		switch(n%10) {
 			case 1:
 			case 2:
			case 3:
 				printf("up\n");
 				n++;
			case 4:
 				printf("jump\n");
 				n *= 2;
 				break;
			default:
 				printf("down\n");
 				n--;
 				break;
		}
	printf("%d\n", n);
	} while( n%3 != 0 );
}
