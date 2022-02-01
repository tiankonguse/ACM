#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 305
int A , B , n , m , ca;
double a[N][N];

void work() {
    scanf("%d%d",&A , &B);
    n = A + B;
    printf("Case %d: " , ++ca);
    memset(a , 0 , sizeof(a));
    a[0][0] = 1 , a[0][n + 1] = 0;
    a[n][n] = 1 , a[n][n + 1] = 0;
    int i , j , k;
    for (i = 1 ; i < n ; ++ i) {
        a[i][i] = 1 , a[i][n + 1] = 1;
        // i , n - i
        a[i][i + min(i , n - i)] = -0.5;
        a[i][i - min(i , n - i)] = -0.5;
    }
    m = n + 1 , n += 2;
    int rank = 0;
    for (i = 0 ; i < n ; ++ i) {
        int pivot = -1;
        for (j = rank ; j < m ; ++ j)
            if (!~pivot || (fabs(a[j][i]) > fabs(a[pivot][i])))
                pivot = j;
        if (pivot == -1) continue;
        for (j = 0 ; j < n ; ++ j)
            swap(a[rank][j] , a[pivot][j]);
        double tmp = a[rank][i];
        for (j = 0 ; j < n ; ++ j)
            a[rank][j] /= tmp;
        for (k = 0 ; k < m ; ++ k) {
            if (k != rank) {
                double times = a[k][i];
                for (j = 0 ; j < n ; ++ j) {
                    a[k][j] -= a[rank][j] * times;
                }
            }
        }
        ++ rank;
    }
    for (i = 0 ; i < m ; ++ i)
        if (fabs(a[i][A] - 1) < 1e-8) {
            printf("%f " , a[i][n - 1]);
            break;
        }
    n -= 2;
    memset(a , 0 , sizeof(a));
    a[0][0] = 1 , a[0][n + 1] = 0;
    a[n][n] = 1 , a[n][n + 1] = 1;
    for (i = 1 ; i < n ; ++ i) {
        a[i][i] = 1;
        // i , n - i
        a[i][i + min(i , n - i)] = -0.5;
        a[i][i - min(i , n - i)] = -0.5;
    }
    m = n + 1 , n += 2;
    rank = 0;
    for (i = 0 ; i < n ; ++ i) {
        int pivot = -1;
        for (j = rank ; j < m ; ++ j)
            if (!~pivot || (fabs(a[j][i]) > fabs(a[pivot][i])))
                pivot = j;
        if (pivot == -1) continue;
        for (j = 0 ; j < n ; ++ j)
            swap(a[rank][j] , a[pivot][j]);
        double tmp = a[rank][i];
        for (j = 0 ; j < n ; ++ j)
            a[rank][j] /= tmp;
        for (k = 0 ; k < m ; ++ k) {
            if (k != rank) {
                double times = a[k][i];
                for (j = 0 ; j < n ; ++ j) {
                    a[k][j] -= a[rank][j] * times;
                }
            }
        }
        ++ rank;
    }
    for (i = 0 ; i < m ; ++ i)
        if (fabs(a[i][A] - 1) < 1e-8) {
            printf("%f\n" , a[i][n - 1]);
            break;
        }
}

int main(){
    //freopen("1.txt","r",stdin);
    int _ ; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
