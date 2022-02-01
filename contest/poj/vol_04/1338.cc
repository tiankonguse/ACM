#include"iostream"
#define Min(a,b) (a<b?a:b)
using namespace std;
int main(){
    int ugly[1501]={0,1};
    int cnt2=1,cnt3=1,cnt5=1;
    for(int i=2;i<=1500;i++){
       ugly[i]=Min(ugly[cnt2]*2,Min(ugly[cnt3]*3,ugly[cnt5]*5));
       if(ugly[i]==ugly[cnt2]*2)cnt2++;
       if(ugly[i]==ugly[cnt3]*3)cnt3++;
       if(ugly[i]==ugly[cnt5]*5)cnt5++;
    }
    int n;
    while(scanf("%d",&n)&&n){
       printf("%d\n",ugly[n]);
    }
    
    return 0;
}
