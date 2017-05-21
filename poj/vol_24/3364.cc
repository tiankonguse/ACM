#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int main(){
    int n,m,c;
    while(~scanf("%d%d%d",&n,&m,&c)){
        if(n==0 && m==0 && c==0)break;
        int res=(n-7)*(m-7);
        if(res%2==0)printf("%d\n",res/2);
        else printf("%d\n",res/2+c);
    }
    return 0;
}
