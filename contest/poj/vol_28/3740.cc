#include"iostream"
#include"cstring"
#include"cstdio"
#include"cstdlib"
#define MAXN 305
#define MAXM 17
#define MAXI MAXN*MAXM
#define inf 0x7f7f7f7f
using namespace std;
int L[MAXI],R[MAXI],U[MAXI],D[MAXI],C[MAXI];
int S[MAXN],map[MAXM][MAXN];
int M,N;
void remove(int c){
    for(int i=D[c];i!=c;i=D[i]){
        for(int j=R[i];j!=i;j=R[j]){
            U[D[j]]=U[j];
            D[U[j]]=D[j];
            S[C[j]]--;
        }
    }
    L[R[c]]=L[c];
    R[L[c]]=R[c];
}
void resume(int c){
    L[R[c]]=R[L[c]]=c;
    for(int i=U[c];i!=c;i=U[i]){
        for(int j=L[i];j!=i;j=L[j]){
            D[U[j]]=U[D[j]]=j;
            S[C[j]]++;
        }
    }
}
bool dfs(){
    if(R[0]==0)return true;
    int s(inf),c;
    for(int i=R[0];i!=0;i=R[i]){
        if(S[i]<s){
            s=S[i];
            c=i;
        }
    }
    remove(c);
    for(int i=D[c];i!=c;i=D[i]){
        for(int j=R[i];j!=i;j=R[j]){
            remove(C[j]);
        }
        if(dfs())return true;
        for(int j=L[i];j!=i;j=L[j]){
            resume(C[j]);
        }
    }
    resume(c);
    return false;
}
int main(){
    int a,idx,s;
    while(~scanf("%d%d",&M,&N)){
         memset(S,0,sizeof(S));
         for(int i=1;i<=M;i++){
             for(int j=1;j<=N;j++){
                 scanf("%d",&map[i][j]);
             }
         }
         for(int i=0;i<=N;i++){
             L[i]=i-1;R[i]=i+1;
             U[i]=D[i]=i;
         }
         L[0]=N;R[N]=0;
         idx=N+1;
         for(int i=1;i<=M;i++){
             s=idx;
             L[s]=R[s]=s;
             for(int j=1;j<=N;j++){
                if(map[i][j]){
                    a=j;
                    S[a]++;
                    C[idx]=a;
                    U[idx]=U[a];
                    D[idx]=a;
                    D[U[a]]=idx;
                    U[a]=idx;
                    L[idx]=L[s];
                    R[idx]=s;
                    R[L[s]]=idx;
                    L[s]=idx;
                    idx++;
                }
             }
         }
         if(dfs())printf("Yes, I found it\n");
         else printf("It is impossible\n");
    }
    return 0;
}
