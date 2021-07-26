/*************************************************************************
    > File Name: F.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 11:01:10
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
const int L = 11111;



void add(char* first, char* second){
    int first_len = strlen(first);
    int second_len = strlen(second);
    int i, j, tmp = 0;

    for(i = j = 0; i < first_len && j < second_len; i++,j++){
        tmp += (first[i] - '0' + second[j] - '0');
        first[i] = tmp%10 + '0';
        tmp /= 10;
    }

    if(j < second_len){
        while(j < second_len){
            tmp += (second[j++] - '0');
            first[i++] = tmp%10 + '0';
            tmp /= 10;
        }
    }else{
        while(i < first_len){
            tmp += (first[i] - '0');
            first[i++] = tmp%10 + '0';
            tmp /= 10;
        }
    }

    if(tmp){
        first[i++] = tmp%10 + '0';
    }
    first[i] = '\0';
}

void mystrrev(char *str){
    int l=0,r=strlen(str)-1;
    while(l<r){
        str[l] ^= str[r], str[r] ^= str[l], str[l] ^= str[r];
        l++,r--;
    }
}

void myprint(char *first){
    while(*first == '0')first++;
    if(*first == '\0')first--;
    printf("%s\n",first);
}

int main() {
    char first[L], second[L];
    scanf("%s",first);
    mystrrev(first);
    while(scanf("%s",second), !(second[0] == '0' && second[1] == '\0')){
        mystrrev(second);
        add(first,second);
    }
    mystrrev(first);
    myprint(first);
    return 0;
}
