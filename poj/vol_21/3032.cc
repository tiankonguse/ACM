#include"iostream"
#include"queue"
using namespace std;
queue<int>q;
int res[20];
int main(){
    int T,N,d;
    scanf("%d",&T);
    while(T--){
         while(!q.empty())q.pop();
         scanf("%d",&N);
         q.push(N);
         for(int i=N-1;i>=1;i--){
             q.push(i);
             for(int j=1;j<=i;j++){
                d=q.front();
                q.pop();
                q.push(d);
             }
         }
         for(int i=0;i<N;i++){
             res[N-i]=q.front();
             q.pop();
         }
         for(int i=1;i<N;i++){
            printf("%d ",res[i]);
         }
         printf("%d\n",res[N]);
    }
    return 0;
}
