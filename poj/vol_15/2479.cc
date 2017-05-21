#include"iostream"
#include"cstdlib"
using namespace std;
int a[50001],b[50001],num[50001];  
int main(){
    int M=2,N,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        num[0]=0;
        for(int i=1;i<=N;i++)scanf("%d",&num[i]);
        memset(a,0,(N+1)*sizeof(a[0]));
        memset(b,0,(N+1)*sizeof(b[0]));
        int max;
        for(int i=1;i<=M;i++){
           max=0x80000000;
           for(int j=i;j<=N;j++){
               if(a[j-1]<b[j-1])a[j]=b[j-1]+num[j];
               else a[j]=a[j-1]+num[j];
               b[j-1]=max;
               if(a[j]>max)max=a[j];
           }
           b[N]=max;
        }
        printf("%d\n",max);
    }
    return 0;
}
