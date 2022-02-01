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
#define maxn 12
using namespace std;
int bill[maxn][2];
set<int> s;
int main(){
    int n, m;
    while(~scanf("%d", &n)){
        scanf("%d", &m);
        for(int i=0;i<m;i++){
            scanf("%d%d", &bill[i][0], &bill[i][1]);
        }
        s.clear();
        s.insert(0);
        set<int> :: reverse_iterator it;
        int d, v, next;
        for(int i=0;i<m;i++){
            d = bill[i][0];
            next = 1;
            for(int j=1;j<=d;){
                v = next * bill[i][1];
                for(it = s.rbegin(); it != s.rend(); it++){
                    if((*it) + v <= n){
                        s.insert((*it) + v);
                    }
                }
              //  cout<<j<<","<<d<<endl;system("pause");
                if(j == d) break;
                next = min(next << 1, d - j);
                j += next;
            }
        }
        printf("%d\n", (*s.rbegin()));
    }
    return 0;
}
