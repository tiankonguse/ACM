#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define eps 1e-7
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define CLR(a, b) memset(a, b, sizeof(a))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;

#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int maxn = 1100;

int a[maxn][maxn];
int n, m;

bool check()
{
    for(int i = 1; i < n; i ++)
    {
        for(int j = 0; j < m - 1; j ++)
        {
            if(a[i][j] - a[i][j+1] < a[i-1][j] - a[i-1][j+1]) return false;
        }
    }
    return true;
}

//bool check()
//{
//    for(int i = 1; i < n; i ++)
//    {
//        for(int j = 0; j < m; j ++)
//        {
//            for(int k = j +1; k < m; k ++)
//                if(a[i][j] - a[i][k] < a[i-1][j] - a[i-1][k]) return false;
//        }
//    }
//    return true;
//}
//inline int get_int(){
//    int ret=0;
//    char c;
//    while(!isdigit(c=getchar()));
//    do{
//        ret =(ret<<3)+(ret<<1)+c-'0';
//    }while(isdigit(c=getchar()));
//    return ret;
//}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int cnt = 0;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                scanf("%d", &a[i][j]);
//                a[i][j] = get_int();
        puts(check() ? "yes" : "no");
    }
}

