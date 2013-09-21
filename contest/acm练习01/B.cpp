/*************************************************************************
    > File Name: B.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 11:00:47
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

char x[1000];
char y[1000];
int l1[100];
int l2[100];

int main() {
    int i;
    while(scanf("%s%s",x,y)!=EOF){
        memset(l1,0,sizeof(l1));
        memset(l2,0,sizeof(l2));
        for(i=0;x[i];i++){
            l1[x[i]-'A']++;
        }
        for(i=0;y[i];i++){
            l2[y[i]-'A']++;
        }
        sort(l1,l1+26);
        sort(l2,l2+26);
        for(i=0;i<26;i++){
            if(l1[i]!=l2[i])break;
        }
        if(i==26)puts("YES");
        else puts("NO");;
    }
    return 0;
}
