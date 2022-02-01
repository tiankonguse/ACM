#include"iostream"
using namespace std;
int dist[10001];
int main(){
    int N,a,b,t,time=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&dist[i],&a);
        t=dist[i];
        for(int j=0;j<a;j++){
           scanf("%d",&b);
           b--;
           if(dist[i]<dist[b]+t)dist[i]=dist[b]+t;
        }
        if(time<dist[i])time=dist[i];
       // printf("dist[%d]=%d\n",i,dist[i]);
    }
    printf("%d\n",time);
   //system("pause");
    return 0;
}
