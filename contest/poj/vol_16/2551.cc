#include"cstdio"
using namespace std;
int main(){
    int n,cnt,d,m;
    while(~scanf("%d",&n)){
         d=cnt=1;
         while(d){
               d=(d*10+1)%n;
               cnt++;
         }
         printf("%d\n",cnt);
    }
    return 0;
}
