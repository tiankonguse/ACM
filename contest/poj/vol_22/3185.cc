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
#define maxn 30
using namespace std;
int countbit[1050000];
vector<int> v[21];
int main(){
    countbit[0]=0;
    v[0].push_back(0);
    for(int i=1;i<1048576;i++){
         countbit[i]=1+countbit[i-((i^(i-1))&i)];
         v[countbit[i]].push_back(i);
    }

    int s = 0, a, t, p, res = inf;
    for(int i=0;i<20;i++){
        scanf("%d", &a);
        s = (s << 1) | a;
    }
    for(int i=0;i<=20;i++){
        int sz = v[i].size();
        for(int k=0;k<sz;k++){
            p = v[i][k];
            t = s;
            for(int j=0;j<20;j++){
                if(p & (1 << j)){
                    if(j - 1 >= 0) t ^= (1 << (j - 1));
                    t ^= (1 << j);
                    if(j + 1 < 20) t ^= (1 << (j + 1));
                }
            }
            if(t == 0){
                printf("%d\n", i);
                return 0;
            }
        }
    }
    return 0;
}
