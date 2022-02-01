#include"cstdio"
#include"cmath"
using namespace std;
int main(){
    int N,x,s,rx,ry;
    while(~scanf("%d",&N)){
        x=(int)sqrt(N*2.0);
        s=x*(x+1)/2;
        while(s<N){
           x++;
           s+=x;
        }
        rx=s-N;
        ry=x-rx;
        rx++;
        if(x&1)printf("TERM %d IS %d/%d\n",N,rx,ry);
        else printf("TERM %d IS %d/%d\n",N,ry,rx);
    }
    return 0;
}
