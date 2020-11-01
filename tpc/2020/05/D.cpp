#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

// 0x3f3f3f3f = 1061109567 (recommended)
const int inf = 0x3f3f3f3f;
// 0x3FFFFFFFFFFFFFFFLL = 4611686018427387903 (recommended)
const LL Inf = 0x3FFFFFFFFFFFFFFFLL;
// 10^9 + 7
const int mod = 1000000007;

//memset
//memset(dpMin, 0x3f, sizeof(dpMin)); // inf
//memset(dpMax, 0xc0, sizeof(dpMax)); // -inf

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

const int maxn = 100055;
char str[maxn];
int sign[maxn<<2];
int sum[8][maxn<<2];
int strIndex;
int n;

map<int, char> mC;
map<char, int> mI;

void init() {
    strIndex = 0;

    mI['r'] = 0x01;
    mI['y'] = 0x02;
    mI['b'] = 0x04;
    mI['o'] = mI['r'] | mI['y'];
    mI['p'] = mI['r'] | mI['b'];
    mI['g'] = mI['y'] | mI['b'];
    mI['x'] = mI['r'] | mI['y'] | mI['b'];

    for(auto&p : mI) {
        mC[p.second] = p.first;
    }
}

int operate(int a, int b) {
    if(a & b) {
        return b;
    } else {
        return a | b;
    }
}

char toC(int i) {
    return mC[i];
}
int toI(char c) {
    return mI[c];
}
void PushUp(int rt) {
    for(int i = 1; i <= 7; i++) {
        int l = i;
        int r = sum[l][rt<<1];
        sum[l][rt] = sum[r][rt<<1|1];
    }
}


void updateRange(int rt, int len, int val) {
    for(int i = 1; i <= 7; i++) {
        if(len == 1) {
            sum[i][rt] = operate(i, val);
        } else {
            sum[i][rt] = val;
        }
    }
}

void PushDown(int rt,int len) {
    if (sign[rt]) {
        updateRange(rt<<1, (len - (len >> 1)), sign[rt]);
        updateRange(rt<<1|1, (len >> 1), sign[rt]);

        sign[rt<<1] = sign[rt];
        sign[rt<<1|1] = sign[rt];
        sign[rt] = 0;
    }
}
void bulid(int l=1,int r=n,int rt=1) {
    sign[rt] = 0;
    if(l==r) {
        updateRange(rt, 1, toI(str[strIndex++]));
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson);
    bulid(rson);
    PushUp(rt);
}


void update(int L,int R,int v,int l=1,int r=n,int
            rt=1) {
    if(L<=l && r<=R) {
        sign[rt] = v;
        updateRange(rt, r - l + 1, v);
        return ;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) {
        update(L, R, v, lson);
    }
    if (R > m) {
        update(L, R, v, rson);
    }
    PushUp(rt);
}
int query(int L,int R,int l=1,int r=n,int rt=1, int c = 7) {
    if (L <= l && r <= R) {
        return sum[c][rt];
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int ret = c;
    if (L <= m) {
        ret = query(L, R, lson, ret);
    }
    if (m < R) {
        ret = query(L, R, rson, ret);
    }
    return ret;
}

int main() {
    int t, q, op, l, r;
    char strVal[10];
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n,&q);
        scanf("%s", str);

        init();
        bulid();
        while(q--) {
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d %d %s", &l, &r, strVal);
                update(l, r, toI(strVal[0]));
            } else {
                scanf("%d %d", &l, &r);
                printf("%c\n", toC(query(l, r)));
            }
        }

    }

    return 0;
}
