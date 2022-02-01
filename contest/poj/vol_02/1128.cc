#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 30
#define MAXL 35
#define MAXM 1000
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int N,idx;
int p[MAXN];
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}

int cnt;
char map[MAXL][MAXL];
bool used[MAXN];
bool tesd[MAXN];
int degree[MAXN];
int H,W;
struct lett{
    int l,r,u,d;
}l[MAXN];

/*void tsort(){
    int start,u;
    for(int k=0;k<cnt;++k){
        for(int i=0;i<26;++i){
            if(used[i] && degree[i]==0){
                start=i;
                break;
            }
        }
        printf("%c",start+'A');
        --degree[start];
        for(int i=p[start];i!=-1;i=e[i].next){
            u=e[i].u;
            --degree[u];
        }
    }
    printf("\n");
}*/

char ans[MAXN];
void tsort(int dep){
    if(dep==cnt){
        ans[dep]='\0';
        printf("%s\n",ans);
    }
    for(int i=0;i<26;i++){
        if(used[i] && degree[i]==0){
            ans[dep]=i+'A';
            degree[i]=-1;
            for(int j=p[i];j!=-1;j=e[j].next){
                --degree[e[j].u];
            }
            tsort(dep+1);
            degree[i]=0;
            for(int j=p[i];j!=-1;j=e[j].next){
                ++degree[e[j].u];
            }
        }
    }

}

void check(int i,int j,int k){
    if(map[j][k]=='.')return;
    int t=map[j][k]-'A';
    if(!tesd[t]){
        tesd[t]=true;
       // printf("add(%c,%c)\n",t+'A',i+'A');
        addedge(i,t);
        ++degree[t];
    }
}
void init(){
    idx=cnt=0;
    memset(p,0xff,sizeof(p));
    memset(used,false,sizeof(used));
    memset(degree,0,sizeof(degree));
}
int main(){
    int a;
    while(~scanf("%d%d",&H,&W)){
        init();
        for(int i=0;i<H;++i){
            scanf("%s",map[i]);
        }
        for(int i=0;i<H;++i){
            for(int j=0;j<W;++j){
                if(map[i][j]!='.'){
                    a=map[i][j]-'A';
                    if(!used[a]){
                        used[a]=true;
                        l[a].u=l[a].d=i;
                        l[a].l=l[a].r=j;
                    }
                    else{
                        l[a].u=min(l[a].u,i);
                        l[a].d=max(l[a].d,i);
                        l[a].l=min(l[a].l,j);
                        l[a].r=max(l[a].r,j);
                    }
                }
            }
        }
        //for(int i=0;i<26;i++)if(used[i])printf("%c:(u,d,l,r)=(%d,%d,%d,%d)\n",i+'A',l[i].u,l[i].d,l[i].l,l[i].r);
        for(int i=0;i<26;++i){
            if(used[i]){
                ++cnt;
                memset(tesd,false,sizeof(tesd));
                tesd[i]=true;
                for(int j=l[i].u;j<=l[i].d;++j){
                    check(i,j,l[i].l);
                    check(i,j,l[i].r);
                }
                for(int k=l[i].l+1;k<l[i].r;++k){
                    check(i,l[i].u,k);
                    check(i,l[i].d,k);
                }
            }
        }
        tsort(0);
    }
    return 0;
}
