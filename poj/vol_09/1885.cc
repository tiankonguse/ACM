#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>

#define inf 0x3f3f3f3f
#define INF 0x3FFFFFFFFFFFFFFFLL
using namespace std;
char str[1001000];
vector<int> v;
map<string, int> mp; int cnt;
string dat[10010];
int getID(string s) {
    if (mp.find(s) == mp.end()) {
        dat[cnt] = s;
        mp[s] = cnt++;
    }
    return mp[s];
}

int main() {
    int idx = 0;
    char ch;
    while ((ch = getchar())) {
        if (ch == '0' && !isdigit(str[idx - 1])) break;
        str[idx++] = ch;
    }
    cnt = 0;
    string t;
    int j, k, id;
    int len = 0;
    for (int i = 0; i < idx; ++i) {
        if (isalpha(str[i])) {
            t = "";
            j = i;
            while (isalpha(str[j])) {
                t += str[j];
                ++j;
            }
            i = j - 1;
            id = getID(t);
            v.push_back(id);
            ++len;
            cout << t ;
        }
        else if (isdigit(str[i])) {
            k = 0;
            j = i;
            while (isdigit(str[j])) {
                k = k * 10 + (str[j] - '0');
                ++j;
            }
            i = j - 1;
            id = v[len - k];
            cout << dat[id];
            v.erase(v.end() - k);
            v.push_back(id);
        }
        else putchar(str[i]);
    }

    return 0;
}
