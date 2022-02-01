#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;

int str[1111][1111];

long long getSum(int n){
    long long ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans += str[i][j];
        }
    }
    ans = ans * 2;
    for(int i=0;i<n;i++){
        ans += str[i][i];
        ans += str[i][n-1-i];
    }
    return ans;
}

struct Point{
    int x, y, v;
    void init(int _x, int _y){
        x = _x, y = _y;
        v = str[x][y];
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &str[i][j]);
            }
        }
        long long ans = getSum(n);
        if(n <= 2){ //小于 2 交换没有最优值
            printf("%lld\n", ans);
            continue;
        }

        //1、对角线之外的最大值 vs 对角线之上最小值
        Point A, B;
        A.init(0, 0); //对角线上的一个点
        B.init(0, 1); //非对角线上的一个点
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j || i + j == n-1){
                    if(A.v > str[i][j]){
                        A.init(i, j);
                    }
                }else{
                    if(B.v < str[i][j]){
                        B.init(i, j);
                    }
                }
            }
        }
        if(A.v < B.v){ //可以更优
            swap(str[A.x][A.y], str[B.x][B.y]);
            ans = max(ans, getSum(n));
            swap(str[A.x][A.y], str[B.x][B.y]);
        }


        //2、对角线之外的最大值 vs 中心
        A.init(n/2, n/2);
        if(n % 2 == 1 && A.v < B.v){
            swap(str[A.x][A.y], str[B.x][B.y]);
            ans = max(ans, getSum(n));
            swap(str[A.x][A.y], str[B.x][B.y]);
        }

        //3、中心之外的最大值 vs 中心
        if(n % 2 == 1){
            for(int i=0;i<n;i++){
                if(i == n/2){
                    continue;
                }
                if(B.v < str[i][i]){
                    B.init(i, i);
                }
                if(B.v < str[i][n-1-i]){
                    B.init(i, n-1-i);
                }
            }
            if(A.v < B.v){
                swap(str[A.x][A.y], str[B.x][B.y]);
                ans = max(ans, getSum(n));
                swap(str[A.x][A.y], str[B.x][B.y]);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}


