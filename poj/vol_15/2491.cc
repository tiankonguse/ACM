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
#define maxn 555
using namespace std;
map<string, int> mp;
int next[maxn], degree[maxn];
string s1, s2;
string str[maxn];
int main(){
    int t, n, a, b, cnt, p;
    int _c = 1;
    for(cin>>t;t--;){
        mp.clear();
        cnt = 0;
        cin>>n;
        memset(degree, 0, sizeof(degree));
        for(int i=0;i<n-1;i++){
            cin>>s1>>s2;
            if(mp.find(s1) == mp.end()){
                mp[s1] = cnt;
                str[cnt++] = s1;
            }
            if(mp.find(s2) == mp.end()){
                mp[s2] = cnt;
                str[cnt++] = s2;
            }
            a = mp[s1], b = mp[s2];
            degree[b]++;
            next[a] = b;
        }
        cout<<"Scenario #"<<_c++<<":"<<endl;
        for(int i=0;i<n;i++) {
            if(degree[i] == 0){
                p = i;
                for(int j=0;j<n;j++){
                    cout<<str[p]<<endl;
                    p = next[p];
                }
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}
