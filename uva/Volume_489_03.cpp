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
    char wrongNum ,i,cas,firstNum,secondNum,j;
    char in[110000];
    char out[110000];
    int first[3000];
    bool find;

    while(scanf("%d",&cas)!=EOF&&cas>0){
		getchar();
		printf("Round %d\n",cas);
		gets(in);
		gets(out);
//    while(scanf("%d",&cas),cas+1){
//        scanf("%s",in);
//        memset(first,-1,sizeof(first));
//        firstNum = 0;
//        for(i=0;in[i];i++){
//            统计字母的个数
//            if(first[in[i]] == -1){
//                first[in[i]] = 1;
//                firstNum++;
//            }
//        }

//        scanf("%s",out);
        wrongNum  = 0;
        secondNum = strlen(in);

        for(i=0;out[i];i++){

            find = false;

            for(j=0;in[j];++j){
                if(out[i] == in[j]){
                    find = true;
                    in[j] = '0';
                    secondNum--;
                }
            }

            if(!find){
                wrongNum++;
                if(wrongNum  == 7)break;
            }

            if(secondNum == 0){
                break;
            }
//
//            if(first[in[i]] == 1){
//                //猜对了
//                secondNum++;
//                //全猜对了
//                if(secondNum == firstNum)break;
//                first[in[i]] = -1;
//            }else{
//                //猜错了
//                wrongNum++;
//                //错的太多了
//                if(wrongNum  == 7)break;
//            }
        }

//        printf("%d %d %d\n",wrongNum,secondNum,j);

//        printf("Round %d\n",cas);

        if(wrongNum  == 7){
            printf("You lose.\n");
        }else if(secondNum == 0){
            printf("You win.\n");
        }else{
            printf("You chickened out.\n");
        }


    }

    return 0;
}

/*
1
a
ab

1
aab
aaaaaaaa

1
aaa
aaaaaaaa


*/
