#include <stdio.h>
void func(int, int *);
void show(int, int);

int main(){
	int n = 15, *p = &n;
	func(n, p);
	show(n, *p);
}

void func(int n, int *m){
	n = 2;
  *m = 3; 
}
void show(int a, int b){
	printf("%d %d\n", a, b); 
}
