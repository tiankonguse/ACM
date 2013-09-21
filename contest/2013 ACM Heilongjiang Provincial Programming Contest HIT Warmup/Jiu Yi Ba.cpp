/*************************************************************************
    > File Name: Jiu Yi Ba.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 17:45:23
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
int str[9999];
char name[10][10] = { "Monday", "Tuesday", "Wednesday",
                 "Thursday", "Friday", "Saturday", "Sunday"
               };

int  get(int d, int m, int y){
    int a;
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    if ((y < 1752) || (y == 1752 && m < 9) ||
            (y == 1752 && m == 9 && d < 3))
        a = (d + 2*m + 3*(m+1)/5 + y + y/4 +5) % 7;
    else
        a = (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400)%7;
    return a;
}



int main(void) {
    int n=0,i;
    while(~scanf("%d",&str[n]))n++;;
    sort(str,str+n);
    for(i=0;i<n;i++){
        printf("%d-09-18 %s\n",str[i],name[get(18,9,str[i])]);
    }
    printf("Never forget 9-18, folks.\n");
    return 0;
}

