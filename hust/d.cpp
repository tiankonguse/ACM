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




int main(int argc, char* argv[]) {
    int a,t;
    while(~scanf("%d",&a)){
        if(a == 21){
            puts("1");
            continue;
        }

        if(a < 30){
            puts("-1");
            continue;
        }

        t = a % 14;
        if(t >= 2 && t <= 12){
            printf("%d\n",a/14);
        }else{
            printf("-1\n");
        }
    }

    return 0;
}






