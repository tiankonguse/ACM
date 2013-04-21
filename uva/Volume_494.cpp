/*************************************************************************
    > File Name: Volume_1_494.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/15 11:07:06
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

bool isalphabet(char c){
    return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

int main() {
    char str[10000];
    int i,ans,begin;
    while(gets(str)){
        i = ans = 0;
        begin = false;
        while(str[i]){
            if(isalphabet(str[i])){
                if(!begin){
                    begin = true;
                    ans++;
                }
            }else{
                begin = false;
            }
            i++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
