#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=1000;
int pre[N];
bool map[N];
void init(int n){
	for(int i=1;i<=n;i++)pre[i]=i;
}
int find(int x){
	return pre[x]!=x?find(pre[x]):x;
}

int main()
{
int x,y,k=1;
while(scanf("%d%d",&x,&y),x+1){
	if(x==0 && y==0){
		printf("Case %d is a tree.\n",k++);
	}
	bool yes=true;
	int num=0,edg=0;
	memset(map,true,sizeof(map));
	init(N);
	while(scanf("%d%d",&x,&y),x){
		if(yes){
			if(map[x])map[x]=false,num++;
			if(map[y])map[y]=false,num++;
			edg++;
			int a=find(x);
			int b=find(y);
			if(a==b)yes=false;
			//if(pre[b]!=b)yes=false;
			pre[b]=a;	
		}

	}
	if(edg+1!=num)yes=false;
	if(yes)printf("Case %d is a tree.\n",k++);
	else printf("Case %d is not a tree.\n",k++);
}

return 0;
}
