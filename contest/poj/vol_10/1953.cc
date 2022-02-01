#include"iostream"
using namespace std;
int a[45]={1,2};
int main(){
    int n,m;
    for(int i=2;i<45;i++){
       a[i]=a[i-2]+a[i-1];
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
       scanf("%d",&m);
       printf("Scenario #%d:\n%d\n\n",i,a[m]);
    }
    return 0;
}
