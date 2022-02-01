#include"iostream"
using namespace std;
int a[20],b[20];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int x,y,cnt,p1,p2,mp;
    while(scanf("%d%d",&x,&y)){
       if(x==0 && y==0)break;
       cnt=p1=p2=0;
       while(x){
          a[p1++]=x%10;
          x/=10;
       }
       while(y){
          b[p2++]=y%10;
          y/=10;
       }
       mp=max(p1,p2);
       int car=0;
       for(int i=0;i<mp;i++){
          if(a[i]+b[i]+car>9){
             car=1;
             cnt++;
          }
          else car=0;
       }
       if(cnt==0)printf("No carry operation.\n");
       else if(cnt==1)printf("1 carry operation.\n");
       else printf("%d carry operations.\n",cnt);
    }
    return 0;
}
