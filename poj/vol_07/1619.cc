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
#define maxn 300300
using namespace std;

const int MAXP=1000100;
int pri[MAXP],cnt;
int markp[MAXP];
int setp() {
    int i,j,m;
    cnt=1;pri[0]=2;markp[4]=2;
    for(i=3;i<MAXP;i++){
        if(!markp[i])pri[cnt++]=i;
        for(j=0;j<cnt,pri[j]*i<MAXP;j++){
            markp[i*pri[j]] = pri[j];
            if(!(i%pri[j]))break;
        }
    }
    return cnt;
}
int mark[MAXP];
bool used[MAXP];
int EKG[MAXP];
int mp[MAXP];

void init(){
    setp();
    memset(mark, 0, sizeof mark);
    EKG[1] = 1, EKG[2] = 2;
    mp[1] = 1, mp[2] = 2;
    used[0] = used[1] = used[2] = true;
    int t, p, r;
    for(int i=3;i<=1000000;i++){
        t = EKG[i - 1];
        r = inf;
        while(t != 1){
            if(markp[t] == 0) p = t;
            else p = markp[t];
            while(mark[p] <= 1000000 && used[ mark[p] ]) mark[p] += p;
            r = min(r, mark[p]);
            t /= p;
        }
        EKG[i] = r;
        //if(r > 1000000) cout << i << "," << r << endl;
        if(r <= 1000000){
            mp[r] = i;
            used[r] = true;
        }
    }
}
int main(){
    init();
    int n;
    while(~scanf("%d", &n) && n){
        printf("The number %d appears in location %d.\n", n, mp[n]);
    }
    return 0;
}
