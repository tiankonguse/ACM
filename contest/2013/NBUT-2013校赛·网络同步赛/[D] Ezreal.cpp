/*************************************************************************
    > File Name: [D] Ezreal.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/18 13:51:11
 ************************************************************************/

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

char str[100][100];

void setRow(int r,int val){
    int i,j;
    for(i=0;i<8;i++){
        if(val&1){
            str[i][r] = '*';
        }
        val >>= 1;
    }
}

void output(){
    int row = 32,i,j,k;
    memset(str,'.',sizeof(str));
    for(i=0;i<8;i++){
        str[i][row] = '\0';
    }

    int tmp;
    for(i=0;i<row;i++){
        scanf("%x",&tmp);
        setRow(i,tmp);
    }
    for(i=0;i<8;i++){
        printf("%s\n",str[i]);
    }
}

int main() {
    int cas;
    scanf("%d",&cas);
    while(cas--){
        output();
        output();
    }
    return 0;
}
