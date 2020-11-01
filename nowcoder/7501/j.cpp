#include<bits/stdc++.h>
using namespace std;


//1.bulid();2.query(a,b)；3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef int LL;
const int maxn = 1111;
LL kMaxVal = 0;

int maxNM;

struct SegTree {
    LL sign[maxn<<2];//
    LL minVal[maxn<<2];
    LL maxMal[maxn<<2];

    LL str[maxn];

    void PushUp(int rt) {
        minVal[rt] = min(minVal[rt<<1], minVal[rt<<1|1]);
        maxMal[rt] = max(maxMal[rt<<1], maxMal[rt<<1|1]);
    }
    void PushDown(int rt) {
        if (sign[rt]) {
            sign[rt<<1] += sign[rt];
            sign[rt<<1|1] += sign[rt];

            minVal[rt<<1] += sign[rt];
            minVal[rt<<1|1] += sign[rt];

            maxMal[rt<<1] += sign[rt];
            maxMal[rt<<1|1] += sign[rt];
            sign[rt] = 0;
        }
    }
    void bulid(int l=1,int r=maxNM,int rt=1) {
        sign[rt] = 0;
        if(l==r) {
            minVal[rt] = maxMal[rt] = str[l];
            return ;
        }
        int m=(l+r)>>1;
        bulid(lson);
        bulid(rson);
        PushUp(rt);
    }
    void update(int L,int R,int add,int l=1,int r=maxNM,int rt=1) {
        if(L<=l && r<=R) {
            sign[rt] += add;
            minVal[rt] += add;
            maxMal[rt] += add;
            return ;
        }
        PushDown(rt);
        int m = (l + r) >> 1;
        if (L <= m)
            update(L, R, add, lson);
        if (R > m)
            update(L, R, add, rson);
        PushUp(rt);
    }
    LL queryMin(int L,int R, int l=1,int r=maxNM,int rt=1) {
        //printf("L=%d R=%d flag=%d l=%d r=%d rt=%d\n",L,R,flag,l,r,r,rt);
        if (L <= l && r <= R) {
            return minVal[rt];
        }
        PushDown(rt);
        int m = (l + r) >> 1;
        LL ret = kMaxVal;
        if (L <= m) {
            ret = min(ret, queryMin(L, R, lson));
        }
        if (m < R) {
            ret = min(ret, queryMin(L, R, rson));
        }
        return ret;
    }
    LL queryMax(int L,int R, int l=1,int r=maxNM,int rt=1) {
        //printf("L=%d R=%d flag=%d l=%d r=%d rt=%d\n",L,R,flag,l,r,r,rt);
        if (L <= l && r <= R) {
            return maxMal[rt];
        }
        PushDown(rt);
        int m = (l + r) >> 1;
        LL ret = -1;
        if (L <= m) {
            ret = max(ret, queryMax(L, R, lson));
        }
        if (m < R) {
            ret = max(ret, queryMax(L, R, rson));
        }
        return ret;
    }
};



int n,m,a,b;

int str[maxn][maxn];

SegTree segTree[maxn];
SegTree lineSegTree;

bool checkLine(int i) {
    memset(lineSegTree.str, 0, sizeof(lineSegTree.str));
    for(int j = 1; j <= m; j++) {
        lineSegTree.str[j] = segTree[j].queryMin(i, i);
    }
    //printf("i=%d : ",i);
    //for(int j = 1; j <= m; j++) {
    //    printf("%d ",lineSegTree.str[j]);
    //}
    //printf("\n");
    //printf("i=%d bulid in\n",i);
    lineSegTree.bulid();
    for(int j = 1; j <= m - b + 1; j++) {
        int nowVal = lineSegTree.queryMin(j, j);
        int minVal = lineSegTree.queryMin(j, j + b - 1);
        //printf("query j=%d nowVal=%d minVal=%d\n", j, nowVal, minVal);
        if(nowVal > minVal) {
            return false;
        }
        if(nowVal == 0) {
            continue;
        }
        lineSegTree.update(j, j + b - 1, -nowVal);
    }

    int maxVal = lineSegTree.queryMax(1, m);
    //printf("max=%d\n", maxVal);
    if(maxVal != 0) {
        return false;
    }

    return true;
}

bool check() {
    // m 列，m 个线段树
    maxNM = max(n, m) + 20;
    for(int j = 1; j <= m; j++) {
        SegTree& colSegTree = segTree[j];
        memset(colSegTree.str, 0, sizeof(colSegTree.str));


        //printf("j=%d : ", j);
        for(int i = 1; i <= n; i++) {
            colSegTree.str[i] = str[i][j];
            //printf("%d ", str[i][j]);
        }
        //printf("\n");
        colSegTree.bulid();
    }

    //printf("init ok\n");

    // 大：0~n-1
    // 小：0~a-1, 1~a, ...,  n-a~n-1, i+1~i+a
    for(int i = 1; i <= n - a + 1; i++) {
        //printf("i=%d checkLine \n",i);
        if(!checkLine(i)) {
            return false;
        }

        //printf("i=%d checkLine pass\n",i);
        for(int j = 1; j <= m; j++) {
            int nowVal = segTree[j].queryMin(i, i);
            int minVal = segTree[j].queryMin(i, i+a-1);
            if(minVal < nowVal) {
                return false;
            }
            if(nowVal == 0) {
                continue;
            }
            segTree[j].update(i, i+a-1, -nowVal);
        }
    }

    for(int j = 1; j <= m; j++) {
        int maxVal = segTree[j].queryMax(1, n);
        if(maxVal != 0) {
            return false;
        }
    }

    return true;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d",&n,&m,&a,&b);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                scanf("%d", &str[i][j]);
                kMaxVal = max(kMaxVal, str[i][j]);
            }
        }
        printf("%s\n", check()?"^_^":"QAQ");
    }
    return 0;
}
