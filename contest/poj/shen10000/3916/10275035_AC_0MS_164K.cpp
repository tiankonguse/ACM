#include<string>
#include<iostream>
using namespace std;

int main()
{
int n,a,b;
while(scanf("%d",&n),n){
	a=0;
	while(n--){
		scanf("%d",&b);
		if(a!=b){
			printf("%d ",b);
			a=b;
		}
	}
	printf("$\n");
}
return 0;
}
