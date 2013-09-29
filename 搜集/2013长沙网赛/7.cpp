#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 110000
using namespace std;
typedef long long  LL;
const int N = 100005;

int oldArray[N];
int realArray[N];
int newArray[N];
int n;

int find(int pos){
    int _min = 0;
    int
}

int main() {
    bool ok;
    int i,j;
    int pos ,pre,p;
    while(~scanf("%d",&n)) {
        ok = false;
        for(i=1; i<=n; i++) {
            scanf("%d",&realArray[i]);
            if(!ok && i%3 &&  realArray[i] != -1) {
                ok = true;
                pos = i;
            }
        }
        for(i=1; i<=n; i++) {
            scanf("%d",&oldArray[i]);
        }
        pre = oldArray[1] + oldArray[2];
        for(i=3; i<=n; i+=3) {
            realArray[i] = oldArray[i-1] - pre;
            pre =  oldArray[i+1] - realArray[i];
        }

        if(!ok && n%3 == 1){
            ok = true;
            pos = n;
            realArray[pos] = oldArray[pos] - realArray[pos-1];
        }

        if()

        if(ok) {
            if(pos%3 == 1) {
                if(pos != 1) {
                    pre = realArray[pos] + realArray[pos-1] ;
                    for(i = pos -2; i>0; i--) {
                        realArray[i] = oldArray[i+1] - pre;
                        pre =  realArray[i+1] + realArray[i];
                    }

                    pre = realArray[pos] + realArray[pos-1] ;
                    for(i = pos +1; i<=n; i++) {
                        realArray[i] = oldArray[i-1] - pre;
                        pre =  realArray[i-1] + realArray[i];
                    }
                } else {
                    pre = realArray[pos] ;
                    for(i = pos +1; i<=n; i++) {
                        realArray[i] = oldArray[i-1] - pre;
                        pre =  realArray[i-1] + realArray[i];
                    }
                }

            } else if(pos %3 == 2) {
                if(pos != n) {
                    pre = realArray[pos] + realArray[pos +1] ;
                    for(i = pos -1; i>0; i--) {
                        realArray[i] = oldArray[i+1] - pre;
                        pre =  realArray[i+1] + realArray[i];
                    }

                    pre = realArray[pos] + realArray[pos+1] ;
                    for(i = pos +2; i<=n; i++) {
                        realArray[i] = oldArray[i-1] - pre;
                        pre =  realArray[i-1] + realArray[i];
                    }
                } else {
                    pre = realArray[pos] ;
                    for(i = pos -1; i>0; i--) {
                        realArray[i] = oldArray[i+1] - pre;
                        pre =  realArray[i+1] + realArray[i];
                    }
                }
            }
        }
        scanf("%d",&p);
        while(p--){
            scanf("%d",&pos);
            pos++;
            if(ok || pos%3 == 0){
                printf("%d\n",realArray[pos]);
            }else{
                printf("%d\n",find(pos));
            }

        }



    }

    return 0;
}
