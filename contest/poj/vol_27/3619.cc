#include"iostream"
using namespace std;
int main(){
    int N,K,s,t,r;
    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++){
       scanf("%d%d%d",&s,&t,&r);
       int a=N/(s*t)*(t+r)+N%(s*t)/s;
       if(N%(s*t)==0)a-=r;
       else if(N%(s*t)%s!=0)a++;
       printf("%d\n",a);
    }
    return 0;
}
