#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXL 55
#define MAXN 2505
#define MAXM 7000005
using namespace std;

char str[MAXL];
char map[MAXL][MAXL];
int node[MAXN][2];
int cnt;
bool used[MAXL][MAXL];
int mark[MAXL][MAXL];

int mat[MAXN][MAXN];
bool inTree[MAXN];
int min_length[MAXN];
int prim(int n)
{
    int sum_length=0;
    memset(inTree,false,sizeof(inTree));
    for(int i=1;i<n;i++)min_length[i]=INT_MAX;
    min_length[0]=0;
    for(int i=0;i<n;i++){
        int min_index=-1;
        for(int j=0;j<n;j++){
          if(!inTree[j]&&(min_index==-1 || min_length[j]<min_length[min_index])){
             min_index=j;
          }
        }
        inTree[min_index]=true;
        sum_length+=min_length[min_index];
        for(int j=0;j<n;j++){
           if(!inTree[j] && mat[j][min_index]<min_length[j]){
                 min_length[j]=mat[j][min_index];
           }
        }
    }
    return sum_length;
}


void init(){
    cnt=0;
}
struct nod{
    int x,y,t;
    nod(){}
    nod(int a,int b,int c){
        x=a,y=b,t=c;
    }
}q[MAXN],t;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void bfs(int sx,int sy){
    int l=0,h=1,tx,ty,ct=1;
    memset(used,false,sizeof(used));
    used[sx][sy]=true;
    q[0]=nod(sx,sy,0);
    while(l<h){
        t=q[l++];
        for(int i=0;i<4;i++){
            tx=t.x+dir[i][0];
            ty=t.y+dir[i][1];
            if(!used[tx][ty] && map[tx][ty]!='#'){
                used[tx][ty]=true;
                if(map[tx][ty]=='A' || map[tx][ty]=='S'){
                    mat[mark[sx][sy]][mark[tx][ty]]=t.t+1;
                    mat[mark[tx][ty]][mark[sx][sy]]=t.t+1;
                    ct++;
                    if(ct==cnt)return;
                }
                q[h++]=nod(tx,ty,t.t+1);
            }
        }
    }
}

int main(){
    int T,W,H;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d \n",&W,&H);
        //gets(str);
        for(int i=0;i<H;i++){
            gets(map[i]);
            for(int j=0;j<W;j++){
                if(map[i][j]=='A' || map[i][j]=='S'){
                    node[cnt][0]=i;
                    node[cnt][1]=j;
                    mark[i][j]=cnt;
                    cnt++;
                }
            }
        }
        for(int i=0;i<cnt;i++){
            bfs(node[i][0],node[i][1]);
        }
        printf("%d\n",prim(cnt));
    }
    return 0;
}
