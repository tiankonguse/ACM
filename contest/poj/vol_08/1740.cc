#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int pile[11],N;
int main(){
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++)scanf("%d",&pile[i]);
        sort(pile,pile+N);
        if(N%2==1)printf("1\n");
        else{
            bool flag=true;
            for(int i=0;i<N;i+=2){
                if(pile[i]!=pile[i+1])flag=false;
            }
            printf("%d\n",flag?0:1);
        }
    }
    return 0;
}
