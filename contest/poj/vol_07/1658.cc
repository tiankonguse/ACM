#include"iostream"
using namespace std;
int main(){
    int N,a[4];
    scanf("%d",&N);
    while(N--){
        for(int i=0;i<4;i++){
          scanf("%d",&a[i]);
        }
        for(int i=0;i<4;i++)printf("%d ",a[i]);
        if(a[1]-a[0]==a[2]-a[1] && a[2]-a[1]==a[3]-a[2])printf("%d\n",a[3]+a[3]-a[2]);
        else printf("%d\n",a[3]*a[3]/a[2]);
    }
    return 0;
}
