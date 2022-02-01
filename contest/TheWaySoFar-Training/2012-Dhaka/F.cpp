#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

char str[300];
struct NUNU{
    int C[20][50];
}a[60];
const int N=17,M=43;

int mark[60];
char b[60];
int bo[60];

int check(int i,int n){
    for (int j=1; j<=N; ++j)
        for (int k=1; k<=M; ++k){
                if (a[i].C[j][k]!='*') continue;
                int num=0;
                for (int l=1; l<=n; ++l)
                    if (l!=i && bo[l] && a[l].C[j][k]=='*') ++num;
                if (num) continue;
                return 1;
            }
    return 0;
}

int main(){
   // freopen("1.txt","r",stdin);
    int n,q;
    scanf("%d%d",&n,&q);
    scanf("%s",str+1);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=N; ++j)
            for (int k=1; k<=M; ++k){
                int ch;
                while (ch=getchar(),ch!='*' && ch!='.');
                a[i].C[j][k]=ch;
            }

    int DD=0;
    for (;q;--q){
        scanf("%s",b+1);
        int m=strlen(b+1);
        memset(bo,0,sizeof(bo));
        for (int i=1; i<=m; ++i)
            for (int j=1; j<=n; ++j)
                if (str[j]==b[i]) bo[j]=1;
        printf("Query %d: ",++DD);
        for (int i=1; i<=m; ++i){
            int k=0;
            for (int j=1; j<=n; ++j)
                if (b[i]==str[j]) k=j;
            if (check(k,n)) putchar('Y');
            else putchar('N');
        }
        putchar('\n');
    }
}
