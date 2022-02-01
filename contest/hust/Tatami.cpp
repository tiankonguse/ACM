#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;

const int N = 1<<8;
const int ALL = N-1;
bool state[N];
int _map[N];
int _map_num;
int ALL;
int str[N][N];
int _val_map[N];
//第bit 位置为1 val,val 可以是0 或1,bit 是1 8
void setBit(int& now,int bit,int val = 1) {
    bit--;
    if(val == 1) {
        now |= (1<<bit);
    } else {
        now &= ~(1<<bit);
    }
}
//得到第bit 位的值
int getBit(int now,int bit) {
    bit--;
    return (now>>bit)&1;
}
//输出c 的二进制
void outputState(int c) {
    printf(",\"");
    for(int i=8; i; i--) {
        printf("%d",getBit(c,i));
    }
    printf("\"\n");
}
//添加状态c
int addState(int c) {
    if(state[c] == false) {
        state[c] = true;
        _map[_map_num] = c;
        _val_map[c] = _map_num;
        _map_num++;
    }
    return _val_map[c];
}

//判断now 是否全1
bool isPutAll(int now) {
    return now == ALL;
}
//深搜得到状态
/*
lev 第几个状态
now 当前状态的图形
next 下个状态的图形
*/
void dfs(int lev,int now,int next) {
    int nextState,i;
    if(isPutAll(now)) {
    	//lev 可以得到图形 next
        nextState = addState(next);
        str[lev][nextState]++;
        return ;
    }
//视情况修改
    for(i=8; i>0; i--) {
        if(getBit(now,i) == 0) {
            setBit(now,i,1);
            setBit(next,i,1);
            dfs(lev,now,next);
            setBit(now,i,0);
            setBit(next,i,0);
            break;
        }
    }
    for(i=8; i>1; i--) {
        if(getBit(now,i) == 0) {
            if(getBit(now,i-1) == 0) {
                setBit(now,i,1);
                setBit(now,i-1,1);
                dfs(lev,now,next);
                setBit(now,i,0);
                setBit(now,i-1,0);
            }
            break;
        }
    }
}
//生成状态
void bornState() {
    memset(state,false,sizeof(state));
    _map_num = 0;
    memset(str,0,sizeof(str));
    addState(0);
    for(int i=0; i<_map_num; i++) {
        dfs(i,_map[i],0);
    }
}



int main(int argc, char* argv[]) {


    return 0;
}






