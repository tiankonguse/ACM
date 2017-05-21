#include"iostream"
using namespace std;
char str[15];
int main(){
    int T,N,a,s;
    while(scanf("%d%d",&T,&N)&&T){
       s=0;
       while(T--){
          scanf(" %s %d",str,&a);
          s+=a;
       }
       printf("%d\n",N*3-s);
    }
    return 0;
}
