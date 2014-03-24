#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class edge {
public:
    int from, to, distance;
    edge(){};
    edge(int f, int t, int d):from(f),to(t),distance(d){};
};

vector<edge> edges;

bool edgeCmp(const edge& a, const edge& b)
{
    return a.distance < b.distance;
}

void union_set(vector<int>& sets, int n, int from, int to)
{
    int j, t;
    if(sets[from] < 0 && sets[to] < 0) {
        t = sets[to];
        for (j = 1; j <= n; ++j) {//合并集合
            if(sets[j] == t)
                sets[j] = sets[from];
        }
    }
    else if(sets[from] < 0 && sets[to] > 0) 
        sets[to] = sets[from];
    else if(sets[from] > 0 && sets[to] < 0) 
        sets[from] = sets[to];
    else if(sets[from] > 0 && sets[to] > 0) 
        sets[from] = sets[to] = -sets[from];           
}


int MST_Kruskal_pku1251(int n)
{
    int nMinCost = 0;
    int i, from, to;

    vector<int> sets(n);
    for (i = 0; i < n; ++i) {
        sets[i] = i+1;
    }
    
    int nNumEdge = edges.size();
    for (i = 0; i < nNumEdge; ++i) {
        from = edges[i].from;
        to   = edges[i].to;
    //    cout<<char('A'+from)<<"-"<<char('A'+to)<<":"<<edges[i].distance<<"  "<<sets[from]<<" "<<sets[to]<<endl;
        if (sets[from] == sets[to]) 
            continue;

        union_set(sets, n, from, to);
        nMinCost += edges[i].distance;
//        cout<<edges[i].distance<<endl;
    }    
    return nMinCost; 
}

int main()
{
    int n, nOutDegree, nDistance, i, j;
    char from[3], to[3];

    while (cin>>n && n) {
        for (j = 1; j <= n-1; ++j) {
            scanf("%s %d", from, &nOutDegree);
            for (i = 1; i <= nOutDegree; ++i) {
                scanf("%s %d", to, &nDistance);
                edges.push_back(edge(from[0]-'A',to[0]-'A',nDistance));
            }        
        }
        sort(edges.begin(), edges.end(), edgeCmp);        
        cout<<MST_Kruskal_pku1251(n)<<endl;
        edges.clear();
    }
    return 0;
}
