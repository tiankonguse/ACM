#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int lens[2200];
int main() {
    int n, k;
    string s;
    int ca = 1;
    bool begin = true;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            lens[i] = s.length();
        }
        sort(lens, lens + n);
        int t = n / k;
        bool flag = true;
        for (int i = 0; i < t; ++i) {
            for (int j = 0; j < k - 1; ++j) {
                int a = i * k + j;
                if (lens[a + 1] - lens[a] > 2) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (!begin) {
            cout << endl;
        }
        begin = false;
        cout << "Case " << ca++ << ": ";

        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
