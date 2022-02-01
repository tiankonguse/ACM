#include"iostream"
#include"algorithm"
using namespace std;
int a[20001];
int main(){
    int N,B,s=0;
    scanf("%d%d",&N,&B);
    for(int i=0;i<N;i++){
       scanf("%d",a+i);
    }
    sort(a,a+N);
    for(int i=N-1;i>=0;i--){
       s+=a[i];
       if(s>=B){
           printf("%d\n",N-i);
           break;
       }
    }
    //system("pause");
    return 0;
}
