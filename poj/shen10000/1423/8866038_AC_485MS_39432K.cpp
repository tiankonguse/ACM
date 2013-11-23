#include<iostream>
#include<math.h>
using namespace std;
int num=1;
int str[10000003];
double sum=0.0;
void fun(int n)
{

	for(int i=num+1;i<=n;i++)
	{
			sum+=log10(1.0*i);
	str[i]=(int)sum+1;
	}
num=n;

}



int main()
{
int n,m;
memset(str,0,sizeof(str));
str[1]=1;
cin>>n;
while(n--)
{
cin>>m;
if(!str[m])fun(m);
printf("%d\n",str[m]);
}

//getchar();getchar();
return 0;
}


