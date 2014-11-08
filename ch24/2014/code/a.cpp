#include<cstdio>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<cstring>
#include<string>
#include<numeric>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<bitset>
#include<cassert>
//#include<unordered_map>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<x<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

//unordered_map<vector<int>,int> m[2];
map<vector<int>,int> m[100];
vector<int> v;
int n,p;
string a[60];
string s;

void dfs(int dep,int ans) {
	int i;
	if (dep==n) {
		m[0][v]=ans;
		return;
	}
	for (i=0;i<a[dep].size();i++) {
		v.push_back(i);
		dfs(dep+1,ans+i);
		v.pop_back();
	}
}

int main() {
//	unordered_map<vector<int>,int>::iterator iter;
	map<vector<int>,int>::iterator iter;
	int i,j,x,t,ans,temp;
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		cin>>a[i];
	//	debug(a[i]);
	//	debug(a[i].size());
	}
	scanf("%d",&p);
	for (i=0;i<p;i++) {
		cin>>s;
	//	debug(s);
		m[0].clear();
		m[1].clear();
		v.clear();
		dfs(0,0);
		t=0;
		for (j=0;j<s.size();j++,t^=1) {
			foreach(it,m[t]) {
				v=it->first;
				for (x=0;x<n;x++) {
					if (a[x][v[x]]==s[j]) {
						temp=v[x];
						v[x]=(v[x]+1)%a[x].size();
		//				printf("t=%d j=%d x=%d a[x].size()=%d\n",t,j,x,a[x].size());
		//				printf("t=%d m[t^1].size()=%d\n",t,m[t^1].size());
						iter=m[t^1].find(v);
						if (iter==m[t^1].end()) {
							m[t^1][v]=it->second+1;
						}
						else {	
							iter->second=min(iter->second,it->second+1);
						}				
						v[x]=temp;
					}
		//			debug(t);
			//		debug(m[t].size());
				}
			}
			m[t].clear();
		}
		ans=-1;
		foreach(it,m[t])
			if (ans==-1 || ans!=-1 && ans>it->second) ans=it->second;
		printf("%d\n",ans);
	}
}
