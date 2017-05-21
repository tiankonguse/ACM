#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 100100
#define max(a,b) (a>b?a:b)
using namespace std;
int spend[MAXN];
int N,M;
bool yep(int s){
    int t=0,k=0;
    for(int i=0;i<N;i++){
        if(t+spend[i]<=s)t+=spend[i];
        else{
            t=spend[i];
            k++;
        }
    }
    if(t>0)k++;
    return (k<=M);
}
int main(){
    while(~scanf("%d%d",&N,&M)){
        int l=0,r=0,mid;
        for(int i=0;i<N;i++){
            scanf("%d",&spend[i]);
            l=max(l,spend[i]);
            r+=spend[i];
        }
        int res=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(yep(mid)){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("%d\n",res);
    }
    return 0;
}
