#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;


char str[100010];
int main() {
    vector<int> base = {2, 3, 5, 7, 11, 13, 17, 37, 79, 113, 197, 199, 337, 1193, 3779, 11939, 19937, 193939, 199933};
    map<int, string> m;

    for(auto v: base) {
        string s = to_string(v);
        int len = s.length();
        while(len--) {
            char c = s.back();
            s.pop_back();
            s.insert(s.begin(), c);
            m.insert({-stoi(s), s});
        }
    }

    scanf("%s", str);
    int ans = -1;
    string s = str;
    for(auto& p: m){
        if(s.find(p.second) != std::string::npos){
                ans = -p.first;
            break;
        }
    }
    printf("%d\n", ans);


    return 0;
}
