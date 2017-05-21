#include"iostream"
#include"cmath"
using namespace std;
int a[50];
int main(){
    int n,k=1,s,c;
    while(scanf("%d",&n)){
       if(n==0)break;
       s=0,c=0;
       printf("Set #%d\n",k++);
       for(int i=0;i<n;i++){
               scanf("%d",&a[i]);
               s+=a[i];
       }
       s/=n;
       for(int i=0;i<n;i++){
          c+=abs(s-a[i]);
       }
       printf("The minimum number of moves is %d.\n\n",c/2);
    }
    return 0;
}
