#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
long long res[20][222];
void init(){
    memset(res,0,sizeof(res));
    res[2][0] = res[2][1] = 1;
    for(int i=2;i<=17;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;res[i][k];k++){
                res[i+1][j+k] += res[i][k];
            }
        }
//        for(int z=0;z<=10;z++){
//            printf("%d ",res[i][z]);
//        }
//        printf("\n");
//        system("pause");
    }
}
int main(){
    init();
    int n,k;
    while(scanf("%d%d",&n,&k) && !(n==0 && k==0)){
        printf("%I64d\n",res[n][k]);
    }
    return 0;
}
