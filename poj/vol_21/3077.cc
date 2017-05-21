#include"iostream"
using namespace std;
int main(){
    int T,a,z;
    scanf("%d",&T);
    while(T--){
       scanf("%d",&a);
       z=0;
       while(a>10 && ++z){
          if(a%10>=5)a=a/10+1;
          else a/=10;
       }
       printf("%d",a);
       for(int i=0;i<z;i++)printf("0");
       printf("\n");
    }
    return 0;
}
