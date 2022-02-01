#include"iostream"
#include"string.h"
using namespace std;
int E[101][101],a[101][101],b[101][101];
int ME,NE,M,N;
void mul(){
    for(int i=0;i<ME;i++){
        for(int j=0;j<N;j++){
            b[i][j]=0;
            for(int k=0;k<NE;k++){
               b[i][j]+=E[i][k]*a[k][j];
            }
        }
    }
    NE=N;
    for(int i=0;i<ME;i++){
        for(int j=0;j<NE;j++){
            E[i][j]=b[i][j];
        }
    }
}
int main(){
    int T,X;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&X);
        scanf("%d%d",&ME,&NE);
        for(int i=0;i<ME;i++){
           for(int j=0;j<NE;j++){
               scanf("%d",&E[i][j]);
           }
        }
        for(int i=1;i<X;i++){
           scanf("%d%d",&M,&N);
           for(int j=0;j<M;j++){
              for(int k=0;k<N;k++){
                 scanf("%d",&a[j][k]);
              }
           }
           mul();
        }
        for(int i=0;i<ME;i++){
           for(int j=0;j<NE;j++){
              if(j==NE-1)printf("%d\n",E[i][j]);
              else printf("%d ",E[i][j]);
           }
        }
        printf("\n");
    }
    //system("pause");
    return 0;
}
