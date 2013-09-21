/*************************************************************************
    > File Name: Volume_489_02.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/16 12:54:44
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

    int cas,i, firstNum, secondNum, wrongNum;
    bool have[27];
    char in[100];





    while(scanf("%d",&cas),cas+1) {

        memset(have,true,sizeof(have));
        wrongNum = secondNum = firstNum = 0;

        //统计不同的字母的个数，并标记其位置，false代表有
        scanf("%s",in);
        for(i=0; in[i]; ++i) {
            if(have[in[i] - 'a']) {
                have[in[i] - 'a'] = false;
                ++firstNum;
            }
        }


        //统计猜测的字母
        //猜测正确，标记才对一次，然后把该字母标记为不存在
        //否则为猜错
        scanf("%s",in);
        for(i=0; in[i]; ++i) {
            if(!have[in[i] - 'a']) {
                ++secondNum;
                if(secondNum == firstNum)break;
                have[in[i] - 'a'] = true;
            } else {
                ++wrongNum;
                if(wrongNum == 7)break;
            }
        }

        printf("Round %d\n",cas);
        if(wrongNum == 7) {
            printf("You lose.\n");
        } else if(secondNum == firstNum) {
            printf("You win.\n");
        } else {
            printf("You chickened out.\n");
        }
    }
    return 0;
}
