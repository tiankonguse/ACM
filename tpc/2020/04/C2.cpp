#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n, sum;
        scanf("%d", &n);
        sum = 0;
        vector<pair<int, int>> vec;
        for(int i=0;i<n;i++){
            int v;
            scanf("%d", &v);
            vec.push_back({v, i}); //由于需要记录路径，保存下标
            sum += v;
        }

        sort(vec.begin(), vec.end(), [](auto& p1, auto&p2){
             return p1.first > p2.first;
         });

        int pack = sum/2;
        set<int> s;
        for(int i=0;i<n;i++){
            auto& p = vec[i];
            if(pack >= p.first){ //从大到小贪心
                s.insert(p.second);
                pack -= p.first;
            }
        }

        string ans;
        for(int i=0;i<n;i++){ //组装答案
            if(s.count(i)){
                ans.push_back('b');
            }else{
                ans.push_back('a');
            }
        }

        printf("%s\n", ans.c_str());
    }

    return 0;
}


