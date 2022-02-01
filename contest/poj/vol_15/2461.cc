#include"iostream"
using namespace std;
short a[100000];
int main(){
    int N;
    while(cin>>N){
                  if(N==0)break;
                  else if(N==2)printf("Impossible\n");
                  else{
                    for(int i=1;i<N;i++){
                            a[i]=1;
                    }
                    for(__int64 i=1;i<=N/2;i++){
                            a[i*i%N]=0;
                    } 
                    for(int i=1;i<N;i++){
                            printf("%d",a[i]);
                    }      
                    printf("\n");
                  }
    }
    return 0;
}
