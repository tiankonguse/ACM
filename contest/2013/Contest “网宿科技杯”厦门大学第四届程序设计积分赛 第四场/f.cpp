/*************************************************************************
    > File Name: f.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/4 20:38:55
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
struct P{
    int x,y,n;
    P(){}
    P(int x,int y,int n):x(x),y(y),n(n){}
    void init(int x,int y,int n){
        this->x=x;
        this->y=y;
        this->n=n;
    }
}now;
const char c = '\0';
int N;
int _map[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct cmp{
    bool operator()(const P &t1,const P &t2){
    	return t1.n>t2.n;
    }
};

priority_queue<P,vector<P>,cmp>heap;
char str[5550][5550];

void add(int x,int y,int n){
    heap.push(P(x,y,n));
    str[x][y] = c;
}

bool dfs(int x,int y,int n){
    int _x,_y,_n;
    for(int i=0;i<4;i++){
        _x = x + _map[i][0];
        _y = y + _map[i][1];
        if(str[_x][_y] == c)continue;
        if(_x == N && _y == N){
            str[N][N] = n;
            return true;
        }

        if(str[_x][_y] == '0'){
            add(_x,_y,n);
            if(dfs(_x,_y,n))return true;
        }else{
            add(_x,_y,n+1);
        }
    }
    return false;
}

int main() {
    int n,i,j;
    while(~scanf("%d",&n)){
        N = n;
        memset(str,c,sizeof(str));
        for(i=1;i<=n;i++){
            scanf("%s",str[i]+1);
            str[i][n+1]=c;
        }

        while(!heap.empty())heap.pop();
        add(1,1,0);

        while(1){
            now = heap.top();heap.pop();
            if(dfs(now.x,now.y,now.n))break;
        }
        printf("%d\n",str[N][N]);
    }
    return 0;
}
