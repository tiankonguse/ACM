/*************************************************************************
    > File Name: A.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 11:00:41
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
#include<cmath>
using namespace std;

int main() {
    int i;
    char op[10];
    double list[10],humidex,e,h;
    while(scanf("%s",op)!=EOF&&op[0]!='E'){
        memset(list,0,sizeof(list));

        if(op[0]=='T'){
            scanf("%lf",&list[1]);
        }else if(op[0]=='D'){
            scanf("%lf",&list[2]);
        }else if(op[0]=='H'){
            scanf("%lf",&list[3]);
        }
        scanf("%s",op);

        if(op[0]=='T'){
            scanf("%lf",&list[1]);
        }else if(op[0]=='D'){
            scanf("%lf",&list[2]);
        }else if(op[0]=='H'){
            scanf("%lf",&list[3]);
        }

        for(i=1;i<=3;i++){
            if(list[i]==0)break;
        }
        if(i==1){
            e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(list[2]+273.16))));
            h = (0.5555)* (e - 10.0);
            list[1] = list[3] - h;
        }else if(i==2){
            h = list[3] - list[1];
            e = h/0.5555+10.0;
            list[2] = 1/((1/273.16) - log (e/6.11)/5417.7530)-273.16;
        }else if(i==3){
            e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(list[2]+273.16))));
            h = (0.5555)* (e - 10.0);
            list[3] = list[1] + h;
        }
        printf("T %.1f D %.1f H %.1f\n",list[1],list[2],list[3]);
    }
    return 0;
}
