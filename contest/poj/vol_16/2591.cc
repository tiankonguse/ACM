#include"iostream"
#define Min(a,b) (a<b?a:b)
using namespace std;
int S[10000001]={0,1};
int main(){
    int N;
    int cnt2=1,cnt3=1;
    for(int i=2;i<=10000000;i++){
        S[i]=Min(2*S[cnt2]+1,3*S[cnt3]+1);
        if(S[i]==2*S[cnt2]+1)cnt2++;
        if(S[i]==3*S[cnt3]+1)cnt3++;
    }
    while(scanf("%d",&N)!=EOF){
      printf("%d\n",S[N]);
    }
    return 0;
}
