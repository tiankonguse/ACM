#include"iostream"
#define MAXN 50010
using namespace std;
struct Node{
     int s,ll,rl,v;
     void init(int d){
          if(v==1)s=ll=rl=0;
          else s=ll=rl=d;
     }
}tree[MAXN*4];
void create(int l,int r,int p){
    tree[p].v=0;
    tree[p].init(r-l+1);
    if(l==r)return;
    int mid=(l+r)>>1;
    create(l,mid,2*p);
    create(mid+1,r,2*p+1);
}
int query(int l,int r,int a,int p){
    if(l==r && a==1)return l;
    int mid=(l+r)>>1;
    if(tree[p].v!=-1){
          tree[2*p].v=tree[2*p+1].v=tree[p].v;
          tree[2*p].init(mid-l+1);
          tree[2*p+1].init(r-mid);
          tree[p].v=-1;
    }
    if(tree[2*p].s>=a)return query(l,mid,a,2*p);    
    else if(tree[2*p].rl+tree[2*p+1].ll>=a)return mid-tree[2*p].rl+1;
    else if(tree[2*p+1].s>=a)return query(mid+1,r,a,2*p+1);     
    else return 0;
}
void update(int l,int r,int a,int b,int c,int p){
    if(l==a && r==b){
        tree[p].v=c;
        tree[p].init(r-l+1);
        return;
    }
    int mid=(l+r)>>1;
    if(tree[p].v!=-1){
        tree[2*p].v=tree[2*p+1].v=tree[p].v;
        tree[2*p].init(mid-l+1);
        tree[2*p+1].init(r-mid);
        tree[p].v=-1;
    }
    if(a>mid)update(mid+1,r,a,b,c,2*p+1);
    else if(b<=mid)update(l,mid,a,b,c,2*p);
    else{
        update(l,mid,a,mid,c,2*p);
        update(mid+1,r,mid+1,b,c,2*p+1);
    }
    tree[p].s=max(tree[2*p].rl+tree[2*p+1].ll,max(tree[2*p].s,tree[2*p+1].s));
    if(tree[p].s==r-l+1)tree[p].v=0;
    if(tree[2*p].v==0)tree[p].ll=tree[2*p].ll+tree[2*p+1].ll;
    else tree[p].ll=tree[2*p].ll;
    if(tree[2*p+1].v==0)tree[p].rl=tree[2*p].rl+tree[2*p+1].rl;
    else tree[p].rl=tree[2*p+1].rl;
}
int main(){
    int N,M,x,a,b,r;
    scanf("%d%d",&N,&M);
    create(1,N,1);
    while(M--){
        scanf("%d",&x);
        if(x==1){
            scanf("%d",&a);
            r=query(1,N,a,1);
            printf("%d\n",r);
            if(r){
                update(1,N,r,r+a-1,1,1);
            }
        }
        else{
            scanf("%d%d",&a,&b);
            update(1,N,a,a+b-1,0,1);
        }
    }
    //system("pause");
    return 0;
}
