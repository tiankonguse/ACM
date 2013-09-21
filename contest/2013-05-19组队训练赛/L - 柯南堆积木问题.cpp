/*************************************************************************
    > File Name: L - 柯南堆积木问题.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/21 17:17:38
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

bool state[513];
int _map[513];
int _map_num;


void setBit(int& now,int bit){
    bit--;
    now |= (1<<bit);
}

int getBit(int now,int bit){
    bit--;
    return (now>>bit)&1;
}

void outputState(int c){
//    printf("c=%d ",tmp);
    for(int i=8;i;i--){
        printf("%d",getBit(c,i));
    }
    printf("\n");
}

void addState(int c){
    if(state[c] == false){
        state[c] = true;
        outputState(c);
        _map[_map_num++] = c;
    }
}


void rightOneBit(int& now){
    int tmp = now & 1;
    now >>= 1;
    now |= tmp<<7;
}

void StateFunction(int now){
    int tmp = now;
    addState(now);
    rightOneBit(now);
    while(tmp != now){
        addState(now);
        rightOneBit(now);
    }
}

void bornState(){

    memset(state,false,sizeof(state));
    int now = 0,tmp,i;
    _map_num = 0;

    now = 0;
    StateFunction(now);
    puts("");

    //2
    now = 0;
    for(i=8;i>6;i--){
        setBit(now,i);
    }
    StateFunction(now);
    puts("");

    //4
    now = 0;
    for(i=8;i>4;i--){
        setBit(now,i);
    }
    StateFunction(now);
    puts("");

    now = 0;
    for(i=8;i>6;i--){
        setBit(now,i);
    }
    for(i=4;i>2;i--){
        setBit(now,i);
    }
    StateFunction(now);
    puts("");


    //6
    now = 0;
    for(i=8;i>2;i--){
        setBit(now,i);
    }
    StateFunction(now);

    //8
    now = 0;
    for(i=8;i>0;i--){
        setBit(now,i);
    }
    StateFunction(now);
}



int main() {

    bornState();
    printf("%d\n",_map_num);




    return 0;
}
