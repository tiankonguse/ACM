#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;

char str[1000010];

int main() {
    printf("hello word\n");
    int t;
    scanf("%d", &t);
    printf("nexr\n");
    while(t--) {
        scanf("%s", str);
        int one = 0, zero = 0;
        for(int i=0; str[i]; i++){
            if(str[i] == '0'){
                zero++;
            }else{
                one++;
            }
        }

        //001
        if(zero == one * 2){ // 2k
            while(one--){
                printf("001");
            }
            printf("\n");
        }else if(zero == one*2 + 1){ // 2k + 1
            while(one--){
                printf("001");
            }
            printf("0\n");
        }else if(zero == one*2 + 2){ // 2k + 2
            while(one--){
                printf("001");
            }
            printf("00\n");
        }else if(zero == one*2 - 1){  // 2k - 1
            one--;
            while(one--){
                printf("010");
            }
            printf("01\n");
        }else if(zero%2 == 0 && one >= zero/2){ // a * 1 + b * (100)
            int pre = one - zero/2;
            while(pre--){
                printf("1");
                one--;
            }
            while(one--){
                printf("100");
            }
            printf("\n");
        }else if(zero%2 == 1 && one >= (zero+1)/2){  // a * 1 + b * (100) + 10
            int pre = one - (zero + 1)/2;
            while(pre--){
                printf("1");
                one--;
            }
            while(one > 1){
                printf("100");
                one--;
            }

            printf("10\n");
        }else{
            printf("Impossible\n");
        }


    }


    return 0;
}
