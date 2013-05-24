#include <iostream>
#include <cmath>
#include<algorithm>
#include<queue> 
#include<cstring>
using namespace std;
struct node{
	int to,len;
};
bool operator<(const node&a,const node&b)
{
	return a.len>b.len;
};
struct node2{
	int f,g,h,to;
};
bool operator<(const node2&a,const node2&b)
{
	return a.f>b.f;
};
priority_queue<node>q;
priority_queue<node2>q2;
const int maxn=1010;
int dis[maxn];
int fir1[maxn],next1[100*maxn],to1[100*maxn],len1[100*maxn];
int fir2[maxn],next2[100*maxn],to2[100*maxn],len2[100*maxn];
int s,target,k,d;
const int inf=99999999;
int n,m;
void dijkstra()
{
	bool done[maxn];
	for(int i=1;i<=n;i++)dis[i]=inf;
	dis[target]=0;
	memset(done,0,sizeof(done))	;
	node temp;
	temp.to=target;
	temp.len=0;
	q.push(temp);
	while(!q.empty())
	{
		temp=q.top();
		q.pop();
		if(done[temp.to])continue;
		done[temp.to]=1;
		for(int e=fir1[temp.to];e!=-1;e=next1[e]) if(dis[to1[e]]>dis[temp.to]+len1[e])
		{
			dis[to1[e]]=dis[temp.to]+len1[e];
			node temp2;
			temp2.len=dis[to1[e]];
			temp2.to=to1[e];
			q.push(temp2);
		}
	}
}
int Astar()
{
	int cnt[maxn];
	memset(cnt,0,sizeof(cnt));
	if(dis[s]==inf)return-1;
	node2 temp;
	temp.to=s;temp.g=0;temp.h=dis[s];temp.f=temp.g+temp.h;
	q2.push(temp);
	while(q2.empty()==0)
	{
		temp=q2.top();
		q2.pop();
		cnt[temp.to]++;
		if(cnt[target]==k)return temp.f;
		if(cnt[temp.to]>k)continue;
		node2 temp2;
		for(int e=fir2[temp.to];e!=-1;e=next2[e])
		{
			temp2.g=temp.g+len2[e];
			temp2.h=dis[to2[e]];
			temp2.f=temp2.g+temp2.h;
			temp2.to=to2[e];
			q2.push(temp2);
		} 
	}
	return -1;
}
int main()
{
	
	scanf("%d%d",&n,&m);
	memset(fir1,-1,sizeof(fir1));
	memset(fir2,-1,sizeof(fir2));
	int num1=0;
	int num2=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&s,&target,&d);
		len1[num1]=d;to1[num1]=s;next1[num1]=fir1[target];fir1[target]=num1++;
		len2[num2]=d;to2[num2]=target;next2[num2]=fir2[s];fir2[s]=num2++;
	}
	scanf("%d%d%d",&s,&target,&k);
	dijkstra();
	if(s==target)k++;
	printf("%d\n",Astar());
}
