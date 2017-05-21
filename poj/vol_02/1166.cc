#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 262144
using namespace std;
int s[9],t[9];
int data[9][9]={
    1,1,0,1,1,0,0,0,0,
    1,1,1,0,0,0,0,0,0,
    0,1,1,0,1,1,0,0,0,
    1,0,0,1,0,0,1,0,0,
    0,1,0,1,1,1,0,1,0,
    0,0,1,0,0,1,0,0,1,
    0,0,0,1,1,0,1,1,0,
    0,0,0,0,0,0,1,1,1,
    0,0,0,0,1,1,0,1,1
};
int check(int k){
    for(int i=0;i<9;i++)t[i]=s[i];
    int d;
    for(int i=0;i<9;i++){
        d=k&3;
        k>>=2;
        for(int j=0;j<9;j++)t[j]+=d*data[i][j];
    }
    int r=0;
    for(int i=0;i<9;i++)r+=t[i]%4;
    return r==0;
}
int main(){
    int ans;
    for(int i=0;i<9;i++)scanf("%d",&s[i]);
    for(int i=0;i<MAXN;i++){
        if(check(i)){
            ans=i;
            break;
        }
    }
    for(int i=0;i<9;i++){
        int d=ans&3;
        ans>>=2;
        for(int j=1;j<=d;j++)printf("%d ",i+1);
    }
    printf("\n");
    return 0;
}
