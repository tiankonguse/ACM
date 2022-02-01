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
#define maxn 17
using namespace std;
int arr[maxn], tmp[maxn];
int n;

int fun(){
    int cnt = 0;
    if(arr[0] != 1) cnt++;
    for(int i=1;i<n;i++) if(arr[i] != arr[i - 1] + 1) cnt++;
    if(arr[n - 1] != n) cnt++;
    return cnt;
}
void trans(int l, int r, int p){
    int cnt = 0;
    for(int i=0;i<l;i++) tmp[cnt++] = arr[i];
    for(int i=r+1;i<=p;i++) tmp[cnt++] = arr[i];
    for(int i=l;i<=r;i++) tmp[cnt++] = arr[i];
    for(int i=cnt;i<n;i++) tmp[i] = arr[i];
    memcpy(arr, tmp, sizeof(tmp));
}
bool dfs(int d, int limit){
    int h = fun();
    if(d == limit) return h == 0;
    else if( (limit - d) * 3 < h ) return false;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=j+1;k<n;k++){
                trans(i, j, k);
                if(dfs(d + 1, limit)) return true;
                trans(i, k - j + i - 1, k);
            }
        }
    }
    return false;
}
int main(){
    int t;
    for(scanf("%d", &t); t--; ){
        scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%d", &arr[i]);
        int x,y,z;
//        while(cin>>x>>y>>z){
//            trans(x,y,z);for(int i=0;i<n;i++) cout<<arr[i]<< " "; cout<<endl;
//            trans(x,z-y+x-1,z);for(int i=0;i<n;i++) cout<<arr[i]<< " "; cout<<endl;
//        }
        int limit;
        for(limit=0;limit<=4;limit++){
            if(dfs(0, limit)){
                break;
            }
        }
        if(limit < 5) printf("%d\n", limit);
        else puts("5 or more");
    }
    return 0;
}
