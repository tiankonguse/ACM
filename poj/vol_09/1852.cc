#include"iostream"
using namespace std;
int main(){
    int T,L,N,a,d,mx,mn;
    scanf("%d",&T);
    while(T--){
       mx=mn=0;
       scanf("%d%d",&L,&N);
       while(N--){
          scanf("%d",&a);
          d=min(a,L-a);
          if(d>mn)mn=d;
          if(a>mx)mx=a;
          if(L-a>mx)mx=L-a;
       }
       printf("%d %d\n",mn,mx);
    }
  //  system("pause");
    return 0;
}
