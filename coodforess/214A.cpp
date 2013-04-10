#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int n,m,a,b,c,ans;
	while(~scanf("%d%d",&n,&m)){
		c=(int)sqrt(n*1.0);
		ans=0;
		for(int a=0;a<=c;a++){
			b=n-a*a;
			if(b*b+a==m)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
