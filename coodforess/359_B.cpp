#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;

int str[200010];
int main() {
    int n,k,nn,i,t;
    while(~scanf("%d%d",&n,&k)) {
        nn = n*2;
        for(i=1; i<=nn; i++) {
            str[i] = i;
        }
        swap(str[2],str[k+1]);
        if(k > 1 && (k+1)%2 == 0) {
            swap(str[k],str[k+1]);
        }
        swap(str[1],str[2]);

        for(i=1; i<nn; i++) {
            printf("%d ",str[i]);
        }
        printf("%d\n",str[nn]);
    }



    return 0;
}

