#include<stdio.h>
#include<queue>
using namespace std;
typedef struct {
	int x,min;
}P;
int n,k,m;
P a,b;
queue <P> que;
bool map[100002];

void fun(int m)
{
	if(map[m])return;
	if(m<0||m>100000)return;
	
	a.x=m;
	a.min=b.min+1;
	que.push(a);		
}

int main()
{	
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(map,false,sizeof(map));
		while(!que.empty())que.pop();
		
		a.x=n;
		a.min=0;
		
		que.push(a);
		
		while(1){
			b=que.front();que.pop();			
			if(b.x==k){printf("%d\n",b.min);break;}			
			m=b.x+1;fun(m);		
			m=b.x-1;fun(m);
			m=b.x+b.x;fun(m);	
		}	
			
	}
			
return 0;	
}
