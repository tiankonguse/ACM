/*************************************************************************
    > File Name: Volume_489.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/15 18:42:16
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

        memset(have,false,sizeof(have));
        wrongNum = secondNum = firstNum = 0;

        scanf("%s",in);
        for(i=0; in[i]; i++) {//统计字母的个数
            if(!have[in[i] - 'a']) {
                have[in[i] - 'a'] = true;
                firstNum++;
            }
        }

        scanf("%s",in);
        for(i=0; in[i]; i++) {
            if(have[in[i] - 'a']) {//猜对了
                secondNum++;
                if(secondNum == firstNum)break;
                have[in[i] - 'a'] = false;
            } else {//猜错了
                wrongNum++;
                if(wrongNum == 7)break;
            }
        }

        printf("Round %d\n",cas);
        if(wrongNum  == 7) {
            printf("You lose.\n");
        } else if(secondNum == firstNum) {
            printf("You win.\n");
        } else {
            printf("You chickened out.\n");
        }
    }
    return 0;
}
