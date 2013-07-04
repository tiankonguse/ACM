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

int tree[N<<1];

struct treap {
    int key,wht,count,sz,ch[2];
} tp[N*20];

int nodecount;

int id(int l,int r) {
    return l+r | l!=r;
}

void init() {
    tp[0].sz=0;
    tp[0].wht=-INF;
    tp[0].key=-1;
    nodecount=0;
}

//update this tree's size
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
    if(!x) {
        x=++nodecount;
        tp[x].key=t;
        tp[x].wht=rand();
        tp[x].count=1;
        tp[x].ch[0]=tp[x].ch[1]=0;
    } else if(tp[x].key==t) {
        tp[x].count++;
    } else {
        int k=tp[x].key<t;
        insert(tp[x].ch[k],t);
        if(tp[x].wht<tp[tp[x].ch[k]].wht) {
            rotate(x,k);
        }
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

int select(int x,int k) {
    if(! x) return 0;
    if(k<tp[x].key) return select(tp[x].ch[0],k);
    int q=0,p=tp[tp[x].ch[0]].sz+tp[x].count;
    if(k>tp[x].key) q=select(tp[x].ch[1],k);
    return p+q;
}

int a[N],n,m,ans;
void treeinsert(int l,int r,int i,int x) {
    insert(tree[id(l,r)],x);
    if(l==r) return;
    int m=(l+r)>>1;
    if(i<=m) treeinsert(l,m,i,x);
    if(i>m) treeinsert(m+1,r,i,x);
}

void del(int l,int r,int i,int x) {
    erase(tree[id(l,r)],x);
    if(l==r) return;
    int m=(l+r)>>1;
    if(i<=m) del(l,m,i,x);
    if(i>m) del(m+1,r,i,x);
}

void query(int l,int r,int L,int R,int x) {
    if(L<=l && R>=r) {
        ans+=select(tree[id(l,r)],x);
        return;
    }
    int m=(l+r)>>1;
    if(L<=m) query(l,m,L,R,x);
    if(R>m) query(m+1,r,L,R,x);
}

int main() {
    int tt;
    scanf("%d",&tt);
    while (tt--) {
        scanf("%d%d",&n,&m);
        init();
        memset(tree,0,sizeof(tree));
        for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            treeinsert(1,n,i,a[i]);
        }
        while (m--) {
            char s[5];
            int x,y,c;
            scanf("%s",s);
            if(s[0]=='C') {
                scanf("%d %d",&x,&y);
                del(1,n,x,a[x]);
                a[x]=y;
                treeinsert(1,n,x,a[x]);
            } else {
                scanf("%d %d %d",&x,&y,&c);
                int l=0,r=INF,mid;
                while (l<r) {
                    ans=0;
                    mid=(l+r)>>1;
                    query(1,n,x,y,mid);
                    if(ans<c) l=mid+1;
                    else r=mid;
                }
                printf("%d\n",l);
            }
        }
    }
    return 0;
}

