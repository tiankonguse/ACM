#include"iostream"
using namespace std;
int M,a[10001];
bool check(int idx,int sum){
     int s=0;
     for(int i=idx;i<M;i++){
        s+=a[i];
        if(s>sum)return false;
        else if(s==sum)s=0;
     }
     if(s!=0)return false;
     else return true;
}
int main(){
    int T,p,sum;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
       scanf("%d%d",&p,&M);
       for(int j=0;j<M;j++){
          scanf("%d",&a[j]);
       }
       sum=0;
       for(int j=0;j<M;j++){
          sum+=a[j];
          if(check(j+1,sum)){
             printf("%d %d\n",p,sum);
             break;
          }
       }
    }
   // system("pause");
    return 0;
}
