#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int N=50010;
const int INF = 0x3f3f3f3f;

#define N 60010
#define M 10010
struct treap {
    int key,wht,count,sz,ch[2];
} tp[N*15];
int tree[N<<1];
int nodecount,root;

int IDX(int l,int r) {
    return l+r | l!=r;
}

void init() {
    tp[0].sz=0;
    tp[0].wht=-INF;
    nodecount=0;
    root=0;
}
void update(int x) {
    tp[x].sz=tp[tp[x].ch[0]].sz+tp[x].count+tp[tp[x].ch[1]].sz;
}
void rotate(int &x,int t) {
    int y=tp[x].ch[t];
    tp[x].ch[t]=tp[y].ch[!t];
    tp[y].ch[!t]=x;
    update(x);
    update(y);
    x=y;
}
void insert(int &x,int t) {
    if(! x) {
        x=++nodecount;
        tp[x].key=t;
        tp[x].wht=rand();
        tp[x].count=1;
        tp[x].ch[0]=tp[x].ch[1]=0;
    } else if(tp[x].key==t)  tp[x].count++;
    else {
        int k=tp[x].key<t;
        insert(tp[x].ch[k],t);
        if(tp[x].wht<tp[tp[x].ch[k]].wht) rotate(x,k);
    }
    update(x);
}
void erase(int &x,int t) {
    if(tp[x].key==t) {
        if(tp[x].count==1) {
            if(! tp[x].ch[0] && ! tp[x].ch[1]) {
                x=0;
                return;
            }
            rotate(x,tp[tp[x].ch[0]].wht<tp[tp[x].ch[1]].wht);
            erase(x,t);
        } else tp[x].count--;
    } else erase(tp[x].ch[tp[x].key<t],t);
    update(x);
}
int select(int x,int t) {
    if(! x) return 0;
    if(tp[x].key>t) return select(tp[x].ch[0],t);
    return tp[x].count+tp[tp[x].ch[0]].sz+select(tp[x].ch[1],t);
}
int a[N],b[N],ord[M][5],lb;
int n,m,tt;
int search(int x) {
    int l=1,r=b[0],mid;
    while (l<=r) {
        mid=(l+r)>>1;
        if(b[mid]==x) return mid;
        if(b[mid]<x) l=mid+1;
        else r=mid-1;
    }
}
void treeinsert(int l,int r,int i,int x) {
    insert(tree[IDX(l,r)],x);
    if(l==r) return;
    int m=(l+r)>>1;
    if(i<=m) treeinsert(l,m,i,x);
    else treeinsert(m+1,r,i,x);
}
void treedel(int l,int r,int i,int x) {
    erase(tree[IDX(l,r)],x);
    if(l==r) return;
    int m=(l+r)>>1;
    if(i<=m) treedel(l,m,i,x);
    else treedel(m+1,r,i,x);
}
int query(int l,int r,int x,int y,int k) {
    if(l==r) return l;
    int m=(l+r)>>1;
    int ans=select(tree[IDX(l,m)],y)-select(tree[IDX(l,m)],x);
    if(ans>=k) return query(l,m,x,y,k);
    return query(m+1,r,x,y,k-ans);
}



int main () {
    scanf("%d",&tt);
    while (tt--) {
        scanf("%d%d",&n,&m);
        b[0]=1;
        lb=0;
        memset(tree,0,sizeof(tree));
        init();
        for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            b[++lb]=a[i];
        }
        for(int i=1; i<=m; i++) {
            char s[5];
            int x,y,c;
            scanf("%s",s);
            if(s[0]=='Q') {
                scanf("%d %d %d",&x,&y,&c);
                ord[i][1]=1;
                ord[i][2]=x;
                ord[i][3]=y;
                ord[i][4]=c;
            } else {
                scanf("%d %d",&x,&y);
                ord[i][1]=2;
                ord[i][2]=x;
                ord[i][3]=y;
                b[++lb]=y;
            }
        }
        sort(b+1,b+1+lb);
        for(int i=1; i<=lb; i++) if(b[i]!=b[b[0]]) b[++b[0]]=b[i];
        for(int i=1; i<=n; i++) {
            a[i]=search(a[i]);
            treeinsert(1,b[0],a[i],i);
        }
        for(int i=1; i<=m; i++) {
            if(ord[i][1]==1)printf("%d\n",b[query(1,b[0],ord[i][2]-1,ord[i][3],ord[i][4])]);
            else {
                treedel(1,b[0],a[ord[i][2]],ord[i][2]);
                a[ord[i][2]]=search(ord[i][3]);
                treeinsert(1,b[0],a[ord[i][2]],ord[i][2]);
            }
        }
    }
    return 0;
}
