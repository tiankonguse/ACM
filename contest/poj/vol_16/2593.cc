#include"iostream"
#include"cstdlib"
using namespace std;
int a[100001],b[100001],num[100001];  
int main(){
    int M=2,N;
    while(scanf("%d",&N)&&N){
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
