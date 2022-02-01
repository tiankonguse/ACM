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
#define maxn 30
using namespace std;
bool mp[maxn][maxn];
int pos[maxn];
char s1[maxn], s2[maxn];
int num[maxn];
int pre[maxn];
int c[27][27];
void init(){
   for(int i=0;i<=26;i++){
       c[i][0]=1;
   }
   for(int i=1;i<=26;i++){
       for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
       }
   }
}
int main(){
    init();
    int n, m;
    char c1, c2;
    while(scanf("%d", &n) && n){
        scanf(" %s %s", s1, s2);
        m = strlen(s1);
        for(int i=0;i<m;i++){
            pos[ s2[i] - 'a' ] = i;
        }
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                c1 = s1[i] - 'a';
                c2 = s1[j] - 'a';
                mp[i][j] = (pos[c1] > pos[c2]);
            }
        }
        memset(num, 0, sizeof(num));
        for(int i=1;i<m;i++){
            for(int j=i-1;j>=0;j--){
                if(mp[j][i]){
                    pre[i] = j;
                    break;
                }
            }
            num[ pre[i] ]++;
        }
        int res = 1;
        for(int i=0;i<m;i++){
           // cout<<num[i]<<endl;
            res *= c[n][num[i]];
        }
        printf("%d\n", res);
    }
    return 0;
}
