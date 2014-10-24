#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int bo[40000],bo1[20001];

int main(){
    memset(bo,0,sizeof(bo));
    for (int i=0; i<20000; ++i)
        for (int j=i; j<20000; ++j)
            if (i*i+j*j>=20000) break;
            else bo[i*i+j*j]=1;
    memset(bo1,0,sizeof(bo1));
    for (int i=2; i<20000; ++i)
        if (bo[i])
            for (int j=2; j<i; ++j)
            if (bo[j] && i%j==0) {
                bo1[i]=1;
                break;
            }
    int T;
    scanf("%d",&T);
    for (;T;--T){
        int n,m;
        scanf("%d%d",&n,&m);
        n=n*n+m*m;
        if (bo1[n]) printf("C\n");
        else printf("P\n");
    }
}
