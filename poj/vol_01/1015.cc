#include"iostream"
#include"cstdlib"
#include"algorithm"
using namespace std;
int n,m,dp[21][805],path[21][805],sum[201],sub[201];
int pv,dv,res[21];
int ab(int a){
   return a>=0?a:-a;
}
void fun(){
     memset(dp,0xff,sizeof(dp));
     memset(path,0xff,sizeof(path));
     dp[0][0]=0;
     bool flag;
     int ii,jj,t0,t1,t2;
     for(int i=0;i<=m-1;i++){
         for(int j=0;j<40*m+1;j++){
             if(dp[i][j]!=-1){
                 for(int k=0;k<n;k++){
                     flag=true;
                     ii=i;
                     jj=j;      
                     while(path[ii][jj]!=-1){
                           if(path[ii][jj]==k){flag=false;break;}
                           jj-=sub[path[ii][jj]];
                           ii--;
                     }      
                     if(flag){
                          t0=j+sub[k];
                          t1=dp[i][j]+sum[k];
                          t2=dp[i+1][t0];
                          if(t1>t2){
                              dp[i+1][t0]=t1;
                              path[i+1][t0]=k;
                          }
                     }
                 }
             }
         }
     }
     int max=0,ti,td;
     int mid=20*m;
     for(int i=0;i<=20*m;i++){
          if(dp[m][mid+i]!=-1){
              if(dp[m][mid+i]>dp[m][mid-i]){
                  ti=mid+i-m*20;
                  td=dp[m][mid+i];
                  break;
              } 
              else{
                 ti=mid-i-m*20;
                 td=dp[m][mid-i];
                 break;
              }
          }
          else if(dp[m][mid-i]!=-1){
              ti=mid-i-m*20;
              td=dp[m][mid-i];
              break;
          }
     }
     pv=(ti+td)/2;
     dv=(td-ti)/2;
     ti+=m*20;
     int kk=0,mm=m;
     while(path[mm][ti]!=-1){
         res[kk++]=path[mm][ti]+1;
         ti-=sub[path[mm][ti]];
         mm--;
     }
     sort(res,res+m);
}
int main(){
    int a,b,c=1;
    while(scanf("%d%d",&n,&m)&&n&&m){
         for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            sum[i]=a+b;
            sub[i]=a-b+20;
         }
         pv=dv=0;
         fun();
         printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",c++,pv,dv);
         for(int i=0;i<m;i++){
            printf(" %d",res[i]);
         }
         printf("\n\n");
    }
    
    return 0;
}
