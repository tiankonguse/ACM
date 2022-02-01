#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 100700
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

int main(){
    freopen("Magic_Trianglein.txt","w",stdout);
    printf("6\n");
    int cas=6;
    while(cas--){
        int k = 0;
        printf("2000 100000\n");
        for(int i=1;i<=50000;i+=10){
            printf("%d\n",i);
            k++;
            if(k==2000)break;
        }
        for(int i=0;i<100000;i++){
            printf("%d\n",i);
        }
    }
    return 0;
}
