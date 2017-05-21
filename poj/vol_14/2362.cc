#include"iostream"
#include"algorithm"
#include"cstdlib"
using namespace std;
int a[21],N,len;
bool used[21],flag;
int cmp(int a,int b){
  return a>b;
}
void dfs(int next,int s,int d){
   if(d==4){
            flag=true;
            return;
   }
   int pre=-1;
   for(int i=next;i<N;i++){
      if(!used[i] && a[i]!=pre && s+a[i]<=len){
          pre=a[i];
          used[i]=true;
          s+=a[i];
          if(s==len)dfs(0,0,d+1);
          else dfs(i+1,s,d);
          s-=a[i];
          used[i]=false;
          if(next==0 || flag)return;
      }
   }
}
int main(){
    int T,sum;
    scanf("%d",&T);
    while(T--){
       sum=0;
       scanf("%d",&N);
       for(int i=0;i<N;i++){
          scanf("%d",&a[i]);
          sum+=a[i];
       }
       if(sum%4!=0)printf("no\n");
       else{
          len=sum/4;
          sort(a,a+N,cmp);
          if(a[0]>len)printf("no\n");
          else{
            memset(used,false,sizeof(used));
            flag=false;
            dfs(0,0,0);
            if(flag)printf("yes\n");
            else printf("no\n");
          }
       }
    }
  //  system("pause");
    return 0;
}
