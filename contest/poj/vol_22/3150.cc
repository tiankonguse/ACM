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
#define maxn 505
using namespace std;
typedef __int64 ll;
int mod = 1000000007;
struct matrix{
    int n;
    ll mat[maxn];
    void init(){
        for(int i=0;i<n;i++) scanf("%I64d", &mat[i]);
    }
    matrix operator*(matrix B){
        matrix C;
        C.n = n;
        for(int i=0;i<n;i++){
            C.mat[i] = 0;
            for(int j=0;j<n;j++){
                if(i - j >= 0) C.mat[i] += mat[j] * B.mat[i - j];
                else C.mat[i] += mat[j] * B.mat[i - j + n];
            }
            C.mat[i] %= mod;
        }
        return C;
    }
    matrix operator^(int m){
        matrix C;
        C.n = n;
        memset(C.mat, 0, sizeof(C.mat));
        C.mat[0] = 1;
        while(m){
            if(m & 1) C = C * (*this);
            *this = (*this) * (*this);
            m >>= 1;
        }
        return C;
    }
    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[(i - j + n) % n]<<" ";
            }
            cout<<endl;
        }
    }
}A, B, C;
int main(){
    int n, d, k;
    while(~scanf("%d%d%d%d", &n, &mod, &d, &k)){
        A.n = n; A.init();
        B.n = n;
        memset(B.mat, 0, sizeof(B.mat));
        for(int i=0;i<=d;i++){
            B.mat[i] = B.mat[(n - i) % n] = 1;
        }
        C = A * (B ^ k);
        for(int i=0;i<n;i++){
            if(i == n - 1) printf("%I64d\n", C.mat[i]);
            else printf("%I64d ", C.mat[i]);
        }
    }
    return 0;
}
