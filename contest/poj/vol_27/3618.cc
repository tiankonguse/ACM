#include"iostream"
#include"algorithm"
using namespace std;
int ab(int x){
    return x>0?x:-x;
}
int cmp(int a,int b){
   return ab(a)<ab(b);
}
int num[50001];
int main(){
    int now,T,N,cnt;
    scanf("%d%d",&T,&N);
    for(int i=0;i<N;i++){
       scanf("%d",&num[i]);
    }
    cnt=now=0;
    sort(num,num+N,cmp);
    for(int i=0;i<N;i++){
         cnt+=ab(num[i]-now);
         if(cnt>T){
            printf("%d\n",i);
            break;
         }
         now=num[i];
    }
    if(cnt<=T)printf("%d\n",N);
 //   system("pause");
    return 0;
}
