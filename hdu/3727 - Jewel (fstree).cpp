#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
#define N 200005
#define Node 2000005
int n , m , ca , root[N];
int d[N] , D;
int a1[N] , a2[N] , a3[N] , a4[N];
#define MID int mid = (LL)l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
int ch[Node][2] , sum[Node] , nodecnt;
int newnode(int val)
{
    ++ nodecnt;
    ch[nodecnt][0] = ch[nodecnt][1] = 0 ;
    sum[nodecnt] = val;
    return nodecnt;
}
void add(int& p , int q , int l , int r , int x , int w)
{
    if (!p) p = newnode(sum[q]);sum[p] += w;
    if (l != r)
    {
        MID;
        if (x <= mid)
            ch[p][1] = ch[q][1] , add(ch[p][0] , ch[q][0] , Left , x , w);
        else
            ch[p][0] = ch[q][0] , add(ch[p][1] , ch[q][1] , Right , x , w);
    }
}
int query(int p , int q , int l , int r , int K)
{
    if (l == r) return l; MID;
    int cnt = sum[ch[p][0]] - sum[ch[q][0]];
    if (cnt >= K)
        return query(ch[p][0] , ch[q][0] , Left , K);
    else
        return query(ch[p][1] , ch[q][1] , Right , K - cnt);
}
int Rank(int p , int l , int r , int x)
{
    if (l == r) return sum[p]; MID;
    if (x <= mid)
        return Rank(ch[p][0] , Left , x);
    else
        return sum[ch[p][0]] + Rank(ch[p][1] , Right , x);;
}
void work()
{
    int i , j , k , x , y;
    char str[20];
    n = nodecnt = D = 0 , memset(root , 0 , sizeof(root));
    long long ans1 = 0 , ans2 = 0 , ans3 = 0;
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%s" , str);
        if (*str == 'I')
        {
            a1[i] = 1 , scanf("%d",&a2[i]);
            d[D ++] = a2[i];
        }
        else if (*(str + 6) == '1')
        {
            a1[i] = 2;
            scanf("%d%d%d",&a2[i],&a3[i],&a4[i]);
        }
        else if (*(str + 6) == '2')
        {
            a1[i] = 3 , scanf("%d",&a2[i]);
            d[D ++] = a2[i];
        }
        else if (*(str + 6) == '3')
        {
            a1[i] = 4 , scanf("%d",&a2[i]);
        }
    }
    sort(d , d + D) , D = unique(d , d + D) - d;
    for (i = 1 ; i <= m ; ++ i)
    {
        if (a1[i] == 1)
        {
            ++ n , x = lower_bound(d , d + D , a2[i]) - d + 1;
            add(root[n] , root[n - 1] , 1 , D , x , 1);
        }
        if (a1[i] == 2)
        {
            x = a2[i] , y = a3[i] , k = a4[i];
            ans1 += d[query(root[y] , root[x - 1] , 1 , D , k) - 1];
        }
        if (a1[i] == 3)
        {
            x = lower_bound(d , d + D , a2[i]) - d + 1;
            ans2 += Rank(root[n] , 1 , D , x);
        }
        if (a1[i] == 4)
        {
            k = a2[i];
            ans3 += d[query(root[n] , root[0] , 1 , D , k) - 1];
        }
    }
    printf("Case %d:\n%I64d\n%I64d\n%I64d\n" , ++ ca , ans1 , ans2 , ans3);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    while (~scanf("%d",&m))
        work();
    return 0;
}
