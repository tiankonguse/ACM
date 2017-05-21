#include"iostream"
#include"cstdlib"
#define inf 0x3f3f3f3f
#define MAXN 210
using namespace std;
template<class T> inline void checkmin(T &a,T b)  {if(a < 0 || a > b)a = b;}
int maze[MAXN][MAXN];
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];
int sap(int s,int t,int nodenum) {
	memset(cur,0,sizeof(cur));
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
	int u = pre[s] = s,maxflow = 0,aug = -1;
	gap[0] = nodenum;
	while(dis[s] < nodenum) {
loop:		for(int v=cur[u];v<nodenum;v++) if(maze[u][v] && dis[u] == dis[v] + 1) {
			checkmin(aug,maze[u][v]);
			pre[v] = u;
			u = cur[u] = v;
			if(v == t) {
				maxflow += aug;
				for(u = pre[u];v != s;v = u,u = pre[u]) {
					maze[u][v] -= aug;
					maze[v][u] += aug;
				}
				aug = -1;
			}
			goto loop;
		}
		int mindis= nodenum-1;
		for(int v=0;v<nodenum;v++) if(maze[u][v] && mindis> dis[v]) {
			cur[u] = v;
			mindis= dis[v];
		}
		if((--gap[dis[u]])== 0)    break;
		gap[dis[u] = mindis+1] ++;
		u = pre[u];
	}
	return maxflow;
}
int ph[102],pigs[1002];
int main(){
    int M,N,k,h;
    scanf("%d%d",&M,&N);
    for(int i=1;i<=M;i++){
        scanf("%d",&pigs[i]);
    }
    for(int i=1;i<=N;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&h);
            if(ph[h]==0){
                maze[0][i]+=pigs[h];
            }
            else{
                maze[ph[h]][i]=inf;
            }
            ph[h]=i;
        }
        scanf("%d",&maze[i][N+1]);
    }
    printf("%d\n",sap(0,N+1,N+2));
   // system("pause");
    return 0;
}
