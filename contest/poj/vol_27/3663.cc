#include"iostream"
#include"algorithm"
using namespace std;
int main(){
    int N,S,a[20001];
    scanf("%d%d",&N,&S);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+N);
    int cnt=0,j;
    for(int i=0;i<N;i++){
       if(a[i]>S)break;
       for(j=i+1;j<N;j++){
           if(a[i]+a[j]>S){
              break;
           }
       }
       cnt+=j-i-1;
    }
    printf("%d\n",cnt);
   // system("pause");
    return 0;
}
