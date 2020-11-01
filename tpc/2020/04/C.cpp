#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;

const int N = 222222;
int str[N];
int dp[2 * N];
int pre[N];
int path[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n, sum;
        scanf("%d", &n);
        sum = 0;
        for(int i=0;i<n;i++){
            scanf("%d", &str[i]);
            sum += str[i];
        }

        int pack = sum/2;
        for(int i=0;i<=pack;i++){
            pre[i] = -1;
            path[i] = -1;
            dp[i] = 0;
        }
        for(int i=0;i<n;i++){
            for(int j=pack;j>=str[i];j--){
                if(dp[j] < dp[j - str[i]] + str[i]){
                    path[j] = i;
                    pre[j] = j - str[i];
                    dp[j] = dp[j - str[i]] + str[i];
                }
            }
        }

        set<int> s;
        int index = pack;
        while(index != -1){
            s.insert(path[index]);
            index = pre[index];
        }

        string ans;
        for(int i=0;i<n;i++){
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


