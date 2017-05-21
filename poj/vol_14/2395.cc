#include"iostream"
#include"cstdlib"
#define MAXN 2001
using namespace std;
int map[MAXN][MAXN];
int N,M;
bool inTree[MAXN];   
int min_length[MAXN];     
int prim(int n)   
{   
    int res=0;
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
        if(res<min_length[min_index])res=min_length[min_index];
        for(int j=0;j<n;j++){
           if(!inTree[j] && map[j][min_index]<min_length[j]){
                 min_length[j]=map[j][min_index];
           }
        }
    }
    return res;
}   

int main(){
    int a,b,c;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        map[i][j]=INT_MAX;
      }
    }
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(map[a-1][b-1]>c)
            map[a-1][b-1]=map[b-1][a-1]=c;
        }
        printf("%d\n",prim(N));
   // system("pause");
    return 0;
}
