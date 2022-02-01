#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=1000010,N=1000000;
int tree[MAXN*5][4],lazy[MAXN*5][4];
char a[10];
const int P=1000000007;

int solve(int k,int m,int n,int mark,int x){
    long long b=n,c=m-1;
    if (mark==0)
        b=(b-c+P)%P;
    else if (mark==1){
        b=b*(b+1)/2%P;
        c=c*(c+1)/2%P;
        b=(b-c+P)% P;
    }
    else if (mark==2){
        b=b*(b+1)*(2*b+1)/6%P;
        c=c*(c+1)*(2*c+1)/6%P;
        b=(b-c+P)%P;
    }
    else {
        b=b*(b+1)/2%P;
        c=c*(c+1)/2%P;
        long long d1=(b+c)%P,d2=(b-c+P)%P;
        b=(d1*d2)%P;
    }
    b=b*x%P;
    return (b+tree[k][mark])%P;
}

int calc(int k,int m,int n,int mark){
        return solve(k,m,n,mark,lazy[k][mark]);
}

void mark_down(int k,int m,int n,int mark){
        int t=mark;
        tree[k][t]=calc(k,m,n,mark);
        lazy[k<<1][t]=(lazy[k<<1][t]+lazy[k][t])%P;
        lazy[(k<<1)+1][t]=(lazy[(k<<1)+1][t]+lazy[k][t])%P;
        lazy[k][t]=0;
}

void add(int k,int m,int n,int x,int mark,int l,int r){
    if (m>r || n<l) return ;
    if (m>=l && n<=r ) {
        lazy[k][mark]=(lazy[k][mark]+x)%P;
        return ;
    }
    mark_down(k,m,n,mark);
    int z1=k<<1,z2=z1+1,mid=(m+n)>>1;
    add(z1,m,mid,x,mark,l,r);
    add(z2,mid+1,n,x,mark,l,r);
    tree[k][mark]=(calc(z1,m,mid,mark)+calc(z2,mid+1,n,mark))%P;
}

int answer(int k,int m,int n,int l,int r,int mark){
    if (m>r || n<l) return 0;
    if (m>=l && n<=r ){ return calc(k,m,n,mark);}
    mark_down(k,m,n,mark);
    int z1=k<<1,z2=z1+1,mid=(m+n)>>1;
    int t1=answer(z1,m,mid,l,r,mark);
    int t2=answer(z2,mid+1,n,l,r,mark);
    return (t1+t2)%P;
}

int main(){
    int T,num=0;
    scanf("%d",&T);
    for (;T;--T){
        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",++num);
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        for (;q;--q){
            scanf("%s",&a);
            if (a[0]=='p'){
                int l,r,a,b,c,d;
                scanf("%d%d%d%d%d%d",&l,&r,&a,&b,&c,&d);
                while (a<0) a+=P;
                while (b<0) b+=P;
                while (c<0) c+=P;
                while (d<0) d+=P;
                a%=P;  b%=P;  c%=P;  d%=P;
                add(1,0,N,d,0,l,r);
                add(1,0,N,c,1,l,r);
                add(1,0,N,b,2,l,r);
                add(1,0,N,a,3,l,r);
            }
            else {
                int l,r,a,b,c,d;
                scanf("%d%d%d%d%d%d",&l,&r,&a,&b,&c,&d);
                while (a<0) a+=P;
                while (b<0) b+=P;
                while (c<0) c+=P;
                while (d<0) d+=P;
                a%=P;  b%=P;  c%=P;  d%=P;
                int ans=answer(1,0,N,l,r,0);
                ans=(ans+answer(1,0,N,l,r,1))%P;
                ans=(ans+answer(1,0,N,l,r,2))%P;
                ans=(ans+answer(1,0,N,l,r,3))%P;
                if (ans<0) ans+=P;
                int x1=((long long)ans*l)%1000000,x2=((long long)ans*r)%1000000;
                int ll=min(x1,x2),rr=max(x1,x2);

                add(1,0,N,d,0,ll,rr);
                add(1,0,N,c,1,ll,rr);
                add(1,0,N,b,2,ll,rr);
                add(1,0,N,a,3,ll,rr);
                //printf("%d %d\n",ll,rr);
                printf("%d\n",ans);
            }
        }
    }
}
