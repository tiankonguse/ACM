#include"iostream"
#define MAX 1000001
using namespace std;
int phi[MAX],pr[MAX];
__int64 res[MAX];
void init()
{
    int i,j;
    int pn=0;
    for(i=2;i<MAX;++i)
    {
        if(!phi[i])
        {
            pr[pn++]=i;
            phi[i]=i-1;
        }
        for(j=0;j<pn&&pr[j]*i<MAX;j++)
        {
            if(i%pr[j]==0)
            {
                phi[pr[j]*i]=phi[i]*pr[j];
                break;
            }
            else
                phi[pr[j]*i]=phi[i]*(pr[j]-1);
        }
    }
    res[2]=1;
    for(i=3;i<=MAX;i++){
       res[i]=res[i-1]+phi[i];
    }
}
int main(){
    int N;
    init();
    while(scanf("%d",&N)&&N){
       printf("%I64d\n",res[N]);
    }
  //  system("pause");
    return 0;
}
