/*************************************************************************
    > File Name: Matchsticks.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/3 20:07:54
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

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 510000;
double sum[maxn<<2][2];
int n;

double (*fun[2]) (double,double);


double _min(double a, double b) {
    return min(a,b);
}
double _max(double a, double b) {
    return max(a,b);
}


void PushUp(int rt) {
    sum[rt][1]=max(sum[rt<<1][1],sum[rt<<1|1][1]);
    sum[rt][0]=min(sum[rt<<1][0],sum[rt<<1|1][0]);
}

void bulid(int l=1,int r=n,int rt=1) {
    if(l==r) { // 据题意做相关修改
        scanf("%lf",&sum[rt][1]);
        sum[rt][0] = sum[rt][1];
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson);
    bulid(rson);
    PushUp(rt);
}

double query(int op,int L,int R,int l=1,int r=n,int rt=1) {
    if(L<=l && r<=R) {
        return sum[op][rt];
    }
    int m=(l+r)>>1;
    double ret=-1,tmp=-1;
    if(L<=m) {
        ret = query(op,L,R,lson);
    }
    if(R> m) {
        tmp = query(op,L,R,rson);
    }

    if(ret < 0) {
        return tmp;
    } else if(tmp < 0) {
        return ret;
    } else {
        return fun[op](ret,tmp);
    }
}

void output(int l,int r) {

    double _tmp,_min,_max;
    _min = query(0,l,r);
    _max = query(1,l,r);
    _tmp = (_min + _max )/2.0;

    if(l==1) {
        if(r==n) {
            printf("%.1f\n",_tmp);
        } else {
            printf("%.1f\n",max(query(1,r+1,n)+_min, _tmp));
        }
    } else {
        if(r==n) {
            printf("%.1f\n",max(query(1,1,l-1)+_min, _tmp));
        } else {
            printf("%.1f\n",max(max(query(1,0,l-1), query(1,r+1,n)) + _min, _tmp));
        }
    }
}

int main() {
    int q,l,r;

    fun[0] = _min;
    fun[1] = _max;

    while(~scanf("%d",&n)) {
        bulid();
        scanf("%d",&q);
        while(q--) {
            scanf("%d%d",&l,&r);
            l++,r++;
            output(l,r);
        }
        break;
    }
    return 0;
}
