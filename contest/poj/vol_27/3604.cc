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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
typedef __int64 ll;
const int MAXP=5000000;
ll pri[MAXP],cnt;
bool mark[MAXP];
int setp() {
    int i,j,m;
    cnt=1;pri[0]=2;mark[4]=1;
    for(i=3;i<MAXP;i+=2){
        if(!mark[i])pri[cnt++]=i;
        for(j=0;j<cnt,pri[j]*i<MAXP;j++){
            mark[i*pri[j]]=1;
            if(!(i%pri[j]))break;
        }
    }
    return cnt;
}

typedef __int64 ll;
inline ll tris(ll n){ return n * n * (n + 1) * (n + 1) / 4;}
ll dsum(ll x){
    ll res = 1LL;
    ll cnt;
    for(int i=0;pri[i]*pri[i]<=x;i++){
        if(x % pri[i] == 0){
            cnt = 1;
            while(x % pri[i] == 0){
                cnt++;
                x /= pri[i];
            }
            res *= tris(cnt);
        }
    }
    if(x != 1) res *= 9LL;
    return res;
}
int main(){
    setp();
    int Q; ll a;
    for(scanf("%d", &Q);Q--;){
        scanf("%I64d", &a);
        printf("%I64d\n", dsum(a) );
    }
    return 0;
}
