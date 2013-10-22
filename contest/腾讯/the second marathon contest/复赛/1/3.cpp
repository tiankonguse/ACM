/**************************************************************************
 **      File Name: 3.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/29 18:25:31
/**************************************************************************/

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
const int N = 1000000007;
//C(n,r)=C(n-1,r)+C(n-1,r-1)
__int64 str[50][50];
__int64 _sum[447];
int array[50];
__int64 ans;

int n,sum;

int get(int k){
    __int64 tmp =0;
    for(int i=0;i<n;i++){
        tmp = (tmp + ((str[array[i]][k]*(sum-k+1) % N) *_sum[k] % N))%N;
    }
    return (tmp * _sum[sum-k]) % N;
}

int main(){
    int i,j,t,x,_max;
    memset(str,0,sizeof(str));
    for(i=0;i<50;i++){
        str[i][0] = 1;
        for(j=1;j<i;j++){
            str[i][j] = (str[i-1][j] + str[i-1][j-1]) % N;
        }
        str[i][i] = 1;
    }
    _sum[0] = 1;
    for(i=1;i<448;i++){
        _sum[i] = _sum[i-1] * i % N;
    }

    scanf("%d",&t);

    for(i=1;i<=t;i++){
        scanf("%d",&n);
        ans = 1;
        sum = 0;
        _max = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&array[i]);
            sum += array[i];
            _max = max(_max,array[i]);
        }

        ans = _sum[sum];
        for(int i=2;i<=_max;i++){
            if(i%2 == 0){
                ans = (ans - get(i)) % N;
            }else{
                ans = (ans + get(i)) % N;
            }
        }

        printf("%I64d\n",ans);

    }




    return 0;
}
/*
3
2
1 2
2
1 3
3
1 2 3


Sample Output
Case 1: 2
Case 2: 0
Case 3: 120
*/
