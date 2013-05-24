#include<stdio.h>

const int N=50010;
int sum[N<<2];

void build(int l,int r,int val)
{
    if(l+1==r){scanf("%d",&sum[val]);return;}
    int p=val<<1;
    int q=(l+r)>>1;
    build(l,q,p);
    build(q,r,p|1);
    sum[val]=sum[p]+sum[p|1];
}

int que(int a,int b,int l,int r,int val)
{
   if(a==l && b==r)return sum[val];
    int q=(l+r)>>1;
    if(q>=b)return que(a,b,l,q,val<<1);
    if(q<=a)return que(a,b,q,r,val<<1|1);
    return que(a,q,l,q,val<<1)+que(q,b,q,r,val<<1|1);
}

void add(int a,int b,int l,int r,int val)
{
    sum[val]+=b;
    if(l+1==r && a==l){return;}
    int q=(l+r)>>1;
    if(a<q)add(a,b,l,q,val<<1);
    else add(a,b,q,r,val<<1|1);
}

int main()
{
int t;
scanf("%d",&t);
for(int i=1;i<=t;i++)
{
    printf("Case %d:\n",i);
    int n;
    scanf("%d",&n);
    build(1,n+1,1);
    char s[10];
    while(scanf("%s",s))
    {
        if('E'==s[0])break;
         int a,b;
        scanf("%d%d",&a,&b);
        if('Q'==s[0]){printf("%d\n",que(a,b+1,1,n+1,1));}
        else if('A'==s[0]){add(a,b,1,n+1,1);}
        else{add(a,-b,1,n+1,1);}
    }

}
return 0;
}
