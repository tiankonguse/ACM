#include"iostream"
#define MAXN 50001
using namespace std;
struct Node{
    int s,ll,rl;
}tree[MAXN*4];
void create(int l,int r,int p){
    tree[p].s=tree[p].ll=tree[p].rl=r-l+1;
    if(l==r)return;
    int mid=(l+r)>>1;
    create(l,mid,2*p);
    create(mid+1,r,2*p+1);
}
int query(int l,int r,int a,int p){
    if(tree[p].s==0 || tree[p].s==r-l+1 || l==r)return tree[p].s;
    int mid=(l+r)>>1;
    if(a<=mid){
         if(a>=mid-tree[2*p].rl+1)return tree[2*p].rl+tree[2*p+1].ll;
         else return query(l,mid,a,2*p);
    }
    else{
         if(a<=mid+tree[2*p+1].ll)return tree[2*p].rl+tree[2*p+1].ll;
         else return query(mid+1,r,a,2*p+1);
    }
}
void update(int l,int r,int a,int b,int p){
    if(l==r){
         tree[p].s=tree[p].ll=tree[p].rl=b;
         return;
    }
    int mid=(l+r)>>1;
    if(a<=mid)update(l,mid,a,b,2*p);
    else update(mid+1,r,a,b,2*p+1);
    tree[p].s=max(tree[2*p].rl+tree[2*p+1].ll,max(tree[2*p].s,tree[2*p+1].s));
    if(tree[2*p].ll==mid-l+1)tree[p].ll=tree[2*p].ll+tree[2*p+1].ll;
    else tree[p].ll=tree[2*p].ll;
    if(tree[2*p+1].rl==r-mid)tree[p].rl=tree[2*p+1].rl+tree[2*p].rl;
    else tree[p].rl=tree[2*p+1].rl;
}
int st[50001];
int main(){
    int N,M,a,d,l=0;
    char c;
    scanf("%d%d",&N,&M);
    create(1,N,1);
    while(M--){
         scanf(" %c",&c);
         if(c=='D'){
              scanf("%d",&a);
              st[l++]=a;
              update(1,N,a,0,1);
         }
         else if(c=='Q'){
              scanf("%d",&a);
              printf("%d\n",query(1,N,a,1));
         }
         else{
              d=st[--l];
              update(1,N,d,1,1);
         }
    }
   // system("pause");
    return 0;
}
