#include"iostream"
using namespace std;
int main(){
    int a,k1,k2,k3,res;
    while(scanf("%d%d%d%d",&a,&k1,&k2,&k3)){
       if(a==0 && k1==0 && k2==0 && k3==0)break;
       res=80;
       res+=(a-k1+40)%40;
       res+=40;
       res+=(k2-k1+40)%40;
       res+=(k2-k3+40)%40;
       printf("%d\n",res*9);
    }
    return 0;
}
