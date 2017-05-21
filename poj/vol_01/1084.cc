#include"iostream"
#include"cstdlib"
#include"cstdio"
#include"string.h"
#define MAXN 25+16+9+4+1+1
#define MAXI 70*MAXN
#define inf 0x7f7f7f7f
//using namespace std;
int L[MAXI],R[MAXI],U[MAXI],D[MAXI],C[MAXI];
int S[MAXN],used[70],map[12][12],hash[70][70];
int nmax[6]={0,1,5,14,30,55};
int N,K,len,res,pmax;
bool mark[MAXN],del[MAXN];
void remove(int x){
    for(int i=D[x];i!=x;i=D[i]){
         L[R[i]]=L[i];
         R[L[i]]=R[i];
         S[C[i]]--;
    }
}
void resume(int x){
     for(int i=D[x];i!=x;i=D[i]){
         L[R[i]]=i;
         R[L[i]]=i;
         S[C[i]]++;
     }     
}
int h(){
    int s=0;
    memset(mark,false,sizeof(mark));
    for(int i=R[0];i!=0;i=R[i]){
         if(!mark[i]){
             mark[i]=true;
             s++;
             for(int j=D[i];j!=i;j=D[j]){
                 for(int k=R[j];k!=j;k=R[k]){
                     mark[C[k]]=true;
                 }
             }
         }
    }
    return s;
}
void dfs(){
    if(K+h()>=res)return;
    if(R[0]==0){
        if(K<res)res=K;
        return;
    }
    int s(inf),c;
    for(int i=R[0];i!=0;i=R[i]){
        if(S[i]<s){
            s=S[i];
            c=i;
        }
    }
    for(int i=D[c];i!=c;i=D[i]){
        remove(i);
        for(int j=R[i];j!=i;j=R[j]){
            remove(j);
        }
        K++;
        dfs();
        K--;
        for(int j=R[i];j!=i;j=R[j]){
            resume(j);
        }
        resume(i);
    }
}
int main(){
    int T,k,a,idx,cnt,c,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&k);
        memset(S,0,sizeof(S));
        memset(hash,0,sizeof(hash));
        memset(map,0,sizeof(map));
  	memset(del,false,sizeof(del));
        for(int i=0;i<k;i++){
            scanf("%d",&used[i]);
        }
        pmax=2*N*(N+1),len=2*N+1;
        for(int p=1;p<=pmax;p++){
            a=p*2-1;
            map[a/len][a%len]=p;
        }
        cnt=1;
        for(int s=1;s<=N;s++){
            for(int i=0;i<len-s*2;i+=2){
                for(int j=0;j<len-s*2;j+=2){
                    for(int it=1;it<=s;it++){
                        t=map[i+it*2-1][j];
                        hash[t][++hash[t][0]]=cnt;
                        t=map[i][j+it*2-1];
                        hash[t][++hash[t][0]]=cnt;
                        t=map[i+s*2][j+it*2-1];
                        hash[t][++hash[t][0]]=cnt;
                        t=map[i+it*2-1][j+s*2];
                        hash[t][++hash[t][0]]=cnt;
                    }
					cnt++;
                }
            }
        }
        for(int i=0;i<=nmax[N];i++){
            L[i]=i-1;
            R[i]=i+1;
            U[i]=D[i]=i;
        }
        L[0]=nmax[N];
        R[nmax[N]]=0;
        idx=nmax[N]+1;
        for(int i=1;i<=pmax;i++){
            bool flag=false;
            for(int j=0;j<k;j++){
                if(used[j]==i){
                    flag=true;
                    break;
                }
            }
            if(flag)continue;
            int s=idx;
			L[s]=R[s]=s;
            for(int j=1;j<=hash[i][0];j++){
                a=hash[i][j];
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
        for(int i=0;i<k;i++){
            for(int j=1;j<=hash[used[i]][0];j++){
               c=hash[used[i]][j];
			   if(del[c])continue;
			   del[c]=true;
               remove(c);
               L[R[c]]=L[c];
               R[L[c]]=R[c];
            }
        }
       // cout<<idx<<endl;system("pause");
        K=0;
        res=inf;
        dfs();
        printf("%d\n",res);
    }
//	system("pause");
    return 0;
}
