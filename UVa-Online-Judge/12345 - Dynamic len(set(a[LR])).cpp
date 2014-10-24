#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
#define N 50005
#define M 1000005
int n , m , a[N];
int L[N] , tmp[M];
set<int> hash[M];
set<int>::iterator it1 , it2;
int c[N];
#define Node 8388608
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
int ch[Node][2] , sum[Node] , nodecnt;

int newnode()
{
    ++ nodecnt;
    ch[nodecnt][0] = ch[nodecnt][1] = sum[nodecnt] = 0;
    return nodecnt;
}

void add(int& p , int l , int r , int x , int w)
{
    if (!p) p = newnode();
    if (l == r)
        sum[p] += w;
    else
    {
        MID;
        if (x <= mid)
            add(ch[p][0] , Left , x , w);
        else
            add(ch[p][1] , Right , x , w);
        sum[p] = sum[ch[p][0]] + sum[ch[p][1]];
    }
}

void add(int x , int w , int val)
{
    for (int i = x ; i <= n ; i += i & -i)
        add(c[i] , 0 , n , w , val);
}
int PP[50] , MM[50] , sp , sm;
int query(int l , int r , int K)
{
    int cnt = 0;
    if (l == r)
    {
        for (int i = 0 ; i < sp ; ++ i) cnt += sum[PP[i]];
        for (int i = 0 ; i < sm ; ++ i) cnt -= sum[MM[i]];
        return cnt;
    } MID;
    for (int i = 0 ; i < sp ; ++ i) cnt += sum[ch[PP[i]][0]];
    for (int i = 0 ; i < sm ; ++ i) cnt -= sum[ch[MM[i]][0]];
    if (mid < K)
    {
        for (int i = 0 ; i < sp ; ++ i) PP[i] = ch[PP[i]][1];
        for (int i = 0 ; i < sm ; ++ i) MM[i] = ch[MM[i]][1];
        return cnt + query(Right , K);
    }
    else
    {
        for (int i = 0 ; i < sp ; ++ i) PP[i] = ch[PP[i]][0];
        for (int i = 0 ; i < sm ; ++ i) MM[i] = ch[MM[i]][0];
        return query(Left , K);
    }
}

void work()
{
    int i , j , x , y , k;
    char str[5];
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , hash[a[i]].insert(i);
    for (i = 1 ; i <= n ; ++ i)
        L[i] = tmp[a[i]] , tmp[a[i]] = i , add(i , L[i] , 1);

    while (m --)
    {
        scanf("%s" , str);
        //for (i = 1 ; i <= n ; ++ i)printf("%d%c" , L[i] , " \n"[i == n]);
        if (*str == 'Q')
        {
            scanf("%d%d",&x,&y);
            sp = 0 ; for (j = y ; j ; j -= j & -j) PP[sp ++] = c[j];
            sm = 0 ; for (j = x ; j ; j -= j & -j) MM[sm ++] = c[j];
            printf("%d\n" , k = query(0 , n , x));
            //if (k < 0) cerr << x << " " << y << endl;
        }
        else
        {
            scanf("%d%d",&x,&y) , ++ x;
            if (a[x] == y) continue;
            it1 = hash[a[x]].upper_bound(x);
            if (it1 != hash[a[x]].end())
            {
                j = *it1;
                add(j , L[j] , -1);
                L[j] = L[x];
                add(j , L[j] , 1);
            }
            add(x , L[x] , -1);
            if (hash[y].empty())
                L[x] = 0 , add(x , L[x] , 1);
            else
            {
                it1 = it2 = hash[y].upper_bound(x);
                if (it2 != hash[y].begin()) -- it2;
                if (it1 == hash[y].end())
                    L[x] = *it2 , add(x , L[x] , 1);
                else if (it1 == hash[y].begin())
                {
                    L[x] = 0 , add(x , L[x] , 1);
                    j = *it1;
                    add(j , L[j] , -1);
                    L[j] = x;
                    add(j , L[j] , 1);
                }
                else
                {
                    j = *it1;
                    L[x] = L[j] , add(x , L[x] , 1);
                    add(j , L[j] , -1);
                    L[j] = x;
                    add(j , L[j] , 1);
                }
            }
            hash[a[x]].erase(x);
            a[x] = y;
            hash[a[x]].insert(x);
        }
    }
}

int main()
{
    work();
    return 0;
}
