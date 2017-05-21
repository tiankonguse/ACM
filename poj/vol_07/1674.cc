#include"iostream"
#include"cstdlib"
using namespace std;
int a[10001];
bool used[10001];
int main(){
    int T,N,p,cnt;
    scanf("%d",&T);
    while(T--){
       memset(used,false,sizeof(used));
       cnt=0;
       scanf("%d",&N);
       for(int i=1;i<=N;i++)scanf("%d",&a[i]);
       for(int i=1;i<=N;i++){
           if(used[i])continue;
           used[i]=true;
           p=a[i];
           while(p!=i){
              used[p]=true;
              p=a[p];
              cnt++;
           }
       }
       printf("%d\n",cnt);
    }
   // system("pause");
    return 0;
}
