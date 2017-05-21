#include"iostream"
using namespace std;
int main(){
    int N,sum=0,t,i,a[100];
    scanf("%d",&N);
    
    for(i=2;i<=N;i++){
        a[i-2]=i;
        sum+=i;
        if(sum>N){sum-=i;t=N-sum;break;}
    }
    int j=i-3;
    i=j;
    while(t){
        a[i]++;
        t--;
        i--;
        if(i<0)i=j;
    }
    for(i=0;i<j;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n",a[j]);
   // system("pause");
    return 0;
}
