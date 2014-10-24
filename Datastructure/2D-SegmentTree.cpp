#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define N 505
int n , m , Q;
int mx[N << 1][N << 1] , mn[N << 1][N << 1];
pair<int , int> A , B;
int val , LL , RR , Max , Min;

inline int id(int l , int r) {return l + r | l != r;}
#define MID int mid = (l + r) >> 1
#define Left l , mid
#define Right mid + 1 , r

void QUERY(int p , int l , int r) {
    int q = id(l , r);
    if (B.first <= l && r <= B.second) {
        Max = max(Max , mx[p][q]);
        Min = min(Min , mn[p][q]);
        return;
    } MID;
    if (B.first <= mid)
        QUERY(p , Left);
    if (B.second > mid)
        QUERY(p , Right);
}

void query(int l , int r) {
    int p = id(l , r);
    if (A.first <= l && r <= A.second) {
        QUERY(p , 1 , m);
        return;
    } MID;
    if (A.first <= mid)
        query(Left);
    if (A.second > mid)
        query(Right);
}

void UPDATE(int p , int l , int r) {
    int q = id(l , r);
    if (l == r) {
        if (p & 1) {
            mx[p][q] = max(mx[LL][q] , mx[RR][q]);
            mn[p][q] = min(mn[LL][q] , mn[RR][q]);
        } else {
            mx[p][q] = mn[p][q] = val;
        }
        return;
    } MID;
    if (A.second <= mid)
        UPDATE(p , Left);
    else
        UPDATE(p , Right);
    mx[p][q] = max(mx[p][id(Left)] , mx[p][id(Right)]);
    mn[p][q] = min(mn[p][id(Left)] , mn[p][id(Right)]);
}

void update(int l , int r) {
    int p = id(l , r);
    if (l == r) {
        UPDATE(p , 1 , m);
        return;
    } MID;
    if (A.first <= mid)
        update(Left);
    else
        update(Right);
    LL = id(Left) , RR = id(Right);
    UPDATE(p , 1 , m);
}

void work()
{
    int i , j;
    char str[5];
    scanf("%d%d",&n,&m);
    memset(mx , 0x80 , sizeof(mx));
    memset(mn , 0x7F , sizeof(mn));
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j) {
            scanf("%d",&val);
            A = make_pair(i , j);
            update(1 , n);
        }
    scanf("%d",&Q);
    while (Q --) {
        scanf("%s" , str);
        if (*str == 'c') {
            scanf("%d%d%d",&A.first , &A.second , &val);
            update(1 , n);
        } else {
            scanf("%d%d%d%d",&A.first , &B.first , &A.second , &B.second);
            Max = -1 << 30 , Min = 1 << 30;
            query(1 , n);
            printf("%d %d\n" , Max , Min);
        }
    }
}

int main()
{
    work();
    return 0;
}

