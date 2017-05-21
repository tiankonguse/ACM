#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 105
using namespace std;
char str[MAXN][10],per[10],ans[10];
int rank[256];
int judge(char *a){
    int r=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(rank[a[i]]>rank[a[j]])r++;
        }
    }
    return r;
}
int main(){
    int N,d,res;
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++){
            scanf(" %s",str[i]);
        }
        for(int i=0;i<5;i++){
            per[i]=i+'A';
        }
        res=0x7f7f7f7f;
        do{
            for(int i=0;i<5;i++){
                rank[per[i]]=i;
            }
            d=0;
            for(int i=0;i<N;i++){
                d+=judge(str[i]);
            }
            if(d<res){
                res=d;
                for(int i=0;i<5;i++)ans[i]=per[i];
            }
        }while(next_permutation(per,per+5));
        printf("%s is the median ranking with value %d.\n",ans,res);
    }
    return 0;
}
