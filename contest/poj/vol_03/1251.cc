#include"iostream"
#include"cstdlib"
#define MAXN 30
using namespace std;
int map[MAXN][MAXN];
int N;
bool inTree[MAXN];   
int min_length[MAXN];     
int prim(int n)   
{   
    int sum_length=0;
    memset(inTree,false,sizeof(inTree));
    for(int i=1;i<n;i++)min_length[i]=INT_MAX;
    min_length[0]=0;
    for(int i=0;i<n;i++){
        int min_index=-1;
        for(int j=0;j<n;j++){
          if(!inTree[j]&&(min_index==-1 || min_length[j]<min_length[min_index])){
             min_index=j;
          }
        }
        inTree[min_index]=true;
        sum_length+=min_length[min_index];
        for(int j=0;j<n;j++){
           if(!inTree[j] && map[j][min_index]<min_length[j]){
                 min_length[j]=map[j][min_index];
           }
        }
    }
    return sum_length;
}   
int main(){
    int m,t,b;
    char c;
    while(scanf("%d",&N)&&N){
       for(int i=0;i<N;i++){
          for(int j=0;j<N;j++){
             map[i][j]=INT_MAX;
          }
       }
       for(int i=0;i<N-1;i++){
         scanf(" %c%d",&c,&m);
         t=c-'A';
         for(int j=0;j<m;j++){
            scanf(" %c%d",&c,&b);
            if(b<map[t][c-'A'])map[t][c-'A']=map[c-'A'][t]=b;
         }
       }
       printf("%d\n",prim(N));
    }
   // system("pause");
    return 0;
}
