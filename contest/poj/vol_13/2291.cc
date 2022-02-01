#include"algorithm"
#include"iostream"
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int a[1001];
int main(){
    int T,N,s,max;
    scanf("%d",&T);
    while(T--){
       scanf("%d",&N);
       for(int i=0;i<N;i++)scanf("%d",&a[i]);
       sort(a,a+N,cmp);
       max=0;
       for(int i=0;i<N;i++){
          s=(i+1)*a[i];
          if(s>max)max=s;
       }
       printf("%d\n",max);
    }
 //   system("pause");
    return 0;
}
