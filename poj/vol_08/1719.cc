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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 1010
using namespace std;
bool mp[maxn][maxn];
int res[maxn];
int cnt[maxn];
int col[maxn][2];
bool used[maxn];
//struct node{
//    int id;
//    friend bool operator<(node a, node b){
//        return cnt[a.id] > cnt[b.id];
//    }
//    node(int _t) { id = _t;}
//    node(){}
//};
//priority_queue<node> q;

int main(){
    int t, r, c, id;
    for(scanf("%d", &t);t--;){
        memset(mp, false, sizeof(mp));
        memset(cnt, 0, sizeof(cnt));
        scanf("%d%d", &r, &c);
        for(int i=1;i<=c;i++){
            scanf("%d%d", &col[i][0], &col[i][1]);
            cnt[col[i][0]]++;
            cnt[col[i][1]]++;
            mp[col[i][0]][i] = mp[col[i][1]][i] = true;
            res[i] = col[i][0];
        }
//        while(!q.empty()) q.pop();
//        for(int i=1;i<=r;i++){
//            q.push(node(i));
//        }
        bool flag = true;
        int cho, mi;
        memset(used, false, sizeof(used));
        for(int k=1;k<=r;k++){
            mi = inf;
            for(int j=1;j<=r;j++){
                if(!used[j] && cnt[j] < mi){
                    mi = cnt[j];
                    cho = j;
                }
            }
            if(cnt[cho] == 0) {
                flag = false;
                break;
            }
            used[cho] = true;
            for(int i=1;i<=c;i++){
                if(mp[cho][i]){
                    res[i] = cho;
                    mp[cho][i] = false;
                    cnt[cho]--;
                    for(int j=1;j<=r;j++){
                        if(mp[j][i]){
                            mp[j][i] = false;
                            cnt[j]--;;
                            break;
                        }
                    }
                    break;
                }
            }
        }
//        while(!q.empty()){
//            id = q.top().id;
//           // cout<<id<<","<<cnt[id]<<endl;
//            q.pop();
//            if(cnt[id] == 0){
//                flag = false;
//                break;
//            }
//            for(int i=1;i<=c;i++){
//                if(mp[id][i]){
//                    res[i] = id;
//                    mp[id][i] = false;
//                    cnt[id]--;
//                    for(int j=1;j<=r;j++){
//                        if(mp[j][i]){
//                            mp[j][i] = false;
//                            cnt[j]--;
//                            break;
//                        }
//                    }
//                    break;
//                }
//            }
//        }
        if(!flag) puts("NO");
        else{
            for(int i=1;i<=c;i++){
                if(i == c) printf("%d\n", res[i]);
                else printf("%d ", res[i]);
            }
        }
    }
    return 0;
}
