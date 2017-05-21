#include"iostream"
#include"algorithm"
using namespace std;
int a[20001];
int main(){
    int T,N,sum;
    scanf("%d",&T);
    while(T--){
       scanf("%d",&N);
       for(int i=0;i<N;i++){
          scanf("%d",a+i);
       }
       sort(a,a+N);
       sum=0;
       for(int i=N-3;i>=0;i-=3){
         sum+=a[i];
       } 
       printf("%d\n",sum);
    }
    //system("pause");
    return 0;
}
