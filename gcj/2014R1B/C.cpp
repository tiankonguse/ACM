#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 55;
int n, m;
int a[N];
int fa[N];
int mat[N][N];
vector <int> L;
int Resultorder[N];

#define MAXN 120
#define inf 1000000000
typedef int elem_t;
elem_t edmonds(int n,elem_t mat[][MAXN*2],int* pre){
    elem_t ret=0;
    int c[MAXN*2][MAXN*2],l[MAXN*2],p[MAXN*2],m=n,t,i,j,k;
    for (i=0;i<n;l[i]=i,i++);
    do{
        memset(c,0,sizeof(c)),memset(p,0xff,sizeof(p));
        for (t=m,i=0;i<m;c[i][i]=1,i++);
        for (i=0;i<t;i++)
            if (l[i]==i&&pre[i]!=-1){
                for (j=0;j<m;j++)
                    if
(l[j]==j&&i!=j&&mat[j][i]<inf&&(p[i]==-1||mat[j][i]<mat[p[i]][i]))
                        p[i]=j;
                if ((pre[i]=p[i])==-1)
                    return -1;
                if (c[i][p[i]]){
                    for (j=0;j<=m;mat[j][m]=mat[m][j]=inf,j++);
                    for (k=i;l[k]!=m;l[k]=m,k=p[k])
                        for (j=0;j<m;j++)
                            if (l[j]==j){
                                if (mat[j][k]-mat[p[k]][k]<mat[j][m])
                                    mat[j][m]=mat[j][k]-mat[p[k]][k];
                                if (mat[k][j]<mat[m][j])
                                    mat[m][j]=mat[k][j];
                            }
                    c[m][m]=1,l[m]=m,m++;
                }
                for (j=0;j<m;j++)
                    if (c[i][j])
                        for (k=p[i];k!=-1&&l[k]==k;c[k][j]=1,k=p[k]);
            }
    }
    while (t<m);
    for (;m-->n;pre[k]=pre[m])
        for (i=0;i<m;i++)
            if (l[i]==m){
                for (j=0;j<m;j++)
                    if (pre[j]==m&&mat[i][j]==mat[m][j])
                        pre[j]=i;
                if (mat[pre[m]][m]==mat[pre[m]][i]-mat[pre[i]][i])
                    k=i;
            }
    for (i=0;i<n;i++)
        if (pre[i]!=-1)
            ret+=mat[pre[i]][i];
    return ret;
}

int go(int u, int v) {
    while (fa[u] != u) {
        if (mat[u][v]) return u;
        u = fa[u];
    }
    if (mat[u][v]) return u;
    return -1;
}

bool check(int idx) {
    if (idx == n) return 1;
    int last = Resultorder[idx - 1];
    int v;
    for (int u : L) {
        if (fa[u] == -1 && (v = go(last, u)) != -1) {
            Resultorder[idx] = u;
            fa[u] = v;
            if (check(idx + 1)) return 1;
            fa[u] = -1;
        }
    }
    return 0;
}

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    int Tc;
    cin >> Tc;
    rep (ri, Tc) {
        printf("Case #%d: ", ri + 1);
        cin >> n >> m;
        memset(mat, 0, sizeof(mat));
        rep (i, n) cin >> a[i];
        rep (i, m) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            mat[x][y] = mat[y][x] = 1;
        }
        L.clear();
        rep (i, n) L.push_back(i);
        sort(L.begin(), L.end(), cmp);
        for (int i : L) {
            memset(fa, 0xff, sizeof(fa));
            fa[i] = i;
            Resultorder[0] = i;
            if (check(1)) break;
            fa[i] = -1;
        }
        rep (i, n) {
            printf("%05d", a[Resultorder[i]]);
        }
        puts("");
    }
}

