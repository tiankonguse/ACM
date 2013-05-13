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
bool sum[550][555];
int top[555];
int bottom[555];

int add(int a,int b){
    if(sum[a][b]){
        return 0;
    }
    sum[a][b] = sum[b][a] =1;
    return 1;
}

int main(){

    int n,m,i;
    int cas,ans;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d",&top[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d",&bottom[i]);
        }
        memset(sum,false,sizeof(sum));
        ans= 0;
        for(i=1;i<=m;i++){
            ans += add(top[i],bottom[i]);
        }
        printf("%.3f\n",ans*1.0/n);

    }

    return 0;
}
