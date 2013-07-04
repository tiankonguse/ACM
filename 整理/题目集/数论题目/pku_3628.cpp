#include<iostream>
#include<vector>
using namespace std;

#define MAXN 1005
#define inf 1000000000

int n, m;
vector<vector<long> > mat, mat2;
vector<long> dist, pre, dist2, pre2;

void dijkstra(int s){
    int v[MAXN],i,j,k;
    for (i=0;i<n;i++)
        dist[i]=inf,v[i]=0,pre[i]=-1;
    for (dist[s]=0,j=0;j<n;j++){
        for (k=-1,i=0;i<n;i++)
            if (!v[i]&&(k==-1||dist[i]<dist[k]))
                k=i;
            for (v[k]=1,i=0;i<n;i++)
                if (!v[i]&&dist[k]+mat[k][i]<dist[i])
                    dist[i]=dist[k]+mat[pre[i]=k][i];
    }
}

void dijkstra2(int s){
    int v[MAXN],i,j,k;
    for (i=0;i<n;i++)
        dist2[i]=inf,v[i]=0,pre2[i]=-1;
    for (dist2[s]=0,j=0;j<n;j++){
        for (k=-1,i=0;i<n;i++)
            if (!v[i]&&(k==-1||dist2[i]<dist2[k]))
                k=i;
            for (v[k]=1,i=0;i<n;i++)
                if (!v[i]&&dist2[k]+mat2[i][k]<dist2[i])
                    dist2[i]=dist2[k]+mat2[i][pre2[i]=k];
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    int from, to, w;
    int i,  k;
    
    while(cin>>n>>m>>k) {
        k -= 1;
        mat = vector<vector<long> >(n, vector<long>(n, inf));
        dist = vector<long>(n);
        pre = vector<long>(n);
        for(i = 0; i < n; ++i) {
            mat[i][i] = 0;
        }
        for(i = 0; i < m; ++i) {
            scanf("%d %d %d ", &from, &to , &w);
            from -= 1, to -= 1;
            if(mat[from][to] > w)
                mat[from][to] = w;
        }
        
        mat2 = mat,  dist2 = dist, pre2 = pre;
        
        dijkstra(k), dijkstra2(k);
        
        int maxdist = -1;
        for(i = 0; i < n; ++i) {
            dist[i] += dist2[i];
            if(dist[i] > maxdist)
                maxdist = dist[i];
        }
        cout<<maxdist<<endl;
    //    cin>>from>>to>>w;
    }
    
    
    return 0;
}

