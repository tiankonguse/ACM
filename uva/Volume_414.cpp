/*************************************************************************
    > File Name: Volume_1_414.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/15 11:28:04
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
    char str[26];

    int n,i,allBlank,minBlank,j,nowBlank;

    while(scanf("%d",&n),n){
        gets(str);
        minBlank = 25;
        allBlank = 0;
        for(i=0;i<n;i++){
            gets(str);
            nowBlank = 0;
            for(j=0;str[j];j++){
                if(str[j] != 'X')nowBlank++;
            }

            minBlank = min(minBlank,nowBlank);

            allBlank += nowBlank;
        }

        printf("%d\n",allBlank - minBlank * n);

    }


    return 0;
}
