#include"iostream"
#include"set"
using namespace std;
int dat[1001];
int find(int x){
   int low=0,high=1000,mid;
   while(low<=high){
      mid=(low+high)>>1;
      if(x>dat[mid])low=mid+1;
      else high=mid-1;
   }
   return low;
}
int main(){
    for(int i=0;i<=1000;i++){
      dat[i]=1+3*i*(i+1);
    }
    int n,d,s,x,y;
    while(~scanf("%d",&n)){
        d=find(n);
        if(d==0)printf("0 0\n");
        else{
           s=(n-dat[d-1]-1)/d;
           if(s==0){
              y=n-dat[d-1];
              x=d-y;
           }
           else if(s==1){
              y=d;
              x=dat[d-1]-n+d;
           }
           else if(s==2){
              x=-d;
              y=d*3+dat[d-1]-n;
           }
           else if(s==3){
              y=d*3+dat[d-1]-n;
              x=-d-y;
           }
           else if(s==4){
              y=-d;
              x=n-d*4-dat[d-1];
           }
           else if(s==5){
              x=d;
              y=n-dat[d];
           }
            printf("%d %d\n",x,y);
        }  
    }
    //system("pause");
    return 0;
}
