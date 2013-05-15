/*************************************************************************
    > File Name: ACompression.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/14 18:10:09
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
int _root(int n){
	return n?(n+8)%9+1:0;
}
char str[1000006];

int main() {
     int i,j,n;
     scanf("%d",&n);
     while(n--)
     {
         scanf("%s",str);
         int len = strlen(str);
         int sum=0;
         for(i=0;i<len;i++)
           sum += (str[i]-'0');
        printf("%d\n",_root(sum));
     }
    return 0;
}
