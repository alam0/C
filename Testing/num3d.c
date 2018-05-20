#include<math.h>
#include<stdio.h>
int fun(int, int); //prototype

int main()
{
 int a=5, b=6, n;
 n = fun(a, b);
 printf("%d %d %d\n", a, b, n);
 n = fun(8, 9);
 printf("%d %d %d\n", a, b, n);
}

int fun(int a, int b)
{
 int n = 7;
 return (a+b);}
