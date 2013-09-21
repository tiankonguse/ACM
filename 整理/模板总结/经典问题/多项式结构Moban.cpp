#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int N = 400000;

int P[N], R[N];

// Union Find Set..


vector<int> adj[N];
bool _del[N]; int order[N];
int ans[N+1];
int n, m, cpt;



inline void Make(int x){
	P[x] = x, R[x] = 0;
}

inline int Find(int x){
    if (P[x] != x) P[x] = Find(P[x]);
    return P[x];
}

void Union(int x, int y){
	x = Find(x), y = Find(y);
	if (x==y) return;
	if (R[x] < R[y]) P[y] = x;
	else {
		P[x] = y;
		if (R[x] == R[y]) R[y] ++ ;
	}
    cpt--;
}

int main(){
    //std::ios::sync_with_stdio(false);
    //freopen("starwar.in", "r", stdin);
    //freopen("starwar.out", "w", stdout);
    
    //cin >> n >> m;
    scanf("%d %d", &n, &m);
    int x, y;
    for (int i=0;i<m;i++){
 //       cin >> x >> y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
//    cin >> m;
    scanf("%d", &m);
    for (int i=0;i<m;i++){
       // cin >> x;
        scanf("%d", &x);
        _del[x] = true;
        order[i] = x;
    }
    
    for (int i=0;i<n;i++)
        Make(i);
    
    cpt = n - m;
    for (int i=0;i<n;i++){
        if (_del[i]) continue;
        for (int j=0;j<adj[i].size();j++)
            if (!_del[adj[i][j]]) Union(i, adj[i][j]);
    }
    
    
    ans[m] = cpt;
    for (int i=m-1;i>=0;i--){
        _del[order[i]] = false, cpt++;
        for (int j=0;j<adj[order[i]].size();j++)
            if (!_del[adj[order[i]][j]]) Union(order[i], adj[order[i]][j]);
        ans[i] = cpt;
    }
    for (int i=0;i<=m;i++)
        //cout << ans[i] << endl;
        printf("%d\n", ans[i]);
}