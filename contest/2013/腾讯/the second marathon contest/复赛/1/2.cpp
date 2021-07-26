/**************************************************************************
 **      File Name: 2.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/29 18:25:27
/**************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

struct T{
    char a[9];
    int str[1000];
    int num;
    void init(){
        memset(a,0,sizeof(a));
        num = 0;
    }

    void set(int k,int bit,int val){
        a[k] |= (val<<bit);
    }

    int get(int k,int bit){
        return a[k]&(val<<bit)
    }

}now;
queue<T>que;
int str[]={2,3,5,7,11,13,17,19,23};
int ans;

int main(){
    int t,t0,i,j,k;
    char s[6];
    scanf("%d",&t);

    for(t0=1;t0<=t;t0++){

        now.init();
        while(!que.empty())que.pop();
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                scanf("%s",s);
                for(k=0;k<5;k++){
                    now.set(i*3+j,k,s[k]=='G' || s[k] == '1');
                }
            }
        }



        printf("Case #%d: %d\n",t0,ans);
    }

    return 0;
}
