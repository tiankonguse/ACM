#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1000005
using namespace std;
int mark[MAXN];
int main(){
    int N;
    while(~scanf("%d",&N)){
        memset(mark,0xff,sizeof(mark));
        mark[N]=0;
        for(int i=1;;i++){
            N=(N/10)%10000;
            N=N*N%1000000;
            if(mark[N]!=-1){
                printf("%d %d %d\n",N,i-mark[N],i);
                break;
            }
            mark[N]=i;
        }
    }
    return 0;
}
