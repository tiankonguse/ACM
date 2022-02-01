#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;


int main() {
    vector<int> vec;
    int t, n, m, v;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        vec.clear();
        while(n--) {
            scanf("%d", &v);
            vec.push_back(v);
        }
        sort(vec.begin(), vec.end());
        vec.resize(m*2);

        int ans = 0;
        int len = vec.size();
        for(int i=0; i<m;i++){
            ans += vec[i] * vec[len-1-i];
        }
        printf("%d\n", ans);
    }


    return 0;
}
