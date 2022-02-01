/*************************************************************************
    > File Name: 11464.cpp
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

const int N = 20;
int n,first[N][N],second[N][N];
int inf = 1000000000;

void _printf(int str[][N]){
    puts("");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",str[i][j]);
        }
        puts("");
    }
}

int check(int state) {
    memset(second,0,sizeof(second));
    int i,j,sum;
    for(j=0; j<n; j++) {
        if(state & (1<<j)) {
            second[0][j] = 1;
        } else {
            if(first[0][j] == 1) {
                return inf;
            }
            second[0][j] = 0;
        }
    }

    for(i=1; i<n; i++) {
        for(j=0; j<n; j++) {
            sum = 0;
            sum += i>1 ? second[i-2][j]: 0;
            sum +=  j>0 ? second[i-1][j-1]:0;
            sum += j<n-1?second[i-1][j+1]:0;
            second[i][j] = sum%2;
            if(second[i][j] == 0 && first[i][j] == 1) {
                return inf;
            }
        }
    }
    i = n-1;
    for(j=0; j<n; j++) {
        sum = 0;
        sum += i>0 ? second[i-1][j]: 0;
        sum +=  j>0 ? second[i][j-1]:0;
        sum += j<n-1?second[i][j+1]:0;

        if(sum%2 == 1) {
//            return inf;
        }
    }

//    _printf(first);
//    puts("");
//    _printf(second);

    sum = 0;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(second[i][j] != first[i][j]) {
                sum++;
            }
        }
    }
    return sum;

}

int main() {
    int cas,ans,i,j;
    scanf("%d",&cas);
    for(int ca=1; ca<=cas; ca++) {

        scanf("%d",&n);
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                scanf("%d",&first[i][j]);
            }
        }
//        memset(first,0,sizeof(first));
//        inf = n*n +1;
        ans = inf;
        for(i=0,j=1<<n; i<j; i++) {
            int tmp = check(i);
            if(tmp == inf){
//                printf("%d\n",tmp);
            }

//            break;
            ans = min(ans, tmp);
        }
        if(ans == inf) {
            ans = -1;
        }
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
/*

1 0 1 1 0
0 0 1 1 1
0 1 0 1 1
1 0 1 0 0
0 1 0 0 1
*/
