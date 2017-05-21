#include"iostream"
using namespace std;
int a[14];
int main(){
    int c=0,N;
    while(scanf("%d",&N)&&N){
        if(c)printf("\n");
        c=1;
        for(int i=0;i<N;i++)scanf("%d",a+i);
        for(int i=0;i<N-5;i++){
           for(int j=i+1;j<N-4;j++){
              for(int k=j+1;k<N-3;k++){
                  for(int l=k+1;l<N-2;l++){
                      for(int m=l+1;m<N-1;m++){
                         for(int s=m+1;s<N;s++){
                           printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],a[l],a[m],a[s]);
                         }
                      }
                  }
              }
           }
        }
    }
    return 0;
}
