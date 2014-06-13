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



int main() {
    int l,r,oddSum,evenSum;
    while(scanf("%d%d",&l,&r)!=EOF) {
        oddSum = evenSum = 0;
        if(l>r)swap(l,r);
        while(l<=r){
			l&1?oddSum+=l*l*l:evenSum+=l*l;
			l++;
        }
        printf("%d %d\n",evenSum,oddSum);
    }
    return 0;
}
