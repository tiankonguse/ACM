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
#define maxn 500050
using namespace std;

bool notp[maxn];
__int64 pr[maxn];
int pn;
int divnum[maxn];
char e[maxn];

void getdivnum(){
  memset(notp,0,sizeof(notp));
	for(int i=2;i<maxn;i++){
  		if(!notp[i]){
			pr[pn++]=i;
			e[i]=1;
			divnum[i]=2;
		}
		for(int j=0;j<pn && i*pr[j]<maxn;j++){
			int k=i*pr[j];
			notp[k]=1;
			if(i%pr[j]==0){
				divnum[k]=divnum[i]/(e[i]+1)*(e[i]+2);
				e[k]=e[i]+1;
				break;
			}
			else{
				divnum[k]=divnum[i]*divnum[pr[j]];
				e[k]=1;
			}
		}
	}
}
struct BinaryIndexTree{
    int num[maxn];
    void init(){
        memset(num, 0, sizeof(num));
    }
    inline int lowbit(int x){ return x & -x;}
    void update(int p, int c){
        while(p < maxn){
            num[p] += c;
            p += lowbit(p);
        }
    }
    int query(int p){
        int t = 0;
        while(p > 0){
            t += num[p];
            p -= lowbit(p);
        }
        return t;
    }
    int findkth(int k){
        int now = 0;
        for(int i=20;i>=0;i--){
            now |= (1 << i);
            if(now >= maxn || num[now] >= k){
                now ^= (1 << i);
            }
            else k -= num[now];
        }
        return now + 1;
    }
}bit;
char str[maxn][15];
int next[maxn];
int main(){
	getdivnum();
	int n, k;
	while(~scanf("%d%d", &n, &k)){
        bit.init();
        for(int i=1;i<=n;i++){
            scanf(" %s %d", str[i], &next[i]);
            bit.update(i, 1);
        }
        int res, rm = -1, a, p = k;
        for(int i=1;i<=n;i++){
            if(divnum[i] > rm){
                rm = divnum[i];
                res = p;
            }
            if(i == n) break;
            bit.update(p, -1);
           // s = n - i;
            a = next[p];
            if(a > 0){
                k = k - 1 + a;
                if(k > n - i){
                     k %= (n - i);
                     if(k == 0) k = n - i;
                }
            }
            else{
                k = k + a;
                if(k <= 0){
                    k = (k % (n - i) + (n - i)) % (n - i);
                    if(k == 0) k = n - i;
                }
            }
            //cout<<k<<endl;
            p = bit.findkth(k);
            //cout<<"find k = "<< p <<endl;
            //system("pause");
        }
        printf("%s %d\n", str[res], rm);
	}
    return 0;
}
