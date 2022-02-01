#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int A,a, B, b, P;
	scanf("%d%d%d%d%d",&A, &a, &B, &b, &P);
	if(A+B<=P)printf("Yes\n");
	else if(A<=b&&B<=P)printf("Yes\n");
	else if(B<=a&&A<=P)printf("Yes\n");
	else printf("No\n");
getchar();getchar();
return 0;
}
