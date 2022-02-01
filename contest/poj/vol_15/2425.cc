#include"iostream"
using namespace std;
int matrix[1000][1000];
int sg[1001],num[1001];
void inti(int p,int N){
     int flag=1;
     if(sg[p]!=-1)return;
     for(int i=0;i<N;i++){
             if(matrix[p][i]==1){
                 inti(i,N);                
              //   cout<<"sg["<<i<<"]="<<sg[i]<<endl;
                 flag=0;
             }
     }
     for(int i=0;i<N;i++){
             if(matrix[p][i]==1){
               num[sg[i]]=p;
               }
     }
     for(int i=0;i<N;i++){
             if(num[i]!=p){
                           sg[p]=i;
                           break;
             }
     }
     if(flag)sg[p]=0;
}
int main(){
    int N,M,k,p,t;
    while(scanf("%d",&N)==1){
       for(int i=0;i<N;i++){
               memset(matrix[i],0,N*sizeof(matrix[0][0]));
       }
       memset(sg,-1,1001*sizeof(sg[0]));
       memset(num,-1,1001*sizeof(num[0]));
       for(int i=0;i<N;i++){
               scanf("%d",&M);
               for(int j=0;j<M;j++){
                       scanf("%d",&p);
                       matrix[i][p]=1;
               }
       }
       for(int i=0;i<N;i++){
          inti(i,N);
       }
       while(scanf("%d",&k)==1 && k){
          t=0;
          for(int i=0;i<k;i++){
                  scanf("%d",&p);
                  t^=sg[p];
          }
          if(t)printf("WIN\n");
          else printf("LOSE\n");
       }
   /*    for(int i=0;i<N;i++)cout<<i<<".sg:"<<sg[i]<<endl;
       for(int i=0;i<N;i++){
               for(int j=0;j<N;j++){
                       cout<<matrix[i][j]<<" ";
               }
               cout<<endl;
       }
     */  
    }
    return 0;
}
