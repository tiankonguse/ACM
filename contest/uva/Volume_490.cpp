/*************************************************************************
    > File Name: Volume_1_490.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/15 16:02:21
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

char str[111][111];
int len[111];
int n;

char ans[111];

void output(int k){
    int pos = 0;
    for(int i=n-1,j=0;i>=0;i--,j++){
        if(k<len[i]){
            pos = j+1;
            ans[j] = str[i][k];
        }else{
            ans[j] = ' ';
        }
    }
    ans[pos] = '\0';
    puts(ans);
}

int main() {
    int maxLen=0,i;
    n = 0;
    while(gets(str[n])){
        len[n] = strlen(str[n]);
        maxLen = max(maxLen,len[n]);
        n++;
    }
    for(i=0;i<maxLen;i++){
        output(i);
    }


    return 0;
}

