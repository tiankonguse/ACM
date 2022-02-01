#include<stdio.h>
#include<queue>
#define N 100000
using namespace std;
typedef struct {
	int x,min;
}P;
int n,k,m;
P a,b;
queue <P> que;
bool map[N+N+1];

void fun(int m,int min)
{
	if(map[m])return;
	if(m<0)return;
	map[m]=true;
	a.x=m;
	a.min=min+1;
	que.push(a);		
}

int main()
{	
	while(scanf("%d%d",&n,&k)!=EOF){
		if(k<=n){printf("%d\n",n-k);continue;}
		
		memset(map,false,sizeof(map));
		while(!que.empty())que.pop();
		
		a.x=n;
		a.min=0;
		
		que.push(a);
		
		while(1){
			b=que.front();que.pop();			
			if(b.x==k){printf("%d\n",b.min);break;}			
		
			m=b.x-1;fun(m,b.min);
			
			if(b.x > k)continue;
			m=b.x+1;fun(m,b.min);			
			m=b.x+b.x;
			fun(m,b.min);	
		}	
			
	}
			
return 0;	
}
