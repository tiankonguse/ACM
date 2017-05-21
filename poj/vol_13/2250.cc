#include"iostream"
#include"string"
using namespace std;
string a[101],b[101],c[101];
int dp[101][101],re[101][101];
void fun(int l1,int l2){
   int i,j;
   for(i=1;i<=l1;i++){
       for(j=1;j<=l2;j++){
               if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    re[i][j]=0;
               }       
               else{
                    if(dp[i-1][j]>dp[i][j-1]){
                        dp[i][j]=dp[i-1][j];
                        re[i][j]=-1;
                    }
                    else{
                        dp[i][j]=dp[i][j-1];
                        re[i][j]=1;
                    }
               }
       }
   }
   int m=dp[l1][l2];
   i=l1;
   j=l2;
   int k=m;
   while(k && i && j){
       if(re[i][j]==0){
           c[k--]=a[i-1];
           i--;
           j--;
       }
       else if(re[i][j]==-1){
           i--;
       }
       else{
           j--;
       }
   }
   for(i=1;i<=m;i++){
       if(i==m)cout<<c[i]<<endl;
       else cout<<c[i]<<" ";
   }
}
int main(){
    string s;
    int t=0,l1=0,l2=0;
    while(cin>>s){
         if(s=="#"){
            if(t==1){
                 fun(l1,l2);
                 l1=0;
                 l2=0;
               //  for(int i=0;i<l1;i++)cout<<a[i]<<" ";cout<<endl;
               //  for(int i=0;i<l2;i++)cout<<b[i]<<" ";cout<<endl;            
            }
            t=(t+1)%2;
         }
         else{
             if(t==0)a[l1++]=s;
             else b[l2++]=s;
         }
    }
    return 0;
}
