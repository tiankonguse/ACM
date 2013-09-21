/*************************************************************************
    > File Name: E.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 11:01:05
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
int const N = 1000005;
int const M = 1000005;

bool is[N];
int prm[N];

void getprm(){
    int i,j;
    for(i=2;i<=N;i++)
    {
        if(prm[i]==0)
        {

            for(j=i+i;j<=N;j+=i)
              prm[j]=1;
        }

    }

}

int main() {

    getprm();
    int n, i;
    while(scanf("%d",&n), n){
        for(i = 2;i<=n/2 ;++i){
            if(prm[i]==0&&prm[n-i]==0)break;
        }
        printf("%d = %d + %d\n",n,i,n-i);
    }

    return 0;
}
