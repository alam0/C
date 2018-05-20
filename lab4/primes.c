// primes.c
#include<stdio.h>
#include<math.h>

int main(){
	int a[1000] = {1}, i, n = 2;
	for(i = 2; i < 1000; i++){
		if(a[i] == 1 && (i % n == 0)){
			a[i] = 0;
		}
		n++;
	}
	for(i = 1; i < 1000; i++){
		if(a[i] == 1){
			printf("%d ", i);
		}
	}
	
}
					
