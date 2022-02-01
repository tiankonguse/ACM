#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int num[25],l[25],r[25];
int data[21]={1};
void solve(int N){
    int p=0;
    while(N){
        num[p++]=N%3;
        N/=3;
    }
    num[p]=0;
    for(int i=0;i<p;i++)if(num[i]>=2){
        num[i]-=3;
        num[i+1]++;
    }
    if(num[p])p++;
    int lt=0,rt=0;
    for(int i=0;i<p;i++){
        if(num[i]==-1)l[lt++]=data[i];
        else if(num[i]==1)r[rt++]=data[i];
    }
    if(lt==0)printf("empty ");
    else{
        for(int i=0;i<lt;i++){
            if(i==lt-1)printf("%d ",l[i]);
            else printf("%d,",l[i]);
        }
    }
    if(rt==0)printf("empty\n");
    else{
        for(int i=0;i<rt;i++){
            if(i==rt-1)printf("%d\n",r[i]);
            else printf("%d,",r[i]);
        }
    }
}
int main(){
    int T,N;
    for(int i=1;i<20;i++)data[i]=data[i-1]*3;
    scanf("%d",&T);
    for(;T--&&scanf("%d",&N);){
        solve(N);
    }
    return 0;
}
