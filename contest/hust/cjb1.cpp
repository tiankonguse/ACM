#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 1007
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

const LL mod = 1000000007;
struct node{
    LL t,w;
}str[maxn];

bool vis[maxn];
LL cnt[maxn];
LL next[maxn];
LL who[maxn];
char s[maxn];
LL t[maxn];
LL w[maxn];

LL gt[maxn];
void  init(){
    gt[0]=gt[1]=1;
    for(LL i=2;i<=100;i++){
        gt[i]=i*gt[i-1]%mod;
    }
}

void dfs(LL i){
    if(i==-1)return;
    vis[i]=true;
    dfs(who[next[str[i].t]]);
}

LL have[maxn];


int main(){
//    freopen("B-large (2).in","r",stdin);
//    freopen("output.txt","w",stdout);
    LL _,cas=1,n;
    scanf("%lld",&_);
    init();
    while(_--){
        scanf("%lld",&n);
        bool ok=true;
        memset(cnt,0,sizeof cnt);
        memset(vis,0,sizeof vis);
        memset(t,0,sizeof t);
        memset(have,0,sizeof have);
        memset(w,0,sizeof w);
        LL c=0;
        for(LL i=0;i<n;i++){
            scanf("%s",s);
            LL len = strlen(s);
            LL qq=s[0],hh=s[len-1];
            bool issame=true;
            for(LL i=0;i<len;i++){
                if(s[i]!=qq)issame=false;
            }
            if(issame){
                cnt[qq]++;
                vis[qq]=true;
                continue;
            }
            if(qq==hh)ok=false;
            for(LL i=1;i<len;i++){
                if(s[i]==s[i-1])continue;
                have[s[i]]++;
            }
            have[s[len-1]]--;
            str[c].t=qq;str[c++].w=hh;
            t[qq]++;
            w[hh]++;
        }

        LL ans=1;
        LL cc=0;
        for(LL i='a';i<='z';i++){
            if(w[i]>1)ok=false;
            if(t[i]>1)ok=false;
            if(w[i]==0&&t[i]==0&&vis[i])cc++;
            if(have[i]>1)ok=false;
            if(have[i]==1){
                if(cnt[i])ok=false;
                if(t[i])ok=false;
                if(w[i])ok=false;
            }
            ans*=gt[cnt[i]];
            ans%mod;
        }

        bool fine = true;
        for(LL i=0;i<c;i++){
            LL now = str[i].t;
            fine = true;
            for(LL j=0;j<c;j++){
                if(now==str[j].w){
                    fine=false;
                }
            }
            if(fine==true)break;
        }
        if(!fine)ok=false;
        printf("Case #%lld: ",cas++);
        if(!ok){puts("0");continue;}

        memset(vis,0,sizeof vis);
        memset(who,-1,sizeof who);
        for(LL i=0;i<c;i++){
            next[str[i].t]=str[i].w;
            who[str[i].t]=i;
        }

        for(LL i=0;i<c;i++){
            LL now = str[i].t;
            fine = true;
            for(LL j=0;j<c;j++){
                if(now==str[j].w){
                    fine=false;
                }
            }
            if(fine==true){
                dfs(i);
                cc++;
            }
        }

        ans*=gt[cc];
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
