#include<iostream>
#include<fstream>
#include<cmath>
 
using namespace std;
const int N=5010;
const int Max=10000;
struct e{
    int l,r,conut,size;
}tree[N<<3];
 
int a[20001];
int b[20001];
int a1[10001];
int b1[10001];
int n;
struct TT{
	int l,r,sign,val;
    void set(int l,int r,int sign,int val){this->l=l;this->r=r;this->sign=sign;this->val=val;}
}xy[2][Max+1];
int cmp(const void *a,const void *b){
    return ((TT *)a)->val-((TT *)b)->val;
}

 
void build(int l,int r,int p){
    tree[p].l=l;
    tree[p].r=r;
    tree[p].size=0;
    tree[p].conut=0;
    if(l<r-1)
    {
        int mid=(l+r)>>1;
        build(l,mid,2*p);
        build(mid,r,2*p+1);
    }
}
 
void insert(int l,int r,int p,int f){
    if(tree[p].l==l&&tree[p].r==r)
    {
        tree[p].conut++;
        if(tree[p].conut==1)
        {
            if(f==0)
                tree[p].size=a1[r]-a1[l];
            else
                tree[p].size=b1[r]-b1[l];
        }
    }
    else
    {
        int mid=(tree[p].l+tree[p].r)>>1;
        if(r<=mid)
            insert(l,r,2*p,f);
        else
            if(l>=mid)
                insert(l,r,2*p+1,f);
            else
            {
                insert(l,mid,2*p,f);
                insert(mid,r,2*p+1,f);
            }
            if(tree[p].conut==0)
            {
                tree[p].size=tree[2*p].size+tree[2*p+1].size;
            }
    }
}
 
void delet(int l,int r,int p){
    if(tree[p].l==l&&tree[p].r==r)
    {
        tree[p].conut--;
        if(tree[p].conut==0)
            tree[p].size=tree[2*p].size+tree[2*p+1].size;
    }
    else
    {
        int mid=(tree[p].l+tree[p].r)>>1;
        if(r<=mid)
            delet(l,r,2*p);
        else
            if(l>=mid)
                delet(l,r,2*p+1);
            else
            {
                delet(l,mid,2*p);
                delet(mid,r,2*p+1);
            }
            if(tree[p].conut==0)
            {
                tree[p].size=tree[2*p].size+tree[2*p+1].size;
            }
    }
}
int cmp2(const void *a,const void *b){
    return *((int *)a)-*((int*)b);
}

void add(int m,int sign,int &k){
	if(sign){
		if(!a[m+Max]){
			a[m+Max]=1;a1[++k]=m;
		}
	}else{
		if(!b[m+Max]){
			b[m+Max]=1;b1[++k]=m;
		}
	}
}
 
void read(){
    int i,j;
    int numx=0,numy=0;
    int x1,y1,x2,y2;
    scanf("%d",&n);
    
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        add(x1,0,numx);
        add(y1,1,numy);
        add(x2,0,numx);
        add(y2,1,numy);

        xy[0][2*i-1].set(y1,y2,0,x1);
        xy[0][2*i  ].set(y1,y2,1,x2);
        xy[1][2*i-1].set(x1,x2,0,y1);
        xy[1][2*i  ].set(x1,x2,1,y2);

    }
    qsort(a1+1,numy,sizeof(int),cmp2);
    qsort(b1+1,numx,sizeof(int),cmp2);
    for(i=1;i<=numy;i++)
        a[a1[i]+10000]=i;
    for(i=1;i<=numx;i++)
        b[b1[i]+10000]=i;
    build(1,numy,1);
    
    qsort(xy[0]+1,2*n,sizeof(TT),cmp);
    qsort(xy[1]+1,2*n,sizeof(TT),cmp);
    j=0;
    int ans=0;
    for(i=1;i<=2*n;i++)
    {
        if(xy[0][i].sign==0)
            insert(a[xy[0][i].l+10000],a[xy[0][i].r+10000],1,0);
        else
            delet(a[xy[0][i].l+10000],a[xy[0][i].r+10000],1);
        ans+=abs(tree[1].size-j);
        j=tree[1].size;
    }
    build(1,numx,1);
    j=0;
    for(i=1;i<=2*n;i++)
    {
        if(xy[1][i].sign==0)
            insert(b[xy[1][i].l+10000],b[xy[1][i].r+10000],1,1);
        else
            delet(b[xy[1][i].l+10000],b[xy[1][i].r+10000],1);
        ans+=abs(tree[1].size-j);
        j=tree[1].size;
    }
    cout<<ans<<endl;
}
 
int main(){
    read();
    int ans;
    cin>>ans;
    return 0;
}
