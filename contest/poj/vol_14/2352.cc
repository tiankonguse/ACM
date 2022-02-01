#include"iostream"
#define MAXN 32001
using namespace std;
int tree[3*MAXN],res[15000];
int search(int i,int x,int l,int r){
    tree[i]++;
    if(x==r)return tree[i]-1;
    int mid=(l+r)/2;
    if(x<=mid)return search(2*i,x,l,mid);
    else return tree[2*i]+search(2*i+1,x,mid+1,r);
}
int main(){
    int N,x,y;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
       scanf("%d%d",&x,&y);
       res[search(1,x,0,MAXN)]++;
    }
    for(int i=0;i<N;i++){
       printf("%d\n",res[i]);
    }
    return 0;
}
