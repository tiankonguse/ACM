#include"iostream"
using namespace std;
int disk[40],cnt[2];
int ab(int a){
   return a>0?a:-a;
}
int main(){
    int T,N,a;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        cnt[0]=cnt[1]=0;
        for(int i=0;i<N;i++){
            scanf("%d",&a);
            cnt[i%2]+=a;
        }
        if(N%2==1)printf("YES\n");
        else{
            if(ab(cnt[0]-cnt[1])<=1)printf("YES\n");
            else printf("NO\n");
        }
    }
  //  system("pause");
    return 0;
}
