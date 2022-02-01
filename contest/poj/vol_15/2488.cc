#include"iostream"
#include"cstdlib"
using namespace std;
bool used[27][27];
char res[100];
int N,M,s;
int ab(int x){
    return x>0?x:-x;
}
bool dfs(int x,int y,int d){
   if(d==s)return true;
   for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
         if(used[i][j])continue;
         if((ab(i-x)==2&&ab(j-y)==1)||(ab(i-x)==1&&ab(j-y)==2)){
             used[i][j]=true;
             res[d*2]='A'+i;
             res[d*2+1]='1'+j;
             if(dfs(i,j,d+1))return true;
             used[i][j]=false;
         }
      }
   }
   return false;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int c=1;c<=T;c++){
        scanf("%d%d",&N,&M);
        memset(used,false,sizeof(used));
        s=N*M;
        res[0]='A';
        res[1]='1';
        used[0][0]=true;
        printf("Scenario #%d:\n",c);
        if(dfs(0,0,1)){
           for(int i=0;i<s*2;i++){
              printf("%c",res[i]);
           }
           printf("\n");
        }
        else printf("impossible\n");
        printf("\n");
    }
   // system("pause");
    return 0;
}
