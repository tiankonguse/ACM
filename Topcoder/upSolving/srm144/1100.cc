// BEGIN CUT HERE
/*

 */
// END CUT HERE
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

#define PB push_back
#define MP make_pair

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repi(i, l, h) for (int i = (l); i <= (h); ++i)
#define repd(i, h, l) for (int i = (h); i >= (l); --i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int const N = 2525, M = 252525;
struct Line {
	int x1, y1, x2, y2;
	Line (int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : x1(x1), y1(y1), x2(x2), y2(y2) { }
} h[N], v[N];
int nH, nV;
inline bool cmpH(Line const &A, Line const &B) { return A.y1 == B.y1 ? A.x1 < B.x1 : A.y1 < B.y1; }
inline bool cmpV(Line const &A, Line const &B) { return A.x1 == B.x1 ? A.y1 < B.y1 : A.x1 < B.x1; }
bool mk[N];
struct Point {
	int x, y;
	Point (int x = 0, int y = 0) : x(x), y(y) { }
	friend bool operator < (Point a, Point b) { return a.y == b.y ? a.x < b.x : a.y < b.y; }
} ip[N]; 
int ic;

map <pii, int> mp; int pid;
inline int getID(int x, int y) {
	pii tmp = MP(x, y);
	if (mp.find(tmp) == mp.end()) mp[tmp] = ++pid;
	return mp[tmp];
}	

int n, m;
struct edges{ int u, next; } e[M];
int p[N], idx;
int deg[N];
void addedge(int u, int v, int k) {
	deg[u] += k, deg[v] += k;
	e[idx].u = v, e[idx].next = p[u], p[u] = idx++;
	e[idx].u = u, e[idx].next = p[v], p[v] = idx++;
}
void init() { idx = 0; clr(p, 0xff); clr(deg, 0);}

bool vis[N]; int oc;
void dfs(int u) {
	vis[u] = 1;
	if (deg[u] & 1) ++oc;
	for (int i = p[u]; ~i; i = e[i].next) {
		int v = e[i].u;
		if (!vis[v]) dfs(v);
	}
}

class PenLift
{
	public:
		int numTimes(vector <string> s, int k)
		{
			nH = nV = 0;
			int nS = s.size();
			int x1, y1, x2, y2;
			rep(i, nS) {
				istringstream is(s[i]);
				is >> x1 >> y1 >> x2 >> y2;
				if (x1 > x2) swap(x1, x2);
				if (y1 > y2) swap(y1, y2);
				if (y1 == y2) h[nH++] = Line(x1, y1, x2, y2);
				else v[nV++] = Line(x1, y1, x2, y2);
			}
			sort(h, h + nH, cmpH);
			sort(v, v + nV, cmpV);
			
			clr(mk, 0);
			Rep(i, nH - 1) {
				rep(j, i) if (!mk[j] && h[i].y1 == h[j].y1) {
					if (!(h[i].x1 > h[j].x2 || h[j].x1 > h[i].x2)) {
						h[j].x1 = min(h[i].x1, h[j].x1);
						h[j].x2 = max(h[i].x2, h[j].x2);
						mk[i] = 1;
						break;
					}
				}
			}
			rep(i, nH) if (mk[i]) {
				swap(h[i], h[nH - 1]);
				swap(mk[i], mk[nH - 1]);
				--nH, --i;
			}	
			clr(mk, 0);
			Rep(i, nV - 1) {
				rep(j, i) if (!mk[j] && v[i].x1 == v[j].x1) {
					if (!(v[i].y1 > v[j].y2 || v[j].y1 > v[i].y2)) {
						v[j].y1 = min(v[i].y1, v[j].y1);
						v[j].y2 = max(v[i].y2, v[j].y2);
						mk[i] = 1;
						break;
					}
				}
			}
			rep(i, nV) if (mk[i]) {
				swap(v[i], v[nV - 1]);
				swap(mk[i], mk[nV - 1]);
				--nV, --i;
			}
			mp.clear(); pid = 0; ic = 0;
			rep(i, nH) rep(j, nV) {
				if (h[i].y1 >= v[j].y1 && h[i].y1 <= v[j].y2 &&
						v[j].x1 >= h[i].x1 && v[j].x1 <= h[i].x2) {
					ip[ic++] = Point(v[j].x1, h[i].y1);
				}
			}
			sort(ip, ip + ic);
			init(); 
			rep(i, nH) {
				int x = h[i].x1, y = h[i].y1, tx, ty;
				rep(j, ic) {
					tx = ip[j].x, ty = ip[j].y;
					if (ty == y && tx > x && tx <= h[i].x2) {
						int id1 = getID(x, y), id2 = getID(tx, ty);
						addedge(id1, id2, k);
						x = tx, y = ty;
					}
				}
				if (x < h[i].x2) {
					int id1 = getID(x, y), id2 = getID(h[i].x2, y);
					addedge(id1, id2, k);
				}
			}
			rep(i, nV) {
				int x = v[i].x1, y = v[i].y1, tx, ty;
				rep(j, ic) {
					tx = ip[j].x, ty = ip[j].y;
					if (tx == x && ty > y && ty <= v[i].y2) {
						int id1 = getID(x, y), id2 = getID(tx, ty);
						addedge(id1, id2, k);
						x = tx, y = ty;
					}
				}
				if (y < v[i].y2) {
					int id1 = getID(x, y), id2 = getID(x, v[i].y2);
					addedge(id1, id2, k);
				}
			}
			int ret = 0; clr(vis, 0);
			Rep(i, pid) if (!vis[i]) {
				oc = 0;
				dfs(i);
				ret += 1 + max(0, (oc - 2)) / 2;
			}
			
			return ret - 1;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {"-10 0 10 0","0 -10 0 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, numTimes(Arg0, Arg1)); }
		void test_case_1() { string Arr0[] = {"-10 0 0 0","0 0 10 0","0 -10 0 0","0 0 0 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, numTimes(Arg0, Arg1)); }
		void test_case_2() { string Arr0[] = {"-10 0 0 0","0 0 10 0","0 -10 0 0","0 0 0 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(2, Arg2, numTimes(Arg0, Arg1)); }
		void test_case_3() { string Arr0[] = {"0 0 1 0",   "2 0 4 0",   "5 0 8 0",   "9 0 13 0",
			"0 1 1 1",   "2 1 4 1",   "5 1 8 1",   "9 1 13 1",
			"0 0 0 1",   "1 0 1 1",   "2 0 2 1",   "3 0 3 1",
			"4 0 4 1",   "5 0 5 1",   "6 0 6 1",   "7 0 7 1",
			"8 0 8 1",   "9 0 9 1",   "10 0 10 1", "11 0 11 1",
			"12 0 12 1", "13 0 13 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(3, Arg2, numTimes(Arg0, Arg1)); }
		void test_case_4() { string Arr0[] = {"-2 6 -2 1",  "2 6 2 1",  "6 -2 1 -2",  "6 2 1 2",
			"-2 5 -2 -1", "2 5 2 -1", "5 -2 -1 -2", "5 2 -1 2",
			"-2 1 -2 -5", "2 1 2 -5", "1 -2 -5 -2", "1 2 -5 2",
			"-2 -1 -2 -6","2 -1 2 -6","-1 -2 -6 -2","-1 2 -6 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 3; verify_case(4, Arg2, numTimes(Arg0, Arg1)); }
		void test_case_5() { string Arr0[] = {"-360 672 -172 672", "-336 -930 -961 -930", "688 4 688 -967", "689 -237 -701 -237", "100 -867 100 -578", "-758 889 -272 889", "-136 -314 -876 -314", "-901 -640 35 -640", "980 -639 -364 -639", "156 45 610 45", "-245 569 -245 39", "850 40 -215 40", "-687 596 -687 -660", "-509 666 -509 457", "625 -309 372 -309", "-582 -785 836 -785", "-914 131 -914 58", "903 -339 903 -738", "-318 709 -318 71", "-635 742 -635 6", "-49 246 -49 917", "694 -27 -355 -27", "-931 390 143 390", "40 -132 40 319", "346 637 643 637", "945 952 573 952", "-102 898 -102 766", "979 615 979 113", "-761 465 -761 995", "10 398 -182 398", "907 -688 907 -222", "-307 909 -307 966", "331 -520 -525 -520", "132 267 -530 267", "-237 -93 -237 -932", "907 -685 653 -685", "796 501 796 -419", "663 -471 663 155", "23 388 23 -592", "44 401 -478 401", "-335 -89 -755 -89", "99 -437 -475 -437", "486 5 486 -195", "381 -954 -521 -954", "-957 -909 -957 260", "663 -264 663 -582", "219 954 -868 954"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999701; int Arg2 = 45; verify_case(5, Arg2, numTimes(Arg0, Arg1)); }

		// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	PenLift ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE


