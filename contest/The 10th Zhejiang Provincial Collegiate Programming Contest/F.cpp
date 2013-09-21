#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<vector>
#include<functional>
//1111111111111111111111111111111111111111111111111111111111111111
#define PI acos(-1.0);
#define inf 0x3ffffffff;
using namespace std;
int str[111][111];
int sum[500];
int main(){
    map<string,int>Map;
    Map.clear();
    Map["123"]=1;
    printf("%d  %d\n",Map["123"],Map["222"]);


    for(int i=0;i<64;i++){
    printf("%c",'1');
    }
//    printf("%0X\n",154);
    int n,m,k,from,to;
    int cas,ans,i,j,now,kk;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d",&n,&m,&k);
        memset(str,0,sizeof(str));
        ans = 0;
        while(m--){
            scanf("%d%d",&from,&to);
            str[from][to] = str[to][from] = 1;
        }

        bool ok = false;
        while(1){
                ok = false;
            for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                    if(str[i][j])continue;
                    now = 0;
                    for(kk=0;kk<n;kk++){
                        if(kk!=i && kk!=j && str[i][kk] && str[kk][j] ){
                            now++;
                        }
                    }
                    if(now>=k){
                        ok = true;ans++;
                        str[i][j] = str[j][i] =1;
                    }
                }
            }
            if(!ok)break;
        }
        printf("%d\n",ans);

    }

    return 0;
}
