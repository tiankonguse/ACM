#include"iostream"
#include"cstdio"
#include"cstdlib"
#include"cstring"
#include"algorithm"
#define MAXN 100
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

struct block{
    int x,y,h;
    friend bool operator<(block a,block b){
        return (a.x==b.x)? (a.y>b.y): a.x>b.x;
    }
}bl[MAXN];
int dp[MAXN];
int main(){
    int N,x,y,z,cnt=1;
    while(scanf("%d",&N) && N){
        N*=3;
        for(int i=0;i<N;i+=3){
            scanf("%d%d%d",&x,&y,&z);
            bl[i].h=z;bl[i].x=max(x,y);bl[i].y=min(x,y);
            bl[i+1].h=x;bl[i+1].x=max(y,z);bl[i+1].y=min(y,z);
            bl[i+2].h=y;bl[i+2].x=max(x,z);bl[i+2].y=min(x,z);
        }
        sort(bl,bl+N);
       // for(int i=0;i<N;i++)printf("%d %d %d\n",bl[i].x,bl[i].y,bl[i].h);
        int ans=0;
        for(int i=0;i<N;i++){
            dp[i]=bl[i].h;
            for(int j=0;j<i;j++){
                if(bl[j].x>bl[i].x && bl[j].y>bl[i].y){
                    dp[i]=max(dp[i],dp[j]+bl[i].h);
                    if(dp[i]>ans)ans=dp[i];
                }
            }
        }
        printf("Case %d: maximum height = %d\n",cnt++,ans);
    }
    return 0;
}
