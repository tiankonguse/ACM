/*************************************************************************
    > File Name: Name Reduction.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/3 18:15:11
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


int str1[300],str2[300];
char str[200100];

void add(int *to){
    scanf("%s",str);
    for(int i=0;str[i];i++){
        to[str[i]]++;
    }
}


bool is(int*pre,int*son){

    for(int i=0;i<300;i++){
        if(pre[i] < son[i])return false;
    }
    return true;
}

int main() {
    int t,n;
    scanf("%d",&t);

    while(t--){
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));

        add(str1);
        add(str1);

        scanf("%d",&n);
        while(n--){
            add(str2);
        }

        printf("%s\n",is(str1,str2)?"YES":"NO");

    }

    return 0;
}
