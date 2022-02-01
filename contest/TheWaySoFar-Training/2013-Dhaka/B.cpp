#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef unsigned long long LL;
int n , ca;
LL cnt[3];

void work() {
    cin >> n;
    printf("Case %d: " , ++ ca);
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (int i = 0 ; i < n ; ++ i) {
        LL L , B;
        cin >> L >> B;
        if (B % 3 == 0)
            cnt[0] += (L - 1) * (B - 1);
        else if (B % 3 == 1) {
            cnt[1] += (L - 1) * (B - 1);
        } else {
            cnt[2] += (L >> 1) * (B - 1);
            cnt[1] += ((L - 1) - (L >> 1)) * (B - 1);
        }
    }
    //cin >> cnt[0] >> cnt[1] >> cnt[2];
    if (!cnt[0] && !cnt[1] && !cnt[2]) {
        puts("Draw");
        return;
    }
    int a = 0 , b = 0;
    if (cnt[1]) {
        -- cnt[1];
        if (cnt[1] < cnt[2]) {
            a = ~cnt[0] & 1;
        } else if (cnt[1] > 1 + cnt[2]) {
            a = cnt[0] & 1;
        } else
            a = 2;
        ++ cnt[1];
    }
    if (cnt[2]) {
        -- cnt[2];
        if (cnt[2] < cnt[1]) {
            b = ~cnt[0] & 1;
        } else if (cnt[2] > 1 + cnt[1]) {
            b = cnt[0] & 1;
        } else
            b = 2;
        ++ cnt[2];
    }

    if (a == 1 || b == 1) {
        puts("M");
    } else if (a == 0 && b == 0) {
        puts("J");
    } else
        puts("Draw");
    //cout << a << ' ' << b << endl;
    //cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << endl;
}

int main(){
    //freopen("1.txt" , "r" , stdin);
    int _; scanf("%d",&_); while(_ --)
        work();
    return 0;
}
