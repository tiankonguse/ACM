#include<iostream>
using namespace std;
#define N 10005
int map[N];
int Caculate(int j)
{
	if(map[j])return map[j];
	int no=1;
	int i=j;
	while(1)
	{
		if(j==1)break;
		if(j%2==0) j/=2;
		else       j=3*j+1;
		no++;			
	}
	return map[i]=no;
}
int main()
{
	int n,m;
	memset(map,0,sizeof(map));
	while(cin>>n>>m)
	{
		int j;
		int tempn=n,tempm=m;
		if(n>m){j=n;n=m;m=j;}
		int max=0;
		for(j=n;j<m+1;j++)
		{
			int temp=Caculate(j);
			max=max>temp?max:temp;
		}
		printf("%d %d %d\n",tempn,tempm,max);
	}
	return 0;
}
