#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
#include<vector>
#include<functional>

#define PI acos(-1.0);
#define inf 0x3ffffffff;
using namespace std;
int str[500];
int sum[500];
int main(){

    int n,m,nm;
    int cas,ans;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&m);
        memset(str,0,sizeof(str));
        memset(sum,0,sizeof(sum));
        nm=n+m;
        ans = 0;
        for(int i=m;i<nm;i++){
            scanf("%d",&str[i]);
            str[i+n] = str[i];
            sum[i] = sum[i-1] - str[i-m] + str[i];
            if(ans < sum[i]){
                ans = sum[i];
            }
        }
        for(int i=nm;i<nm+n;i++){
            sum[i] = sum[i-1] - str[i-m] + str[i];
            if(ans < sum[i]){
                ans = sum[i];
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
