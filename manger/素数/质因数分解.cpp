#include <iostream>
using namespace std;


//分解质因数
//prime_factor()传入n, 返回不同质因数的个数
//f存放质因数，nf存放对应质因数的个数

//筛法产生素数表  
#include <cmath>
#define MAXN  1000000    // MAXN为最大范围
#define pMaxCount 100000 //素数表最大容量,可根据maxn做调整
int  pCount; //MAXN以内的素数个数,大概28万多个
bool prime_hash[MAXN+1];
int  plist[pMaxCount]; //素数表,从小标0开始存 

inline void init_prime()
{
    int i, j, idx, max = (int)sqrt(MAXN*1.0);

    //prime_hash[i] = true,(i>=2)表示i为素数
    memset(prime_hash,true,sizeof(prime_hash));
    
    for(i = 2 ; i <= max; ++i) {
        if(prime_hash[i])
            for(j = i*i; j <= MAXN; j += i)
                prime_hash[j] = false;
    }

    //将素有素数保存在plist中
    for(idx = 0, i = 2; i <= MAXN; ++i) { 
        if(prime_hash[i] == true) {
            plist[idx] = i; ++idx;
        }
    }
    pCount = idx;
	printf("%d\n", pCount);
}

int prime_factor(int n, int* f, int *nf) {
    int cnt = 0;
    int n2 = sqrt((double)n);
    for(int i = 0; n > 1 && plist[i] <= n2; ++i)
        if (n % plist[i] == 0) {            
            for (nf[cnt] = 0; n % plist[i] == 0; ++nf[cnt], n /= plist[i]);
            f[cnt++] = plist[i];
        }
    if (n > 1) nf[cnt] = 1, f[cnt++] = n;
    return cnt;
}


int main()
{
	int f[100];
	int nf[100];
	
	init_prime();
	int n = prime_factor(10250, f, nf);
	for (int i = 0; i < n; ++i) {
		cout<<f[i]<<" "<<nf[i]<<endl;
	}

	return 0;
}