#include"iostream"
using namespace std;
int R,C,a[100][100],b[100][100];
int dfs(int i,int j){
    if(b[i][j]!=0)return b[i][j];
    b[i][j]=1;
    int max=0,t;
    if(i-1>=0){
               if(a[i-1][j]<a[i][j]){
                  t=dfs(i-1,j);
                  if(max<t)max=t;
               }
    }
    if(i+1<R){
               if(a[i+1][j]<a[i][j]){
                  t=dfs(i+1,j);
                  if(max<t)max=t;
               }
    }
    if(j-1>=0){
               if(a[i][j-1]<a[i][j]){
                  t=dfs(i,j-1);
                  if(max<t)max=t;
               }
    }
    if(j+1<C){
               if(a[i][j+1]<a[i][j]){
                  t=dfs(i,j+1);
                  if(max<t)max=t;
               }
    }
    b[i][j]+=max;
    return b[i][j];
}
int main(){
    while(scanf("%d%d",&R,&C)!=EOF){
        for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                        scanf("%d",&a[i][j]);
                        b[i][j]=0;
                }
        }
        int max=0;
        for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                        b[i][j]=dfs(i,j);
                        if(b[i][j]>max)max=b[i][j];      
                }
        }
        printf("%d\n",max);
        }
}
