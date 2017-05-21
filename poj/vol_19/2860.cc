#include"iostream"
using namespace std;
int main(){
    int a[11],b[11];
    int N,M,K,res;
    while(~scanf("%d%d%d",&N,&M,&K)){
       res=0;
       for(int i=0;i<K;i++)scanf("%d",&a[i]);
       for(int i=0;i<K;i++)scanf("%d",&b[i]);
       for(int i=0;i<K;i++){
          if(a[i]<b[i])res+=b[i]-a[i];
       }
       printf("%d\n",res);
    }
    return 0;
}
