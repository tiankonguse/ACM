#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;
#define M 16777216
int n , m , nodecnt;
int ch[M][2];
LL LK[M] , LB[M];
LL K[M] , B[M];

int newnode() {
    ++ nodecnt;
    K[nodecnt] = 0 , B[nodecnt] = -1LL << 60;
    return nodecnt;
}
#define MID int mid = (l + r) >> 1
#define Left l , mid
#define Right mid + 1 , r

void add(int& p , int l , int r , int top , int bot , LL a , LL b) {
    if (!p) p = newnode();
    if (top <= l && r <= bot) {
        LK[p] += a , LB[p] += b;
        return;
    } MID;
    if (top <= mid) add(ch[p][0] , Left , top , bot , a , b);
    if (bot > mid) add(ch[p][1] , Right , top , bot , a , b);
}
void update(int& p , int l , int r , int top , int bot , LL a , LL b) {
    if (!p) p = newnode();
    if (top <= l && r <= bot) {
        bool f1 = K[p] * l + B[p] >= a * l + b;
        bool f2 = K[p] * r + B[p] >= a * r + b;
        if (f1 && f2)
            return;
        else if (!f1 && !f2) {
            K[p] = a , B[p] = b;
            return;
        } else {
            MID;
            bool f3 = K[p] * mid + B[p] >= a * mid + b;
            if (f1) {
                if (f3)
                    update(ch[p][1] , Right , Right , a , b);
                else {
                    update(ch[p][0] , Left , Left , K[p] , B[p]);
                    K[p] = a , B[p] = b;
                }
            } else {
                if (f3)
                    update(ch[p][0] , Left , Left , a , b);
                else {
                    update(ch[p][1] , Right , Right , K[p] , B[p]);
                    K[p] = a , B[p] = b;
                }
            }
        }
        return;
    } MID;
    if (top <= mid) update(ch[p][0] , Left , top , bot , a , b);
    if (bot > mid) update(ch[p][1] , Right , top , bot , a , b);
}

pair<LL , LL> ans;
void query(int p , int l , int r , int x) {
    if (!p) return;
    ans.first += LK[p] * x + LB[p];
    ans.second = max(ans.second , K[p] * x + B[p]);
    if (l == r) return; MID;
    if (x <= mid)
        query(ch[p][0] , Left , x);
    else
        query(ch[p][1] , Right , x);
}

int main()
{
    int root = 0 , i , u , v ;
    LL a , b;
    scanf("%d%d",&n,&m);
    while (m --) {
        scanf("%d",&i);
        if (i == 3) {
            scanf("%d",&u);
            ans = make_pair(0 , -1LL << 60);
            query(root , 0 , n - 1 , u - 1);
            if (ans.second <= -1LL << 60)
                puts("NA");
            else
                printf("%lld\n" , ans.first + ans.second);
        } else {
            scanf("%d%d%lld%lld",&u,&v,&a,&b);
            -- u , -- v;
            b -= a * u;
            if (i == 1)
                update(root , 0 , n - 1 , u , v , a , b);
            else
                add(root , 0 , n - 1 , u , v , a , b);
        }
    }
    return 0;
}
