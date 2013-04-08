/**************************************************************************
 **      File Name: H.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/31 12:08:57
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

typedef long long LL;
int lev;

LL read(char *p){
    long long t = 0;

    while(*p >= '0' && *p <= '9'){
        t = t * 10 + *p - '0';
        p++;
    }
    lev = 0;
    if(*p == '.'){
        p++;
        while(*p >= '0' && *p <= '9'){
            t = t * 10 + *p - '0';
            p++;
            lev++;
        }
    }
    return t;
}

int main(){
    long long w,n,k,p,ans,pre,nex;
    double tmp;
    char s[10];
    while(scanf("%lld %s %lld",&n,&s,&k)!=EOF){
//        pre = n;
//        nex = k;
//        printf("%d.%02d\n",pre,nex);
//        continue;

        n+=2;

        w = read(s);
        //printf("---%lld\n",w);
        while(lev < 3){
            w *= 10;
            lev++;
        }

        ans = (n - n/k ) * w /2;

        while(lev>3){
            ans /=10;
            lev--;
        }

        ans = (ans + 5 )/10;

        pre = ans / 100;
        nex = ans % 100;

        printf("%lld.%02lld\n",pre,nex);
    }
    return 0;
}
