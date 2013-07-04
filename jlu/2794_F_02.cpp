/*************************************************************************
    > File Name: 2794_F_02.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/6/6 20:52:19
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

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

struct T {
    double k,a,b;
    void input() {
        scanf("%lf%lf%lf",&k,&a,&b);
    }
    void output() {
        printf("%lf %lf %lf\n",k,a, b);
    }
    bool operator < (const T &m)const {
        if(a != m.a){
            return a < m.a;
        }else{
            if(k == m.k){
                if(a == m.a){
                    return b < m.b;
                }else{
                    return a < m.a;
                }
            }else{
                return k < m.k;
            }
        }

    }
} str[100];

struct TT{
    int state;
    double left,right;
    int pos;
    void init(int _state, double _left, double _right, int _pos){
        state = _state,left = _left, right = _right, pos = _pos;
        if(left < 0 ){
            left = 0;
        }
        if(right >= 100){
            right = 100;
        }
    }
};
stack<TT>sta,statmp;

void init(){
    while(!sta.empty())sta.pop();
    while(!statmp.empty())statmp.pop();
}

void add(int pos){
    while(!statmp.empty())statmp.pop();

    TT now, tmp;
    double k = str[pos].k, a = str[pos].a, b = str[pos].b;

    double dir = sqrt((100 - b)/k);
    now.init(1, a - dir, b + dir, pos);

    while(!sta.empty()){
        tmp = sta.top();
        if(tmp.right <= now.left){
//            sta.push(TT(1,now.left,now.right,now.pos));
//            break;
        }





    }

    while(!statmp.empty()){
        sta.push(statmp.top());
        statmp.pop();
    }
}

int main() {

    int cas,n,i,j;
    scanf("%d",&cas);
    while(cas--) {
        scanf("%d",&n);
        for(i=0; i<n; i++) {
            str[i].input();
        }
        sort(str,str+n);
        for(i=0;i<n;i++){
            add(i);
        }
    }

    return 0;
}

/*
2
3
1 2 3
4 5 6
7 8 9
1
4 5 6
*/

