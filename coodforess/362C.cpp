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
#define eps 1e-7
using namespace std;
typedef long long LL;

int str[maxn];

int main(){
    int i,j,k;
    int n;
    int tmp,cnt;
    while(cin>>n){
        for(i=0;i<n;i++){
            cin>>str[i];
        }
        tmp=-1,cnt=0;

        int ans = 0;
        for(i=0;i<n;i++){
            ans += abs(str[i]-i);
        }
//      printf("%d\n",ans);
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                if(abs(str[i]-i)-abs(str[i]-j)+abs(str[j]-j)-abs(str[j]-i)>tmp){
                    tmp = abs(str[i]-i)-abs(str[i]-j)+abs(str[j]-j)-abs(str[j]-i);
                    cnt=1;
                }else if(abs(str[i]-i)-abs(str[i]-j)+abs(str[j]-j)-abs(str[j]-i)==tmp){
                    cnt++;
                }
            }
        }

        tmp = (ans-tmp)>>1;

        printf("%d %d\n",tmp,cnt);
    }
    return 0;
}
