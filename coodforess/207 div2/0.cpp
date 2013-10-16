#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;

int str[111];
int main(int argc, char* argv[]) {
    int n,sum,i,x,y,first,second,ans = 0;
    while(~scanf("%d",&n)){
        sum = 0;
        ans = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&str[i]);
            sum += str[i];
        }
        scanf("%d%d",&x,&y);
        first = 0 ;
        for(int i=1;i<=n;i++){
            first += str[i];
            second = sum - first;
            if(first >= x && first <= y && second >= x && second <= y){
                ans = i+1;
                break;
            }
        }
        printf("%d\n",ans);

    }


    return 0;
}






