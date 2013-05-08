/*************************************************************************
    > File Name: sprintf.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/5 20:35:38
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
     char str[100]={"1 2 3 4"};
    int a,b,c,d;
//    sscanf(str,"%d%d%d%d",&a,&b,&c,&d);
//    printf("%d %d %d %d\n",a,b,c,d);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    sprintf(str,"%d:%d:%d:%d",a,b,c,d);
    printf("%s",str);
//    printf("%d %d %d %d",a,b,c,d);
    return 0;
}
