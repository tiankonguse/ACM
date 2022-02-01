#include"iostream"
#include"algorithm"
using namespace std;
bool used[101][101];
int sum[101];
int main(){
    //freopen("1001in.txt","r",stdin);
    //freopen("1001out.txt","w",stdout);
    int P,T,a,b;
    memset(used,false,sizeof(used));
    memset(sum,0,sizeof(sum));
    scanf("%d%d",&P,&T);
    while(scanf("%d%d",&a,&b)!=EOF){
       if(!used[a][b]){
          used[a][b]=true;
          sum[a-1]+=b*b*b;
       }
    }
    sort(sum,sum+P);
    int ans=0;
    for(int i=0,tmp=-1;i<P;i++){
       if(sum[i]>tmp){
         tmp=sum[i];
         ans++;
       }
    }
    printf("%d\n",ans);
    return 0;
}
