#include"iostream"
#include"cstdlib"
#define MAXN 2001
using namespace std;
int map[MAXN][MAXN];
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
          if(!inTree[j]&&(min_index==-1 || min_length[j]

<min_length[min_index])){
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
char str[MAXN][8];
int dis(char *a,char *b){
   int d=0;
   for(int i=0;i<7;i++){
           if(a[i]!=b[i])d++;
   }
   return d;
}
int main(){
    int N,d;
    while(scanf("%d",&N)&&N){
       for(int i=0;i<N;i++)scanf(" %s",str[i]);
       for(int i=0;i<N;i++){
           for(int j=i+1;j<N;j++){
                d=dis(str[i],str[j]);
                map[i][j]=map[j][i]=d;
           }
       }
       printf("The highest possible quality is 1/%d.\n",prim(N));
    }
    return 0;
}
