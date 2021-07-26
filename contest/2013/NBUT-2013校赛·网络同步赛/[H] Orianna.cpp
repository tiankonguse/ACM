/*************************************************************************
    > File Name: [H] Orianna.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/18 15:29:08
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 100110;

LL ans[2][6][N];
LL str[6][N];

int main() {

    int n,i,j,k;
    while(~scanf("%d",&n)){
        for(i=0;i<5;i++){
            for(j=0;j<n;j++){
                scanf("%lld",&str[i][j]);
                ans[0][i][j] = ans[1][i][j] = -99999l;
            }
        }



        LL _max = 0;
        for(i=0;i<5;i++){
            ans[0][i][0] = ans[1][i][0] = str[i][0];
            _max = max(_max,ans[0][i][0]);
            _max = max(_max,ans[1][i][0]);
        }

        for(i=1;i<n;i++){
            for(j=0;j<5;j++){
                for(k=0;k<5;k++){
                    if(j==k)continue;
                    if(j > k){
                        ans[1][j][i] = max(ans[1][j][i],ans[0][k][i-1] + str[j][i]);
                    }else if(j < k){
                        ans[0][j][i] = max(ans[0][j][i],ans[1][k][i-1] + str[j][i]);
                    }
                }
                _max = max(_max,ans[0][j][i]);
                _max = max(_max,ans[1][j][i]);
            }
        }
//        for(i=0;i<5;i++){
//            for(j=0;j<n;j++){
//                printf("%7lld/%-7lld ",ans[0][i][j],ans[1][i][j]);
//            }
//            puts("");
//        }


        printf("%lld\n",_max);

    }


    return 0;
}
