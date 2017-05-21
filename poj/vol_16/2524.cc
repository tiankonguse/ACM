#include"iostream"
#include"cstdlib"
#define MAXN 50000
using namespace std;
int parents[MAXN];
int Find(int a){
    int x=a,tmp;
    while(parents[x]>0)x=parents[x];
    while(parents[a]>0 && parents[a]!=x){ //-1也会触发while! 
       tmp=parents[a];
       parents[a]=x;
       a=tmp;
    
    }
    return x;
}
void Union(int a,int b){
  //  a=Find(a),b=Find(b);
    if(parents[a]<parents[b]){
        parents[a]+=parents[b];
        parents[b]=a;
    }
    else{
        parents[b]+=parents[a];
        parents[a]=b;
    }
}
int main(){
    int N,M,k=1,a,b,c;
    while(scanf("%d%d",&N,&M)&&N&&M){
        c=N;
        memset(parents,-1,N*sizeof(parents[0]));
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            a=Find(a),b=Find(b);
            if(a!=b){
               c--;
               Union(a,b);
            }
        }
        printf("Case %d: %d\n",k++,c);
    }
    return 0;
}
