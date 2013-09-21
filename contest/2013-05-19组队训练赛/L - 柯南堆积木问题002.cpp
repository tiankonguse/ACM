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
typedef unsigned long long TT;
const int N=80;
const int sz = 70;
const int mod = 1000000007;

bool state[513];
int _map[513];
int _map_num;
int str[513][513];
int _val_map[513];

//第bit位置为1 val,val可以是0或1，bit是1~8
void setBit(int& now,int bit,int val = 1) {
    bit--;
    if(val == 1) {
        now |= (1<<bit);
    } else {
        now &= ~(1<<bit);
    }
}
//得到第bit位的值
int getBit(int now,int bit) {
    bit--;
    return (now>>bit)&1;
}
//输出c的二进制
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
//判断now是否全1
bool isPutAll(int now) {
    return now == 255;
}
//深搜得到状态
void dfs(int lev,int now,int next) {
    int nextState,i;

    if(isPutAll(now)) {
        nextState = addState(next);
        str[lev][nextState]++;
        return ;
    }

    //视情况修改
    if(getBit(now,8) == 0 && getBit(now,1) == 0) {
        setBit(now,8,1);
        setBit(now,1,1);
        dfs(lev,now,next);
        setBit(now,8,0);
        setBit(now,1,0);
    }

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


struct Matrix {
    TT a[N][N];
    Matrix() {
        memset(a,0,sizeof(a));
    }
    void _union() {
        int l=sz;
        while(l--)a[l][l]=1;
    }
    void init(int _a[][513]) {
        for(int i=0; i<sz; i++) {
            for(int j=0; j<sz; j++) {
                a[i][j] = _a[i][j];
            }
        }
    }
    Matrix operator*(Matrix& B);
    Matrix pow(TT k);
};
Matrix Matrix::operator*(Matrix& B) {
    Matrix ret;
    for(int i=0; i<sz; i++)
        for(int j=0; j<sz; j++)
            for(int k=0; k<sz; k++)
                ret.a[i][j]=(ret.a[i][j]+a[i][k]*B.a[k][j]) %mod;
    return ret;
}

Matrix Matrix::pow(TT k) {
    Matrix ret;
    Matrix A=*this;
    ret._union();

    while(k) {
        if(k&1)ret=ret*A;
        A=A*A;
        k>>=1;
    }
    return ret;
}

int main() {

//    puts("****");
    bornState();
//    printf("%d\n",_map_num);

//    outputState(_map[_map_num-1]);
//    printf(" -> ");
//    for(int i=0;i<_map_num;i++){
//        printf("%02d",i);
//    }
//    puts("");
//    for(int i=0;i<_map_num;i++){
//        printf("%02d-> ",i);
//        for(int j=0;j<_map_num;j++){
//            printf("%d ",str[i][j]);
//        }
//        puts("");
//    }
//    outputState(_map[2]);


    Matrix matrix,ans;
    int n;
    matrix.init(str);
    while(~scanf("%d",&n)) {
        ans = matrix.pow(n);
        printf("%lld\n",ans.a[0][0]);
    }




    return 0;
}
