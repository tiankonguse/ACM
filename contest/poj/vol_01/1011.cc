#include"iostream"
#include"algorithm"
#define MAX 64
using namespace std;
int S[MAX],M[MAX];
int N,flag,sum,sdi,len;
bool cmp(int a,int b){
     return a>b;
}
void dfs(int num,int cur,int next){
     if(num==sdi){
                  flag=1;
                  return;
     }
     if(cur==len){
          dfs(num+1,0,0);
          return;
     }
     int p=-1;
     for(int i=next;i<N;i++){
             if(!M[i] && S[i]!=p && S[i]+cur<=len){
                  p=S[i];

                       M[i]=1;
                       dfs(num,S[i]+cur,i+1);
                       M[i]=0;
                       if(next==0 || flag)return;//最重要的剪枝 
                  
             }
     }
}
int main(){
    while(scanf("%d",&N) && N){
          sum=0;
          for(int i=0;i<N;i++){
                  scanf("%d",&S[i]);
                  sum+=S[i];
          }
          sort(S,S+N,cmp);
          flag=0;
          for(len=S[0];len<=sum/2;len++){
              if(sum%len==0){
                    sdi=sum/len;   
                    memset(M,0,sizeof(M));    
                    dfs(0,0,0);
                    if(flag){
                        printf("%d\n",len);
                        break;
                    }  
              }
          }
          if(!flag)printf("%d\n",sum);
    }
    return 0;
}
