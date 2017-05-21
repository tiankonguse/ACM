#include <iostream>
#define MAX(a,b) (a>b?a:b)
using namespace std;

int a[351][351];
int main()
{
    int N;
   // freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
       for(int j=0;j<=i;j++){
            scanf("%d",&a[i][j]);
       }
    }
    for(int i=N-2;i>=0;i--){
        for(int j=0;j<=N-2;j++){
           a[i][j]+=MAX(a[i+1][j],a[i+1][j+1]);
        }
    }
    printf("%d\n",a[0][0]);
    return 0;
}
