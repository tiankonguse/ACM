#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define M 2000005
#define N 100005
struct cmplx
{
    double a , b;
    cmplx () {}
    void print() { printf("%f %f\n" , a , b); }
    cmplx (double x , double y) {a = x , b = y;}
    cmplx operator + (const cmplx& X) const{
        return cmplx(a + X.a , b + X.b);
    }
    cmplx operator * (const cmplx& X) const{
        return cmplx(a * X.a - b * X.b , a * X.b + b * X.a);
    }
    bool operator != (const cmplx& X) const{
        return a != X.a || b != X.b;
    }

};
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
const cmplx O(0 , 0) , I(1 , 0);
cmplx a[N];
pair<cmplx , cmplx> f[M] , null(I , O) , data;

int n , m , version;
int child[M][2] , root[N] , nodecnt;
char s[10];
int rub[M] , rs;
int newnode()
{
    int x;
    if (rs)
        x = rub[rs --];
    else
        x = ++ nodecnt;
    f[x] = null;
    child[x][0] = child[x][1] = 0;
    return x;
}

int Build(int l , int r)
{
    int p = newnode();
    if (l != r) {
        MID;
        child[p][0] = Build(Left);
        child[p][1] = Build(Right);
    }
    return p;
}
cmplx cal(cmplx A , pair<cmplx , cmplx> B)
{
    return B.first * A + B.second;
}
pair<cmplx , cmplx> cal(pair<cmplx , cmplx> A , pair<cmplx , cmplx> B)
{
    return make_pair(A.first * B.first , A.second * B.first + B.second);
}

int update(int l , int r , int q , int top , int bot , pair<cmplx , cmplx> w)
{
    int p = newnode();
    if (top <= l && r <= bot)
    {
        f[p] = cal(f[q] , w);
        child[p][0] = child[q][0];
        child[p][1] = child[q][1];
        return p;
    } MID;

    int LL = update(Left , child[q][0] , Left , f[q]);
    if (top <= mid)
    {
        child[p][0] = update(Left , LL , top , bot , w);
        rub[++ rs] = LL;
    }
    else
        child[p][0] = LL;
    int RR = update(Right , child[q][1] , Right , f[q]);
    if (bot > mid)
    {
        child[p][1] = update(Right , RR , top , bot , w);
        rub[++ rs] = RR;
    }
    else
        child[p][1] = RR;
    return p;
}

pair<cmplx , cmplx> query(int l , int r , int p , int x)
{
    if (l == r)
        return f[p];
    MID;
    if (x <= mid)
        return cal(query(Left , child[p][0] , x) , f[p]);
    else
        return cal(query(Right, child[p][1] , x) , f[p]);
}

void work()
{
    int i , j , x , y , l , r; double arc;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d%d",&x,&y) , a[i] = cmplx(x , y);
    root[version = 0] = Build(1 , n);
    scanf("%d",&m);
    while (m --)
    {
        scanf("%s" , s);
        if (*s == 'C' || *s == 'R')
            scanf("%d",&x) , version += *s == 'C' ? -x : x;
        if (*s == 'A')
        {
            scanf("%d",&x);
            cal(a[x] , query(1 , n , root[version] , x)).print();
        }
        if (*s == 'M' || *s == 'P' || *s == 'L')
        {
            scanf("%d%d",&l,&r);
            if (*s == 'M')
                scanf("%d%d",&x,&y) , data = make_pair(I , cmplx(x , y));
            if (*s == 'P')
                scanf("%lf",&arc) , data = make_pair(cmplx(cos(arc) , sin(arc)) , O);
            if (*s == 'L')
                data = make_pair(O , O);
            root[++ version] = update(1 , n , root[version - 1] , l , r , data);
        }
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //init();

    //while (~scanf("%d",&n))
        work();
    return 0;
}
