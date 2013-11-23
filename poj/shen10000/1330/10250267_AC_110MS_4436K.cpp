#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
using namespace std;
const int N=10020;
vector<int>e[N];
int indegree[N],first[N],last[N],dep[N<<2],id,pos[N<<2],f[N<<2][40],num,wei[N];
#define CLR(arr,val) memset(arr,val,sizeof(arr))
int min(int a,int b){return dep[a]>dep[b]?b:a;}
void init(){
	for(int i=0;i<N;i++){
		e[i].clear();
		indegree[i]=0;
		first[i]=-1;
		num=0;
	}
	id=1;
}

void S_table(){
	id--;
	for (int i=1;i<=id;i++) f[i][0] =i;
for(int j=1,tj=2;tj<=id;++j,tj<<=1)
for(int i=1,ti=(tj>>1);i+tj-1<=id;++i)
	f[i][j]=min(f[i][j-1],f[i+ti][j-1]);
}
void dfs(int u,int d){
	if(first[u]==-1){
		wei[u]=num++;
		first[u]=id;
	}
		last[u]=id;
		dep[id]=d;
		pos[id++]=u;
		int l=e[u].size();
	for(int i=0;i<l;i++){
		dfs(e[u][i],d+1);
		dep[id]=d;
		last[u]=id;
		pos[id++]=u;
		
	}
}

int rmq(int x, int y) {
int k=(int)(log((double)(y-x+1))/log(2.0));
return min(f[x][k],f[y-(1<<k)+1][k]);
}
int main()
{
	int n,u,v;
	scanf("%d",&n);	
	while(~scanf("%d",&n)){
		init();
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			indegree[v]++;
		}
		for(int i=1;i<=n;i++){
			if(indegree[i]==0){
//				printf("%d\n",i);
				dfs(i,0);
			}
		}
			
		S_table();
//		printf("%d\n",id);
//		for(int i=1;i<=id;i++)
//			printf("%d ",i);
//		printf("\n");
//		for(int i=1;i<=id;i++)
//			printf("%d ",pos[i]);
//		printf("\n");
//		for(int i=1;i<=id;i++)
//			printf("%d ",dep[i]);
//		printf("\n\n");
//		for(int i=1;i<=n;i++)
//			printf("%d ",wei[i]);
//		printf("\n\n");
		scanf("%d%d",&u,&v);
		if(wei[u]>wei[v]){
			u^=v;
			v^=u;
			u^=v;
		}
//		printf("%d:%d %d\n",u,first[u],last[u]);
//		printf("%d:%d %d\n",v,first[v],last[v]);
		if(first[v]<last[u])printf("%d\n",u);
		else printf("%d\n",pos[rmq(last[u],first[v])]);
	}
return 0;
}
