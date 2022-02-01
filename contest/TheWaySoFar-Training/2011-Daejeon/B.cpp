#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    for (; T;--T){
        int a,b,c,A,B,C;
        scanf("%d%d%d",&a,&b,&c);
        scanf("%d%d%d",&A,&B,&C);
        int ans=0;
        for (int i=0; i<=min(b,a); ++i)
        for (int j=0; j<=min(b-i,c); ++j){
            int ans1=i*A+j*B;
            int aa=a-i,cc=c-j;
            ans1=ans1+min(aa,cc)*C;
            ans=max(ans,ans1);
        }
        printf("%d\n",ans);
    }
}
