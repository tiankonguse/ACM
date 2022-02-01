/*************************************************************************
    > File Name: 1125.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/24 18:37:17
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

char str[1000][1000];
int col,line;
bool have[10][8]={
 // {1,2,3,4,5,6,7},
    {1,1,1,0,1,1,1},//0
    {0,0,1,0,0,1,0},//1
    {1,0,1,1,1,0,1},//2
    {1,0,1,1,0,1,1},//3
    {0,1,1,1,0,1,0},//4
    {1,1,0,1,0,1,1},//5
    {1,1,0,1,1,1,1},//6
    {1,0,1,0,0,1,0},//7
    {1,1,1,1,1,1,1},//8
    {1,1,1,1,0,1,1},//9
};


void setLine(int x,int y,int len){
    while(len--){
        str[x][++y] = '-';
    }
}

void setRow(int x,int y,int len){
    while(len--){
        str[++x][y] = '|';
    }
}

void init(int s,int n){
    memset(str,' ',sizeof(str));
    col = n*(s + 3)-1;
    line = 2 * s + 3;
    for(int i=0;i<line;i++){
        str[i][col] = '\0';
//        str[i][col+1] = '\0';
    }

}

void setChar(int i,int y,int s){
    if(i == 0){
        setLine(0,y,s);
    }else if(i==1){
        setRow(0,y,s);
    }else if(i==2){
        setRow(0,y+s+1,s);
    }else if(i==3){
        setLine(s+1,y,s);
    }else if(i==4){
        setRow(s+1,y,s);
    }else if(i==5){
        setRow(s+1,y+s+1,s);
    }else if(i==6){
        setLine((s+1)<<1,y,s);
    }
}

void setNum(int val,int nowy,int s){
    for(int i=0;i<7;i++){
        if(have[val][i]){
            setChar(i,nowy,s);
        }
    }
}

int main() {

    char in[20];
    int s,n,nowy,i;
    while(scanf("%d%s",&s,in),s){
        n = strlen(in);
        init(s,n);
        nowy = 0;
//        puts("--");
        for(i=0;i<n;i++,nowy+=(s+3)){
            setNum(in[i]-'0',nowy,s);
        }
//puts("--");
        for(i=0;i<line;i++){
            printf("%s\n",str[i]);
        }
        puts("");
//
    }

    return 0;
}
