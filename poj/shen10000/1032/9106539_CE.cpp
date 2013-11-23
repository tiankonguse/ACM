#include<iostream>
#include<string>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main()
{
int m;

scanf("%d",&m);
	int k=(int)(sqrt(m+m)+5);	
	int n=(int)((k*k+k-2)/2);

	while(n>m){n-=k;k--;}
	k++;
	int q=k-(m-n);

	bool t=false;
	int h=2;
	if(q==1){h=3;q=k;k++;}
	for(int i=h;i<=k;i++)
	{
		if(i==q)continue;
		if(t)putchar(' ');
		printf("%d",i);	
		t=true;
	}
	putchar('\n');
getchar();getchar();
return 0;
}
