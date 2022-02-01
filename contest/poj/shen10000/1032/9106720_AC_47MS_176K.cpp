#include<stdio.h>
#include<math.h>

int main()
{
int m,k,n,q,h=2;
	bool t=false;
scanf("%d",&m);
	k=(int)sqrt((m+m)*1.0)+5;	
	n=(k*k+k-2)/2;

	while(n>m){n-=k;k--;}
	k++;
	q=k-(m-n);
	if(q==1){h=3;q=k;k++;}
	
	for(int i=h;i<=k;i++)
	{
		if(i==q)continue;
		
		if(t){printf(" %d",i);continue;}
		printf("%d",i);	
		t=true;
	}
	putchar('\n');
getchar();getchar();
return 0;
}
