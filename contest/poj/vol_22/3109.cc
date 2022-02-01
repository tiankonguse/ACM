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
#define maxn 200100
using namespace std;
typedef __int64 ll;

int arr[maxn], rk[maxn], mp[maxn];
int n, mx;
bool cmp(int a, int b){
    return arr[a] < arr[b];
}
void lisan(){
    for(int i=1;i<=n;i++) rk[i] = i;
    sort(rk + 1, rk + n + 1, cmp);
    mp[1] = arr[rk[1]];
    arr[rk[1]] = mx = 1;
    for(int i=2;i<=n;i++){
        if(arr[rk[i]] == mp[mx]) arr[rk[i]] = mx;
        else mp[++mx] = arr[rk[i]], arr[rk[i]] = mx;
    }
}
struct node{
    int x, y, id;
    int state;
}p[maxn];
bool cmpx(node a, node b){ return a.x == b.x ? a.y < b.y : a.x < b.x; }
bool cmpy(node a, node b){ return a.y == b.y ? a.x < b.x : a.y < b.y; }

struct lines{
    int x, y1, y2;
}line[maxn];
struct horizon{
    int x, y, state;
    friend bool operator<(horizon a, horizon b){
        if(a.x == b.x) return a.state < b.state;
        else return a.x < b.x;
    }
}hline[maxn];

struct binaryIndexedTrees{
    ll num[maxn];
    void init(){
        memset(num,0,sizeof(num));
    }
    int lowbit(int x){
        return x&(-x);
    }
    void update(int p,int c){
        while(p<maxn){
            num[p] += c;
            p += lowbit(p);
        }
    }
    int sum(int p){
        int t=0;
        while(p>0){
            t += num[p];
            p -= lowbit(p);
        }
        return t;
    }
}bit;
int main(){
    ll res;
    while(~scanf("%d", &n)){
        for(int i=1;i<=n;i++){
            scanf("%d %d", &p[i].x, &p[i].y);
            p[i].state = -1;
            p[i].id = i;
            arr[i] = p[i].y;
        }
        lisan();
        sort(p + 1, p + n + 1, cmpx);
        p[0].x = p[0].y = -inf;
        p[n + 1].x = p[n + 1].y = inf;
        int _start = 0, _end = 0;
        int m = 0;
        for(int i=1;i<=n+1;i++){
            if(p[i].x != p[i - 1].x){
                if(_end != _start){
                    line[m].x = p[i - 1].x;
                    line[m].y1 = arr[ p[_start].id ];
                    line[m].y2 = arr[ p[_end].id ];
                    m++;
                }
                _start = _end = i;
            }
            else{
                _end = i;
                if(p[i].x == p[i + 1].x){ //ips n + 1
                    p[i].state = 1;
                }
            }
        }
        //for(int i=0;i<m;i++) printf("%d %d %d\n", line[i].x, line[i].y1, line[i].y2);
        sort(p + 1, p + n + 1, cmpy);
        res = n;
        _start = _end = 0;
        int k = 0;
        for(int i=1;i<=n+1;i++){
            if(p[i].y != p[i - 1].y){
                if(p[_end].x - p[_start].x > 1){
                    hline[k].y = arr[ p[i - 1].id ];
                    hline[k].x = p[_start].x + 1;
                    hline[k].state = 1;
                    k++;
                    hline[k].y = arr[ p[i - 1].id ];
                    hline[k].x = p[_end].x ;
                    hline[k].state = 2;
                    k++;
                }
                _start = _end = i;
            }
            else{
                _end = i;
                if(p[i].y == p[i + 1].y && p[i].state == 1){
                    res--;
                }
            }
        }

        //for(int i=0;i<k;i++) printf("%d %d %d\n", hline[i].x, hline[i].y, hline[i].state);system("pause");
        sort(hline, hline + k);
        bit.init();
        int pos = 0, low, high;
        for(int i=0;i<k;i++){
            if(hline[i].state == 1){
                while(pos < m && line[pos].x < hline[i].x){
                    low = line[pos].y1 + 1;
                    high = line[pos].y2 - 1;
                    if(low <= high){
                        res += bit.sum(high) - bit.sum(low - 1);
                    }
                    pos++;
                }
                if(pos == m) break;
                bit.update(hline[i].y, 1);
            }
            else{
                while(pos < m && line[pos].x < hline[i].x){
                    low = line[pos].y1 + 1;
                    high = line[pos].y2 - 1;
                    if(low <= high){
                  //      cout << low << "," << high << endl;
                        res += bit.sum(high) - bit.sum(low - 1);
                    }
                    pos++;
                }
                if(pos == m) break;
                bit.update(hline[i].y, -1);
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}
