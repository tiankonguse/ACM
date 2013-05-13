/*************************************************************************
    > File Name: G 1477.整容院杀人事件.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 16:05:00
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
    char str[111],tmp[111];
    int n,m,i,j;
    while(~scanf("%d%d",&n,&m)){
        memset(str,0,sizeof(str));
        for(j=0;j<=n;j++){
            scanf("%s",tmp);
            for(i=0;i<m;i++){
                str[i] ^= tmp[i];
            }
        }
        printf("%s\n",str);
    }
    return 0;
}
