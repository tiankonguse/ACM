#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 20
using namespace std;
int t,n;
int num[MAXN];
int used[MAXN];
bool found;
void dfs(int s,int d,int next){
    if(s==t){
        found=true;
        for(int i=0;i<d;i++){
           if(i!=0)printf("+%d",used[i]);
           else printf("%d",used[i]);
        }
        printf("\n");
        return;
    }
    for(int i=next;i<n;i++){
        if(s+num[i]<=t){
            used[d]=num[i];
            dfs(s+num[i],d+1,i+1);
        }
        while(i<n-1 && num[i]==num[i+1])i++;
    }
}
int main(){
    while(~scanf("%d%d",&t,&n)&&t){
        for(int i=0;i<n;i++)scanf("%d",&num[i]);
        found=false;
        printf("Sums of %d:\n",t);
        dfs(0,0,0);
        if(!found)printf("NONE\n");
    }
    return 0;
}
