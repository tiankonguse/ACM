/*************************************************************************
    > File Name: Volume_445.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/15 16:22:26
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

char str[133][133];
char in[133000];


int main() {
    int i,num;
    while(gets(in)){
        if(strlen(in) == 0){
            putchar('\n');
        }else{
            i=0;
            while(in[i]){
                if(in[i] == '!'){
                    putchar('\n');
                }else{
                    num = 0;
                    while(in[i] >= '0' && in[i] <= '9')num += in[i++] - '0';
                    if(in[i] == 'b')in[i] = ' ';
                    while(num--){
                        putchar(in[i]);
                    }
                }
                i++;
            }
            putchar('\n');
        }
    }

    return 0;
}
