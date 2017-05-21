#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
int const maxn = 1111;
typedef long long ll;
char str[maxn];
int a[maxn];
int b[maxn], n;
int m, mod;

void getBinary() {
	int len = strlen(str);
	for (int i = 0; i < len; ++i) a[len - i - 1] = str[i] - '0';
	--a[0];
	if (a[0] < 0) {
		a[0] = 9;
		for (int i = 1; i < len; ++i) {
			a[i]--;
			if (a[i] < 0) a[i] = 9;
			else break;
		}
	}
	bool zero;
	n = 0;
	while (1) {
		zero = true;
		for (int i = 0; i < len; ++i) {
			if (a[i] != 0) {
				zero = false;
				break;
			}
		}
		if (zero) break;
		b[n++] = a[0] % 2;
		int add = 0;
		for (int i = len - 1; i >= 0; --i) {
			int t = (add * 10 + a[i]) / 2;
			add = a[i] % 2;
			a[i] = t;
		}
	}
	
}
bool ok[32][32];

void init() {
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 32; ++j) {
			bool flag = true;
			int t = i | j;
			for (int z = 0; z < m - 1; ++z) {
				if ((t & 3) == 0) {
					flag = false;
					break;
				}
				t >>= 1;
			}
			t = i & j;
			for (int z = 0; z < m - 1; ++z) {
				if ((t & 3) == 3) {
					flag = false;
					break;
				}
				t >>= 1;
			}
			ok[i][j] = flag;
		}
	}	
}

struct matrix{
    int N;
    int mat[33][33];
    void init(int n){
        N = 1 << n;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (ok[i][j]) mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		}
    }
    matrix operator+(matrix B){
        matrix C;
        C.N=N;
        for(int i=0;i<N;i++){
            for(int j=0;j<B.N;j++){
                C.mat[i][j]=(mat[i][j]+B.mat[i][j])%mod;
            }
        }
        return C;
    }
    matrix operator *(matrix B){
        matrix C;
        C.N=N;
        memset(C.mat,0,sizeof(C.mat));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mat[i][j]){
                   for(int k=0;k<N;k++){
                       C.mat[i][k]=(C.mat[i][k]+mat[i][j]*B.mat[j][k])%mod;
                   }
                }
            }
        }
        return C;
    }
    matrix powMod(){
        matrix C;
        C.N=N;
        memset(C.mat,0,sizeof(C.mat));
        for(int i=0;i<N;i++)C.mat[i][i]=1;
		for (int i = 0; i < n; ++i) {
			if (b[i]) C = C * (*this);
			*this = (*this) * (*this);
		}
        return C;
    }
    void print(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j == N - 1) cout<<mat[i][j]<<endl;
                else cout<<mat[i][j]<<" ";
            }
        }
    }
}A,B,C;

int main() {
	int T;
	scanf(" %s %d %d", str, &m, &mod);
	init();
	getBinary();
	A.init(m);
	B = A.powMod();
	int ret = 0;
	for (int i = 0; i < (1 << m); ++i) {
		for (int j = 0; j < (1 << m); ++j) {
			ret += B.mat[i][j];
		}
	}
	printf("%d\n", ret % mod);
	return 0;
}

