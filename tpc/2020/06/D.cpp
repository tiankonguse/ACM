#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

// 0x3f3f3f3f = 1061109567 (recommended)
const int inf = 0x3f3f3f3f;
// 0x3FFFFFFFFFFFFFFFLL = 4611686018427387903 (recommended)
const LL Inf = 0x3FFFFFFFFFFFFFFFLL;
// 10^9 + 7
const int mod = 1000000007;

#define memsetMin(arr) memset(arr, 0xc0, sizeof(arr))
#define memsetMax(arr) memset(arr, 0x3f, sizeof(arr))

//memset
//memset(dpMin, 0x3f, sizeof(dpMin)); // inf
//memset(dpMax, 0xc0, sizeof(dpMax)); // -inf

char strT[1111111]; //一位数组储存多个字符串
char* nowT;
struct Op {
    char op[5];
    LL pos;
    LL c, a, b;
    char* pt;
};
Op ops[5555];

void input(int &q){
    nowT = strT;
    scanf("%s", nowT);
    Op* p = ops + 0;
    p->op[0] = '+';
    p->pt = nowT;
    nowT += strlen(nowT) + 1;

    scanf("%d", &q);
    for(int i=1; i<=q; i++) {
        Op* p = ops + i;
        scanf("%s", p->op);
        if(p->op[0] == '+') {
            scanf("%lld%s", &p->pos, nowT);
            p->pt = nowT;
            nowT += strlen(nowT) + 1;
        } else if(p->op[0] == '!') {
            scanf("%lld%lld%lld%lld", &p->a, &p->b, &p->c, &p->pos);
        } else if(p->op[0] == '?') {
            scanf("%lld", &p->pos);
        }
    }
}

map<int, pair<LL, char>> ans;

int main() {
    int t, q;
    scanf("%d", &t);
    while(t--) {
        input(q);
        ans.clear();
        for(int i=q;i>=0;i--){
            Op* p = ops + i;
            LL pos = p->pos;
            if(p->op[0] == '?'){
                ans[i].first = pos - 1;
                continue;
            }
            LL len = 0;
            if(p->op[0] == '+') {
                len = strlen(p->pt);
            }else{
                len = (p->b - p->a + 1) * p->c;
            }
            for(auto& kv: ans){
                auto& pp = kv.second;
                if(pp.first == -1 || pp.first < pos){ //已经找到答案，或者在 pos 之前
                    // do nothing
                }else if(pos <= pp.first && pp.first < pos + len ){ // 在插入的字符串 [pos, pos+len)之内
                    if(p->op[0] == '+'){
                        pp.second = p->pt[pp.first - pos];
                        pp.first = -1;
                    }else{
                        pp.first = p->a - 1 + (pp.first - pos) % (p->b - p->a + 1); //由于重复了 c 次，需要取模，计算在第几次
                    }
                }else{
                    pp.first -= len; //在字符串之后，需要前移
                }
            }
        }
        for(auto& kv: ans){
            printf("%c\n", kv.second.second);
        }

    }

    return 0;
}


