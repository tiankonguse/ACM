#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXP 555555
#define MAXN 1005
using namespace std;
int pri[MAXP],cnt;
bool mark[MAXP];
int setp(){
    int i,j;
    cnt=0,pri[0]=2;
    for(i=2;i<MAXP;i++){
        if(!mark[i])pri[cnt++]=i;
        for(j=0;j<cnt && pri[j]*i<MAXP;++j){
            mark[i*pri[j]]=1;
            if(!(i%pri[j]))break;
        }
    }
    return cnt;
}
int N,M,D,P;
int res[MAXN]={0};
bool used[MAXN];
bool flag;
int s;
bool dfs(int d){
    if(d==P+1)return true;
    for(int i=N;i<=M;i++){
        if(!used[i]){
            used[i]=true;
            if(d>=D){
                flag=true;
                s=i;
                for(int j=d-1;j>d-D;j--){
                    s+=res[j];
                    if(!mark[s]){flag=false;break;}
                }
                if(flag){
                    res[d]=i;
                    if(dfs(d+1))return true;
                }
            }
            else{
                flag=true;
                s=i;
                for(int j=d-1;j>0;j--){
                    s+=res[j];
                    if(!mark[s]){flag=false;break;}
                }
                if(flag){
                    res[d]=i;
                    if(dfs(d+1))return true;
                }
            }
            used[i]=false;
        }
    }
    return false;
}
int main(){
    setp();
    while(scanf("%d%d%d",&N,&M,&D) && D){
        P=M-N+1;
        memset(used,false,sizeof(used));
        if(dfs(1)){
            for(int i=1;i<=P;i++){
                if(i==P)printf("%d\n",res[i]);
                else printf("%d,",res[i]);
            }
        }
        else printf("No anti-prime sequence exists.\n");
    }
    return 0;
}
