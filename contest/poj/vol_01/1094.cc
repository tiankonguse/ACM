#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define MAXN 30
#define MAXM 1000
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int N,M,idx;
int p[MAXN];
int degree[MAXN],tdeg[MAXN];
int ans[MAXN],at;
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
int tsort(){
    at=0;
    int cnt,start,u;
    int res=1;//0:loop,1:sorted,2:nots
    memcpy(tdeg,degree,sizeof(degree));
    for(int i=0;i<N;++i){
        cnt=0;
        for(int j=0;j<N;++j){
            if(tdeg[j]==0){
                start=j;
                ++cnt;
            }
        }
        if(cnt==0)return 0;
        else if(cnt>1)res=2;
        ans[at++]=start;
        tdeg[start]=-1;
        for(int j=p[start];j!=-1;j=e[j].next){
            u=e[j].u;
            --tdeg[u];
        }
    }
    return res;
}
void init(){
    idx=0;
    memset(p,0xff,sizeof(p));
    memset(degree,0,sizeof(degree));
}
char str[10];
int main(){
    int a,b,s;
    while(scanf("%d%d",&N,&M)&&N){
        init();
        s=-1;
        for(int i=1;i<=M;++i){
            scanf(" %s",str);
            if(s==0 || s==1)continue;
            a=str[0]-'A',b=str[2]-'A';
            addedge(a,b);
            degree[b]++;
            s=tsort();
            if(s==0){
                printf("Inconsistency found after %d relations.\n",i);
            }
            else if(s==1){
                printf("Sorted sequence determined after %d relations: ",i);
                for(int j=0;j<N;++j){
                   printf("%c",ans[j]+'A');
                }
                printf(".\n");
            }

        }
        if(s==2)printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
