#include"iostream"
#include"cstdlib"
using namespace std;
bool flag[60001];
int a[7];
int main(){
    int sum,c=1;
    while(scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6])){
       if(a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0 && a[6]==0)break;
       sum=1*a[1]+2*a[2]+3*a[3]+4*a[4]+5*a[5]+6*a[6];
       if(sum%2==1){
           printf("Collection #%d:\nCan't be divided.\n\n",c++);
       }
       else{
           memset(flag,false,sizeof(flag));
           flag[0]=true;
           bool fl=false;
           int max=0;
           for(int k=1;k<=6;k++){
              if(fl)break;
              if(a[k]>0){
                  for(int i=max;i>=0;i--){
                     if(fl)break;
                     if(flag[i]){
                       for(int j=1;j<=a[k];j++){
                           if(i+j*k==sum/2){fl=true;break;}
                           if(i+j*k>sum/2 || flag[i+j*k])break;
                           flag[i+j*k]=true;  
                       }
                     }
                  }
              if(max>=sum/2)max=sum/2;
              else max+=a[k]*k;
              }
           }
           if(fl)printf("Collection #%d:\nCan be divided.\n\n",c++);
           else printf("Collection #%d:\nCan't be divided.\n\n",c++);
       }
    }
    return 0;
}
