#include"iostream"
using namespace std;
int a[5000],b[5000];
int lds(int n){
   b[0]=1;
   int maxn=1,max;
   for(int i=1;i<n;i++){
      max=0;
      for(int j=0;j<i;j++){
         if(a[j]>a[i] && b[j]>max)max=b[j];
      }
      b[i]=max+1;
      if(b[i]>maxn)maxn=b[i];
   }
   return maxn;
}
int main(){
    int t,k=0,c=1;
    bool flag=false;
    while(scanf("%d",&t)!=EOF){
       if(t==-1){
          if(flag)break;
          flag=true;
          if(c!=1)printf("\n");
          printf("Test #%d:\n  maximum possible interceptions: %d\n",c++,lds(k));
          k=0;
       }
       else{
          flag=false;
          a[k++]=t;
       }
    }
    return 0;
}
