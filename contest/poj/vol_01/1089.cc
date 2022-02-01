#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 50005
using namespace std;
struct seg{
    int s,e;
    friend bool operator<(seg a,seg b){
        if(a.s==b.s)return a.e>b.e;
        else return a.s<b.s;
    }
}s[MAXN];
int main(){
    int N;
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++){
            scanf("%d%d",&s[i].s,&s[i].e);
        }
        sort(s,s+N);
        int min=s[0].s,max=s[0].e;
        for(int i=1;i<N;i++){
            if(s[i].s>max){
                printf("%d %d\n",min,max);
                min=s[i].s;
                max=s[i].e;
            }
            else if(s[i].e>max){
                max=s[i].e;
            }
        }
        printf("%d %d\n",min,max);
    }
    return 0;
}
