/*************************************************************************
    > File Name: Your Name is Mine.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/3 17:55:34
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

const int N = 25100;

char first[N],second[N];

bool is(char*p1,char*p2){

    while(*p1 && *p2){
        if(*p1 == *p2){
            p1++,p2++;
        }else{
            p2++;
        }
    }
    return !(*p1);
}

int main() {
    int len1,len2;
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s%s",first,second);
        len1 = strlen(first);
        len2 = strlen(second);

        if(len1 < len2){
            printf("%s\n",is(first,second)?"YES":"NO");
        }else{
            printf("%s\n",is(second,first)?"YES":"NO");
        }

    }


    return 0;
}
