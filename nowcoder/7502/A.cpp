#include<bits/stdc++.h>
#define FASTIO() cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define D(x) #x,x
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define MP make_pair
#define pb push_back
using namespace std;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(ll &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf("%c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.fi); putchar(' '); _W(x.se);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
int dp[100005][4];
int n;
char s[100005];
int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%s",s+1);
        for(int i = 1 ; i <= n; ++i)
        {
            // 2 的个数
            dp[i][0] = dp[i-1][0]+(s[i]=='2');

            // 20 的个数
            // dp[i-1][1] 已经组成的 20 个数，判断是否可以再组成一个
            // 如果 dp[i-1][0] > dp[i-1][1], 一定可以组成一个
            dp[i][1] = min(dp[i-1][1]+(s[i]=='0'),dp[i-1][0]);

            // 202 的个数
            // dp[i-1][2] 已经组成的 202 个数，帕努单是否可以再组成一个
            // 如果 dp[i-1][1] 的个数
            dp[i][2] = min({dp[i-1][2]+(s[i]=='2'),dp[i-1][1],dp[i][0]/2}); //
            dp[i][3] = min({dp[i-1][3]+(s[i]=='0'),dp[i-1][2],dp[i][1]/2}); // 2020 的个数
//            W(D(i),s[i]);
//            W(dp[i][0],dp[i][1],dp[i][2],dp[i][3]);
        }
        W(dp[n][3]);
    }
    return 0;
}







