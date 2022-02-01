#include"iostream"
#include"cstdlib"
#define inf 0x3f3f3f3f
using namespace std;
int map[21][21];
int main(){
    int n,a,b,c=1;
    while(~scanf("%d",&n)){
        for(int i=1;i<=20;i++){
           for(int j=1;j<=20;j++){
              map[i][j]=inf;
           }
        }
        for(int i=0;i<n;i++){
          scanf("%d",&a);
          map[a][1]=map[1][a]=1;
        }
        for(int i=2;i<=19;i++){
           scanf("%d",&n);
           for(int j=0;j<n;j++){
              scanf("%d",&a);
              map[i][a]=map[a][i]=1;
           }
        }
        //floyd
        for(int k=1;k<=20;k++){
           for(int i=1;i<=20;i++){
              for(int j=1;j<=20;j++){
                  if(map[i][k]+map[k][j]<map[i][j]){
                     map[i][j]=map[i][k]+map[k][j];
                  }
              }
           }
        }
        printf("Test Set #%d\n",c++);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
           scanf("%d%d",&a,&b);
           printf("%d to %d: %d\n",a,b,map[a][b]);
        }
        printf("\n");
    }
    return 0;
}
