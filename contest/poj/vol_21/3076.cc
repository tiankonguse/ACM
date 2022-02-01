#include"iostream"
#include"cstdio"
#include"cstdlib"
#define MAXN 1024+1
#define MAXI 1024*4096+1
#define MAXL 16
#define inf 0x7f7f7f7f
int L[MAXI],R[MAXI],U[MAXI],D[MAXI],C[MAXI],W[MAXI];
int S[MAXN],I[MAXN],num[4],O[256];
int N,M,K;
bool hash[MAXN];
char map[17][17];
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
            U[D[j]]=D[U[j]]=j;
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
        O[K]=W[i];
        for(int j=R[i];j!=i;j=R[j]){
            remove(C[j]);
        }
        K++;
        if(dfs())return true;
        K--;
        for(int j=L[i];j!=i;j=L[j]){
            resume(C[j]);
        }
    }
    resume(c);
    return false;
}
int main(){
    int idx,d,a,s,x,y;
    bool flag=false;
    while(~scanf(" %s",map[0])){
        if(flag)printf("\n");flag=true;
        memset(S,0,sizeof(S));
        memset(hash,false,sizeof(hash));
  	memset(I,0xff,sizeof(I));
        for(int i=0;i<16;i++){
            if(i!=0)scanf(" %s",map[i]);
            for(int j=0;j<16;j++){
                if(map[i][j]!='-'){
                    d=map[i][j]-'A'+1;
                    hash[i*16+j+1]=true;
                    hash[256+i*16+d]=true;
                    hash[512+j*16+d]=true;
                    hash[768+(i/4*4+j/4)*16+d]=true;
                }
            }
        }
        idx=0;
        for(int i=0;i<=1024;i++){
            if(hash[i])continue;
            L[idx]=idx-1;
            R[idx]=idx+1;
            U[idx]=D[idx]=idx;
            I[i]=idx;
            idx++;
        }
        L[0]=idx-1;
        R[idx-1]=0;
        for(int j=1;j<=4096;j++){
            d=j%16;if(d==0)d=16;
            y=(j-d)%256/16;
            x=(j-d-16*y)/256;
            num[0]=I[x*16+y+1];
            num[1]=I[256+x*16+d];
            num[2]=I[512+y*16+d];
            num[3]=I[768+(x/4*4+y/4)*16+d];
			if(num[0]==-1 || num[1]==-1 || num[2]==-1 ||num[3]==-1)continue;
            s=idx;
            L[s]=R[s]=s;
            for(int k=0;k<4;k++){
                a=num[k];
				S[a]++;
                W[idx]=j;
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
        K=0;
        dfs();
        for(int i=0;i<K;i++){
            int j=O[i];
            d=j%16;if(d==0)d=16;
            y=(j-d)%256/16;
            x=(j-d-16*y)/256;
            map[x][y]=(char)('A'+d-1);
			//printf("%d,%d:%d\n",x,y,d);
		}
		//printf("%d\n",K);
		for(int i=0;i<16;i++){
           printf("%s\n",map[i]);
        }
    }
    //system("pause");
    return 0;
}

