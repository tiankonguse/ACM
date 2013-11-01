/*************************************************************************
    > File Name: 11292.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
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

#define FOR0(i,n) for(int i=0;i<(n);i++)
#define FOR0_(i,n) for(int i=(n)-1;i>=0;i--)
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR1_(i,n) for(int i=n;i>=1;i--)
#define READ_I(i) scanf("%d",&(i));


const int N = 20010;
int first[N],second[N];

int main() {
    int n,m,ans,cur;
    while(~scanf("%d%d",&n,&m),n){
        FOR0(i,n){
            READ_I(first[i]);
        }
        FOR0(i,m){
            READ_I(second[i]);
        }

        sort(first, first+n);
        sort(second, second+m);

        ans = 0;
        cur = 0;
        FOR0(i,m){
            if(second[i] >= first[cur]){
                ans += second[i];
                if(++cur == n){
                    break;
                }
            }
        }

        if(cur < n){
            printf("Loowater is doomed!\n");
        }else{
            printf("%d\n",ans);
        }

    }

    return 0;
}
