#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=1000;
int pre[N],rank[N];
bool map[N];
void init(int n){
	for(int i=1;i<=n;i++)pre[i]=i,rank[i]=0;
}
int find(int x){
	return pre[x]=pre[x]!=x?find(pre[x]):x;
}
void _union(int a,int b){//ÓÅ»¯ÎªÐ¡Ê÷½Ó´óÊ÷ÉÏ
	if(rank[a]>rank[b]){pre[b]=a;return ;}
	pre[a]=b;
	if(rank[a]==rank[b])rank[b]++;
}
int main()
{
int x,y,k=1;
while(scanf("%d%d",&x,&y),x+1){

	if(x==0 && y==0){
		printf("Case %d is a tree.\n",k++);
		continue;
	}
	bool yes=true;
	int num=0,edg=0;
	memset(map,0,sizeof(map));
	init(N);
	if(!map[x])map[x]=true,++num;
	if(!map[y])map[y]=true,++num;
	edg++;
	
	if(x==y)yes=false;
	else _union(x,y);
	
	while(scanf("%d%d",&x,&y),x){
		if(yes){
			if(!map[x])map[x]=true,num++;
			if(!map[y])map[y]=true,num++;
			edg++;
			int a=find(x);
			int b=find(y);
			if(a==b)yes=false;
			else _union(a,b);	
		}

	}
	if(edg+1!=num)yes=false;
	if(yes)printf("Case %d is a tree.\n",k++);
	else printf("Case %d is not a tree.\n",k++);
}

return 0;
}
