#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

int n , m;

int main(){
    cin >> n >> m;
    pair<int , int> res(1 << 30 , -1);
    int i , j , k;
    for (k = 0 ; k < 3 ; ++ k) {
        int cnt = 0;
        for (i = 0 ; i < n ; ++ i)
            for (j = 0 ; j < m ; ++ j)
                if ((i + j) % 3 == k)
                    ++ cnt;
        res = min(res , make_pair(cnt , k));
    }
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < m ; ++ j)
            putchar("0#"[(i + j) % 3 == res.second]);
        puts("");
    }
    return 0;
}
