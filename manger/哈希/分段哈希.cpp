/*************************************************************************
    > File Name: 分段哈希.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/4 8:22:53
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int cs=337,cs2=1007;
struct HS {
    //n为当前段有几种颜色
    //s[]存这种颜色的个数,b[]存颜色的值
    int a[1000],next[cs2],n,s[cs2],f[cs2],b[cs2];
    int bj;

    void clear() {
        bj=-1;
        memset(f,-1,sizeof(f));
        n=0;
    }
    void init() {
        bj=-1;
        for(int i=0; i<n; i++)
            f[b[i]%cs2]=-1;
        n=0;
    }
    int fd(int k) {
        if(bj!=-1) {
            if(bj==k)return cs;
            else return 0;
        }
        int fk=f[k%cs2];
        while(fk!=-1) {
            if(b[fk]==k)return s[fk];
            fk=next[fk];
        }
        return 0;
    }
    int fd(int l,int r,int k) {
        int da=0;
        if(bj!=-1) {
            push();
            crt();
        }

        for(int i=l; i<=r; i++) {
            da+=(a[i%cs]==k);
        }
        return da;
    }
    void ins(int k) {
        int fk=f[k%cs2];
        while(fk!=-1) {
            if(b[fk]==k) {
                s[fk]++;
                return ;
            }
            fk=next[fk];
        }
        s[n]=1;
        b[n]=k;
        next[n]=f[k%cs2];
        f[k%cs2]=n++;
    }
    void update(int l,int r,int k) {
        push();
        for(int i=l; i<=r; i++)
            a[i%cs]=k;
        crt();
    }
    void push() {
        if(bj!=-1) {
            for(int i=0; i<cs; i++)
                a[i]=bj;
            bj=-1;
        }
    }
    void crt() {
        init();
        for(int i=0; i<cs; i++)
            ins(a[i]);
    }
} hs[400];
int main() {
    for(int i=0; i<400; i++)
        hs[i].clear();
    int n,m;
    while(cin>>n>>m) {
        for(int i=0; i<n; i++)
            scanf("%d",&hs[i/cs].a[i%cs]);
        for(int i=0; i*cs<n; i++)
            hs[i].crt();

        while(m--) {
            int a,l,z,r;
            scanf("%d%d%d%d",&a,&l,&r,&z);
            if(a==1) { //更新
                if(l/cs==r/cs) {
                    hs[l/cs].update(l,r,z);
                } else {
                    hs[l/cs].update(l%cs,cs-1,z);
                    hs[r/cs].update(0,r%cs,z);
                    for(int i=l/cs+1; i<r/cs; i++)
                        hs[i].bj=z;
                }

            } else { //查询
                int da=0;
                if(l/cs==r/cs) {
                    printf("%d\n",hs[l/cs].fd(l,r,z));
                } else {
                    da+=hs[l/cs].fd(l%cs,cs-1,z);
                    da+=hs[r/cs].fd(0,r%cs,z);
                    for(int i=l/cs+1; i<r/cs; i++)
                        da+=hs[i].fd(z);
                    printf("%d\n",da);
                }
            }
        }
    }
}

