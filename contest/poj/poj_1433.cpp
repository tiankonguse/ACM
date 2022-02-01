#include<iostream>
#include<stdio.h>
#include<cstring>
#define FOR(i,l,r) for (int i=(l),_r=(r);i<=_r;i++)
#define COR(i,r,l) for (int i=(r),_l=(l);i>=_l;i--)
#define FL(a) memset(a,0,sizeof(a))
#define UPDATE(i,j) i=max(i,(j))
#define MAXN 10100
#define MAXM 30100
using namespace std;
int o1[MAXM],o2[MAXM],ot[MAXM],pre[MAXM],nx[MAXM];
int h[MAXN],add[MAXN];
bool q[MAXM];
void update(int k) {
    if (q[k]) return ;
    q[k]=1;
    if (!pre[k] && o1[k]!=1)
        UPDATE(add[o1[k]],2);
    if (pre[k]) update(pre[k]);
    if (nx[k]) UPDATE(add[ot[nx[k]]],1);
    else   UPDATE(add[o2[k]],1);
}
int main() {
    int ca;
    for (scanf("%d",&ca); ca; ca--) {
        int N,M;
        scanf("%d%d",&N,&M);
        FOR(i,1,M) scanf("%d%d",&o1[i],&o2[i]);
        FL(h);
        FL(add);
        FL(q);
        COR(i,M,1) {
            nx[i]=h[o2[i]];
            h[o2[i]]=i;
            pre[i]=h[o1[i]];
            ot[i]=(pre[i]?ot[pre[i]]:o1[i]);
        }
        FOR(i,1,N) if (!h[i]) UPDATE(add[i],2);
        else   update(h[i]);
        int Ans=0;
        FOR(i,2,N) Ans+=add[i];
        printf("%d\n",Ans);
    }
    return 0;
}

/*
232
3 0
*/
