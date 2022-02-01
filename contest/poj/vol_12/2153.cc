#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#define MAXN 10005
#define MAXM 55
#define MAXS 35
using namespace std;
map<string,int>mp;
char name[MAXN][MAXS];
char str[MAXS];
int score[MAXN];
int main(){
    int lm,N,M,sc;
    while(~scanf("%d",&N)){
        mp.clear();
        lm=0;
        getchar();
        for(int i=0;i<N;i++){
            gets(name[i]);
            mp[name[i]]=0;
        }
        scanf("%d",&M);
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                scanf("%d ",&sc);
                gets(str);
                mp[str]+=sc;
                score[j]=mp[str];
            }
            lm=mp["Li Ming"];
            sort(score,score+N);
            for(int j=N-1;j>=0;j--){
                if(score[j]==lm){
                    printf("%d\n",N-j);
                    break;
                }
            }
        }

    }
    return 0;
}
