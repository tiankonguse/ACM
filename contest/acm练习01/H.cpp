/*************************************************************************
    > File Name: H.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 15:07:29
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


int mystrchr(char* str, char c){
    for(int i=0;;i++){
        if(str[i] == c)return i;
    }
}

void fun(char* front,char* mid,char* end, int len){

    if(len == 0)return ;

    end[len - 1] = front[0];

    if(len == 1)return ;

    int pos = mystrchr(mid, front[0]);
    fun(front + 1, mid, end, pos);
    fun(front + pos + 1 , mid +pos+1, end+pos, len - pos -1);

}

int main() {
    char front[33], mid[33], end[33];
    int len;
    while(~scanf("%s%s",front,mid)){
        len = strlen(front);
        end[len] = '\0';
        fun(front, mid, end, len);
        printf("%s\n",end);
    }
    return 0;
}
