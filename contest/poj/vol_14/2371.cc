#include"iostream"
#include"algorithm"
using namespace std;
int a[100001];
int main(){
    int N,K,q;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%d",&a[i]);
    }
    sort(a,a+N);
    scanf("%*s");
    scanf("%d",&K);
    while(K--){
       scanf("%d",&q);
       printf("%d\n",a[q-1]);
    }
    //system("pause");
    return 0;
}
