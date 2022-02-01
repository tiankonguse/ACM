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
#include <sstream>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
string dat[33] =
{"zero", "one", "two", "three", "four",
"five", "six", "seven", "eight", "nine",
"ten", "eleven", "twelve", "thirteen",
"fourteen", "fifteen", "sixteen", "seventeen",
"eighteen", "nineteen", "twenty", "thirty", "forty",
"fifty", "sixty", "seventy", "eighty", "ninety"};
map<string, int> mp;

void init() {
    mp.clear();
    for (int i = 0; i <= 20; ++i) mp[ dat[i] ] = i;
    for (int i = 30; i <= 90; i += 10) mp[ dat[18 + i / 10] ] = i;
}
string s;
int main() {
    init();
    while (getline(cin, s)) {
        if (s == "") break;
        istringstream is(s);
        bool flag = true;
        int t = 0, ret = 0;
        int q = 0;
        bool ml = false, th = false;

        while (is >> s) {
            if (s == "negative") flag = false;
            else if (s == "million") {
                ret += t;
                ret *= 1000000;
                t = 0;
                ml = true;
            }
            else if (s == "thousand") {
                if (!ml) ret = (ret + t) * 1000;
                else ret += t * 1000;
                t = 0;
            }
            else if (s == "hundred") {
                t *= 100;
            }
            else t += mp[s];
        }
        ret += t;
        if (!flag) printf("-%d\n", ret);
        else printf("%d\n", ret);
    }
    return 0;
}
