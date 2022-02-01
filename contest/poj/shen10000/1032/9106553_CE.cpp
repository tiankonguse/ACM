#include<stdio.h>
#include<math.h>

int main()
{
int m,k,n,q,h;

scanf("%d",&m);
	k=(int)(sqrt(m+m)+5);	
	n=(int)((k*k+k-2)/2);

	while(n>m){n-=k;k--;}
	k++;
	q=k-(m-n);

	bool t=false;
	h=2;
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
