#include"iostream"
#include"algorithm"
using namespace std;
int a[11];
int main(){
    int T,p;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
       scanf("%d",&p);
       for(int j=0;j<10;j++){
           scanf("%d",a+j);
       }
       sort(a,a+10);
       printf("%d %d\n",p,a[7]);
    }
  //  system("pause");
    return 0;
}
