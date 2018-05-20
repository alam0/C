#include<math.h>
#include<stdio.h>
int main(){
	int i;
	for(i=20; i<100; i++) {
		if(i<50) continue;
		if(i%9==0) break;
		printf("%d\n", i);
	}
}
