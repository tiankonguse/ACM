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
using namespace std;
typedef long long LL;
#define N 4005
#define M 40005
int U[M] , D[M] , L[M] , R[M], col[M] , row[M];
//上下左右指针，节点所在行列编号。
int cnt , s[N];
//节点总数目，每列的节点数目。
#define FOR(i,A,s) for(int i = A[s]; i != s ; i = A[i])

void remove(int c)
{
    L[R[c]] = L[c] , R[L[c]] = R[c];
    FOR(i,D,c) FOR(j,R,i)
        U[D[j]] = U[j] , D[U[j]] = D[j] , -- s[col[j]];
}
void resume(int c)
{
    FOR(i,U,c) FOR(j,L,i)
        U[D[j]] = D[U[j]] = j , ++ s[col[j]];
    L[R[c]] = R[L[c]] = c;
}
bool res[N];
void dfs(int d , int sum)
{
    res[sum] = 1;
    if (R[0] == 0) {
        return;
    }
    int c = -1;
    FOR(i,R,0) if (s[i] && (!~c || s[i] > s[c])) c = i;
    if (!~c || !s[c]) return;
    remove(c);
    FOR(i,D,c)
    {
        //ans.pb(row[i]);
        FOR(j,R,i) remove(col[j]);
        dfs(d + 1 , sum - row[i]);
        FOR(j,L,i) resume(col[j]);
        //ans.pop_back();
    }
    resume(c);
}
int A , B , C , m , ca;
bool block[21][21][21];
int id[21][21][21];
void work()
{
    int i , j , k , x , y , z , S , ccnt;
    memset(block , 0 , sizeof(block));
    memset(res , 0 , sizeof(res));
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        block[x][y][z] = 1;
    }
    cnt = 1;
    for (i = 1 ; i <= A ; ++ i)
        for (j = 1 ; j <= B ; ++ j)
            for (k = 1 ; k <= C ; ++ k)
                if (!block[i][j][k])
                    id[i][j][k] = cnt ++;
    ccnt = cnt;
    for (i = 0 ; i < cnt ; ++ i)
        L[i] = i - 1 , R[i] = i + 1 , U[i] = i , s[i] = 0;
    L[0] = cnt - 1 , R[cnt - 1] = 0;
    for (S = min(A , min(B , C)) - 1 ; S >= 1 ; -- S) {
        int cube = (S + 1) * (S + 1) * (S + 1);
        for (i = 1 ; i + S <= A ; ++ i)
            for (j = 1 ; j + S <= B ; ++ j)
                for (k = 1 ; k + S <= C ; ++ k) {

                    bool found = 0;
                    for (x = i ; x <= i + S && !found ; ++ x)
                        for (y = j ; y <= j + S && !found ; ++ y)
                            for (z = k ; z <= k + S && !found ; ++ z)
                                if (block[x][y][z])
                                    found = 1;
                    if (found) continue;
                    for (x = i ; x <= i + S ; ++ x)
                        for (y = j ; y <= j + S ; ++ y)
                            for (z = k ; z <= k + S ; ++ z) {
                                int COL = id[x][y][z];
                                L[cnt] = cnt - 1 , R[cnt] = cnt + 1;
                                D[U[COL]] = cnt , U[cnt] = U[COL] , U[COL] = cnt;
                                col[cnt] = COL , row[cnt] = cube - 1 , ++ s[COL];
                                ++ cnt;
                            }
                    R[cnt - 1] = cnt - cube;
                    L[cnt - cube] = cnt - 1;
                }
    }
    for (i = 0 ; i < ccnt ; ++ i)
        D[U[i]] = i;
    dfs(0 , A * B * C - m);
    vector<int> ans;
    for (i = 0 ; i < ccnt ; ++ i)
        if (res[i])
            ans.push_back(i);
    printf("Case %d:" , ++ ca);
    for (i = 0 ; i < ans.size() ; ++ i)
        printf(" %d" , ans[i]);
    puts("");
}

int main()
{
    while (scanf("%d%d%d%d",&A,&B,&C,&m) , A || B || C || m)
        work();
    return 0;
}
/*
5 5 5 0
Case 1: 1 50 57 62 64 69 71 76 78 83 85 90 92 97 99 104 111 118 125
4 4 4 1
2 2 2
Case 2: 14 21 28 35 42 49 56 63
5 5 5 1
3 3 3
Case 3: 68 75 82 89 96 103 110 117 124
5 5 5 1
2 2 2
Case 4: 56 63 70 75 77 82 84 89 91 96 98 103 110 117 124
5 5 5 1
1 1 1
Case 5: 49 56 61 63 68 70 75 77 82 84 89 91 96 98 103 110 117 124
5 5 5 5
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
Case 6: 78 85 92 99 106 113 120
5 5 5 2
1 1 1
5 5 5
Case 2: 48 55 60 62 67 69 74 76 81 83 88 90 95 97 102 109 116 123
5 5 5
3
1 4 3
2 5 1
4 3 2
Case 3: 47 54 61 66 68 73 75 80 82 87 89 94 96 101 108 115 122
*/
