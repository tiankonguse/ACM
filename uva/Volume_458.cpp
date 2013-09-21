/*************************************************************************
    > File Name: Volume_1_458.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/15 10:57:30
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

int main() {
    char str[10000];
    int i;
    while(gets(str)){
        i=0;
        while(str[i]){
            printf("%c",str[i]-7);
            i++;
        }
        puts("");
    }

    return 0;
}
