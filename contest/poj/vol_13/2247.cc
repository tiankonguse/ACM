#include"iostream"
#define Min(a,b) (a<b?a:b)
using namespace std;
int main(){
    int hum[5843]={0,1};
    int cnt2=1,cnt3=1,cnt5=1,cnt7=1;
    for(int i=2;i<=5842;i++){
         hum[i]=Min(hum[cnt2]*2,Min(hum[cnt3]*3,Min(hum[cnt5]*5,hum[cnt7]*7)));
         if(hum[i]==hum[cnt2]*2)cnt2++;
         if(hum[i]==hum[cnt3]*3)cnt3++;
         if(hum[i]==hum[cnt5]*5)cnt5++;
         if(hum[i]==hum[cnt7]*7)cnt7++;
    }
    int n;
    while(scanf("%d",&n)&&n){
       if(n%10==1 && n%100!=11)printf("The %dst humble number is %d.\n",n,hum[n]);
       else if(n%10==2 && n%100!=12)printf("The %dnd humble number is %d.\n",n,hum[n]);
       else if(n%10==3 && n%100!=13)printf("The %drd humble number is %d.\n",n,hum[n]);
       else printf("The %dth humble number is %d.\n",n,hum[n]);
    }
    return 0;
}
