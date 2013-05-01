/*************************************************************************
    > File Name: a.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 14:51:12
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
    int i,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("Unknown\n");break;
            case 2:printf("Spring Training\n");break;
            case 3:printf("Spring Training\n");break;
            case 4:printf("Spring Training\nBNU Contest\n");break;
            case 5:printf("Unknown\n");break;
            case 6:printf("Unknown\n");break;
            case 7:printf("Practice Week\nSummer Training\n");break;
            case 8:printf("Summer Training\n");break;
            case 9:printf("Regional Contest\n");break;
            case 10:printf("Regional Contest\n");break;
            case 11:printf("Basic Training\nRegional Contest\n");break;
            case 12:printf("Basic Training\nRookie Contest\n");break;
        }
    }
    return 0;
}
