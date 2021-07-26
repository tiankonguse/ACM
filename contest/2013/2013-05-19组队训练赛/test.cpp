/*************************************************************************
    > File Name: test.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/21 18:55:38
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

char str[][20]={
"00000000"
,"01111110"
,"01111000"
,"01110010"
,"01100110"
,"01100000"
,"01001110"
,"01001000"
,"01000010"
,"00011110"
,"00011000"
,"00010010"
,"00000110"
,"11111111"
,"11111100"
,"11111001"
,"11110011"
,"11110000"
,"11100111"
,"11100100"
,"11100001"
,"11001111"
,"11001100"
,"11001001"
,"11000011"
,"11000000"
,"10011111"
,"10011100"
,"10011001"
,"10010011"
,"10010000"
,"10000111"
,"10000100"
,"10000001"
,"00111111"
,"00111100"
,"00111001"
,"00110011"
,"00110000"
,"00100111"
,"00100100"
,"00100001"
,"00001111"
,"00001100"
,"00001001"
,"00000011"
,"10001101"
,"10110001"
,"00110110"
,"10110111"
,"10110100"
,"10111101"
,"10100101"
,"01101100"
,"11101101"
,"00101101"
,"00011011"
,"01100011"
,"01101111"
,"01101001"
,"01111011"
,"01001011"
,"11000110"
,"11011000"
,"01011010"
,"11011011"
,"11011110"
,"11010010"
,"11110110"
,"10010110"
,"2"};

int cmp(void const *a,void const *b){
    return strcmp((const char*)a,(const char *)b);
}
void setBit(int& now,int bit,int val = 1){
    bit--;
    if(val == 1){
        now |= (1<<bit);
    }else{
        now &= ~(1<<bit);
    }
}
int getBit(int now,int bit){
    bit--;
    return (now>>bit)&1;
}
void outputState(int c){
    printf(",\"");
    for(int i=8;i;i--){
        printf("%d",getBit(c,i));
    }
    printf("\"\n");
}

int main() {

    outputState(255);

//    int now = 0;
//    setBit(now,8,1);
//    printf("%d\n",now);
//    setBit(now,8,0);
//    printf("%d\n",now);

    int i,len;
    for(i=0;str[i][0]!='2';i++);
    len = i;
//    printf("i=%d\n",i);
    qsort(str,len,sizeof(str[0]),cmp);
    for(i=0;i<len;i++){
//        printf("%d %s\n",i,str[i]);
    }
//    puts("---");
    for(i=1;i<len;i++){
        if(strcmp(str[i-1],str[i])==0){
//            printf("%d %d\n",i,i-1);
        }

    }

    return 0;
}
