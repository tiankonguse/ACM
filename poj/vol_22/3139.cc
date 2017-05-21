#include"iostream"
#include"vector"
#define MAXSUM 10230
#define MAXN 17
#define MAX (1<<16)
using namespace std;
vector<int>v[MAXSUM];
int num[MAXN];
int cnt[MAX];
int data[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int main(){
    int s,mins,maxs,size,ans,cas=1;
    while(scanf("%d",&num[0])&&num[0]){
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<16;i++)scanf("%d",&num[i]);
        mins=MAX;
        maxs=0;
        for(int i=0;i<MAXSUM;i++)v[i].clear();
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                if(j==i)continue;
                for(int k=0;k<16;k++){
                    if(i==k || j==k)continue;
                    for(int l=0;l<16;l++){
                       if(l==i || l==j || l==k)continue;
                       s=(num[i]<<2)+num[j]*3+(num[k]<<1)+num[l];
                       if(s>maxs)maxs=s;
                       if(s<mins)mins=s;
                       v[s].push_back(data[i]|data[j]|data[k]|data[l]);
                    }
                }
            }
        }
        for(int i=mins;i<=maxs;i++){
            size=v[i].size();
            for(int j=0;j<size;j++){
                for(int k=j+1;k<size;k++){
                    if(v[i][j]&v[i][k])continue;
                    cnt[v[i][j]|v[i][k]]++;
                }
            }
        }
        ans=0;
        for(int i=0;i<(MAX>>1);i++){
            ans+=cnt[i]*cnt[(~i)&(MAX-1)];
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
