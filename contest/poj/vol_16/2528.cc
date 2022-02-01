#include"iostream"
#include"cstdlib"
#include"algorithm"
#define MAXN 10005
using namespace std;
int lr[MAXN][2],num[MAXN*4],tree[MAXN*14],nu[MAXN*4],ans;
bool hash[MAXN];
void create(int l,int r,int p){
    tree[p]=-1;
    if(l==r)return;
    int mid=(l+r)>>1;
    create(l,mid,2*p);
    create(mid+1,r,2*p+1);
}
void update(int a,int b,int c,int l,int r,int p){
   if(a==l && b==r){
       tree[p]=c;
       return;
   }
   if(tree[p]!=-1){
         tree[2*p]=tree[p];
         tree[2*p+1]=tree[p];
         tree[p]=-1;
   }
   int mid=(l+r)>>1;
   if(b<=mid)update(a,b,c,l,mid,2*p);
   else if(a>mid)update(a,b,c,mid+1,r,2*p+1);
   else{
       update(a,mid,c,l,mid,2*p);
       update(mid+1,b,c,mid+1,r,2*p+1);
   }
}
void query(int l,int r,int p){
    if(tree[p]!=-1){
         if(!hash[tree[p]]){
            ans++;
            hash[tree[p]]=true;
         }
         return;
    }
    if(l==r)return;
    int mid=(l+r)>>1;
    query(l,mid,2*p);
    query(mid+1,r,2*p+1);
}
int Search(int a,int l,int r){
    int mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(nu[mid-1]==a)return mid;
        else if(nu[mid-1]<a) l=mid+1;
        else r=mid-1;
    }
    return -1;
}
int main(){
    int T,N,M,a;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
           scanf("%d%d",&lr[i][0],&lr[i][1]);
           num[2*i]=lr[i][0];
           num[2*i+1]=lr[i][1];
        }
        sort(num,num+2*N);
        M=0;
        for(int i=0;i<2*N;i++){
                if(i==0)nu[M++]=num[i];
                else{
                    a=num[i]-num[i-1];
                    if(a==0)continue;
                    else if(a==1) nu[M++]=num[i];
                    else{
                        nu[M++]=num[i]-1;
                        nu[M++]=num[i];
                    }
                }
        }
        create(1,M,1);
        for(int i=0;i<N;i++){
              update(Search(lr[i][0],1,M),Search(lr[i][1],1,M),i+1,1,M,1);
              //  cout<<"[]="<<Search(lr[i][0],1,M)<<","<<Search(lr[i][1],1,M)<<endl;
              //  for(int i=1;i<=30;i++)cout<<tree[i]<<endl;
              //  cout<<endl;
        }
      //  for(int i=1;i<=10;i++)cout<<tree[i]<<endl;
        ans=0;
        memset(hash,false,sizeof(hash));
        query(1,M,1);
        printf("%d\n",ans);
    }
    return 0;
}
