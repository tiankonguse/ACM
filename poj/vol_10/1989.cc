#include"iostream"
#include"cstdlib"
using namespace std;
bool used[10001];
int main(){
    int N,K,a,cnt,c=0;
    scanf("%d%d",&N,&K);
    cnt=0;
    for(int i=0;i<N;i++){
       scanf("%d",&a);
       if(!used[a]){
          cnt++;
          used[a]=true;
       }
       if(cnt==K){
           c++;
           cnt=0;
           memset(used,false,sizeof(used));
       }
    }
    printf("%d\n",c+1);
    //system("pause");
    return 0;
}
