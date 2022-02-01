#include "cstdio"
#include "cstring"
#include "iostream"
#define MAXN 101
using namespace std;
int N,res[MAXN],tmp[MAXN],ans;

void dfs(int dep,int num){
    if(dep>=ans)return;
    else if(num==N){
       // cout<<"dep="<<dep<<endl;
        ans=dep;
        for(int i=0;i<dep;i++){
            res[i]=tmp[i];
        }
        return;
    }
    for(int i=0;i<dep;i++){
        int s=tmp[i]+tmp[dep-1];
        if(s<res[dep-1])continue;
        //cout<<"dep="<<dep<<",s="<<s<<endl;
        if(s>N)return;
        tmp[dep]=s;
        dfs(dep+1,s);
    }
}
int main(){
    while(scanf("%d",&N)&&N){
        ans=N+1;
        tmp[0]=1;
        dfs(1,1);
      //  cout<<"ans="<<ans<<endl;
        for(int i=0;i<ans;i++){
            if(i==ans-1)printf("%d\n",res[i]);
            else printf("%d ",res[i]);
        }
    }
    return 0;
}
