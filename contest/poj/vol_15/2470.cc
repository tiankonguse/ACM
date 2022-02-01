#include"iostream"
using namespace std;
int a[100001];
int main(){
    int N,i;
    while(scanf("%d",&N)&&N){
         for(i=1;i<=N;i++)scanf("%d",&a[i]);
         for(i=1;i<=N;i++){
             if(a[a[i]]!=i){
                  printf("not ambiguous\n");
                  break;
             }
         }
         if(i>N)printf("ambiguous\n");
    }
    return 0;
}
