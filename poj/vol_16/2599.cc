#include"iostream"
using namespace std;
int N,K,t;
int map[1001][1001];
int used[1001];
bool check(int s){
     for(int i=1;i<=N;i++){
        if(!used[i] && i!=s && map[s][i]==1){
            used[i]=1;
            if(!check(i)){
                if(s==K)t=i;
                return true;
            }
            used[i]=0;
        }
     }
     return false;
}
int main(){
    int a,b;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N-1;i++){
       scanf("%d%d",&a,&b);
       map[a][b]=1;
       map[b][a]=1;
    }
    used[K]=1;
    if(check(K))printf("First player wins flying to airport %d\n",t);
    else printf("First player loses\n");
    return 0;
}
