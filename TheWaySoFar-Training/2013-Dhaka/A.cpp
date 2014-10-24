#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int n;
    while (scanf("%d",&n),n){
        int L,W,H;
        int ans=0,ans1=0;
        for (int i=1; i<=n; ++i){
            scanf("%d%d%d",&L,&W,&H);
            if (H>ans){
                ans=H,ans1=L*W*H;
            }
            if (H==ans)
                ans1=max(L*W*H,ans1);
        }
        printf("%d\n",ans1);
    }
}
