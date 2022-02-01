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
using namespace std;
typedef long long LL;
typedef long long LL;
const int N=110000;
const int M=300000;
bool is[N];
int prm[M];


int prim[M];
int pcount;

int getprm() {
    int e = (int)(sqrt(0.0 + N) + 1),k=0,i;
    memset(is, 1, sizeof(is));
    prm[k++] = 2;
    is[0] = is[1] = 0;
    for (i = 4; i < N; i += 2) is[i] = 0;
    for(i=3; i<e; i+=2) {
        if(is[i]) {
            prm[k++]=i;
            for(int s=i+i,j=i*i; j<N; j+=s)is[j]=0;
        }
    }
    for (; i < N; i += 2)
        if (is[i])prm[k++] = i;
    return k;
}



LL myrongchi(int index,int a) {
    LL r=0,t;
    for(int i=index; i<pcount; i++) {
        t=a/prim[i];
        r+=t-myrongchi(i+1,t);
    }
    return r;
}



int main(int argc, char* argv[]) {
    int num =  getprm() ;
    LL s,x,y;
    int i;
    //printf("%d\n",num);
    scanf("%lld",&s);
    while(~scanf("%lld%lld%lld",&s,&x,&y)) {
        pcount = 0;
        for(i=0; i<num && s != 1; i++) {
            if(s%prm[i] == 0) {
                prim[pcount++] = prm[i];
                while(s%prim[i] == 0)s /= prim[i];
            }
        }
        if(pcount == 0) {
            printf("%lld\n",y-x+1);
        } else {
            printf("%lld\n",myrongchi(0,y) - myrongchi(0,x-1));
        }
    }

    return 0;
}
