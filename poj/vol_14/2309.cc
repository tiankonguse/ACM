#include"iostream"
using namespace std;
int main(){
    int T,n,d;
    scanf("%d",&T);
    while(T--){
       scanf("%d",&n);
       d=n&-n;
       printf("%d %d\n",n-d+1,n+d-1);
    }
    return 0;
}
