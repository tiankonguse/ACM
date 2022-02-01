#include"iostream"
using namespace std;
int a[7];
bool used[7];
int main(){
    int res,c2,c1;
    while(scanf("%d%d%d%d%d%d",a+1,a+2,a+3,a+4,a+5,a+6)){
          used[1]=used[2]=false;
          if(a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0 && a[6]==0)break;
          res=a[6]+a[5]+a[4]+(a[3]+3)/4;
       //   a[1]-=a[5]*11;if(a[1]<0)used[1]=true;
          if(a[3]%4==3){
             c2=1+a[4]*5;
             c1=5+a[5]*11;
          }
          else if(a[3]%4==2){
             c2=3+a[4]*5;
             c1=6+a[5]*11;
          }
          else if(a[3]%4==1){
             c2=5+a[4]*5;
             c1=7+a[5]*11;
          }
          else{
             c2=a[4]*5;
             c1=a[5]*11;
          }
          if(c2>=a[2]){
             c2-=a[2];
             c1+=c2*4;
             a[1]-=c1;
             if(a[1]>0)res+=(a[1]+35)/36;
          }
          else{
             a[2]-=c2;
             a[1]-=c1;
             if(a[1]>0)res+=(a[2]*4+a[1]+35)/36;
             else res+=(a[2]*4+35)/36;
          }
          printf("%d\n",res);
    }
    return 0;
}
