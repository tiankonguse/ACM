/*************************************************************************
    > File Name: Chinese Girls' Amusement.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 19:16:41
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



void mystrrev(char *str){
    int l=0,r=strlen(str)-1;
    while(l<r){
        str[l] ^= str[r], str[r] ^= str[l], str[l] ^= str[r];
        l++,r--;
    }
}

char *getAns(char *first){
    if((*first-'0')&1){

    }else{

    }
}


int main() {

    int tmp = 100000;
    int a=2;
    for(int i=0;i<tmp;i++){
        for(int j=0;j<tmp;j++){
            if(i&1)a++;
            else a--;
        }
    }

    char first[1000];
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%s",first);
        mystrrev(first);
        printf("%s",getAns(first));
    }

    return 0;
}
