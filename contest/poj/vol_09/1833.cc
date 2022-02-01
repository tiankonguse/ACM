#include"iostream"
#include"algorithm"
using namespace std;
int main(){
    int m,n,k,a[1025];
    scanf("%d",&m);
    while(m--){
       scanf("%d%d",&n,&k);
       for(int i=0;i<n;i++){
           scanf("%d",&a[i]);
       }
       while(k--){
          next_permutation(a,a+n);
       }
       for(int i=0;i<n;i++){
         if(i==n-1)printf("%d\n",a[i]);
         else printf("%d ",a[i]);
       }
    }
   // system("pause");
    return 0;
}
