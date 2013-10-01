#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <list>
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define FORSZ(i,a,v) FOR(i,a,SZ(v))
#define REPSZ(i,v) REP(i,SZ(v))
typedef long long ll;

// f(n) = max (n-x)*cost+g(x)	0<=x, n-cnt(f)<=x	x<=maxfree(g), x<=n, x<=total-n

// let dg(z)>=cost, dg(z+1)<cost	z<=maxfree(g)

// fx(n)=n				f(n)=g(n)						n<=z			n<=maxfree(g)
// fx(n)=z				f(n)=(n-z)*cost+g(z)			z<=n<=z+cnt(f)	n<=maxfree(g)
// fx(n)=n-cnt(f)		f(n)=cnt(f)*cost+g(n-cnt(f))	z+cnt(f)<=n		n<=maxfree(g)

// df(n)=dg(n)				n<=z				n<=maxfree(g)
// df(n)=cost				z+1<=n<=z+cnt(f)	n<=maxfree(g)
// df(n)=dg(n-cnt(f))		z+cnt(f)+1<=n		n<=maxfree(g)

int nitems;
int itemcost[500000];

int ngroups;
int groupcnt[500000];
int groupcost[500000];

int nnodes,firstnode,lastnode;
int nextnode[500002];
int prevnode[500002];
int nodeval[500002];

int nnewvals;
int newval[500000];

void printlst() {
	bool first;
	first=true; for(int x=nextnode[firstnode];x!=lastnode;x=nextnode[x]) { if(first) first=false; else printf(","); printf("%2d",nodeval[x]); } puts("");
//	first=true; for(int x=nextnode[firstnode];x!=lastnode;x=nextnode[x]) { if(first) first=false; else printf(","); printf("%2d",prevnode[x]); } puts("");
//	first=true; for(int x=nextnode[firstnode];x!=lastnode;x=nextnode[x]) { if(first) first=false; else printf(","); printf("%2d",x); } puts("");
//	first=true; for(int x=nextnode[firstnode];x!=lastnode;x=nextnode[x]) { if(first) first=false; else printf(","); printf("%2d",nextnode[x]); } puts("");
}
int read_int(){
	int a=0;
	int b=1,c=getchar();
	if(c=='-')b=-1;
	else a=c-48;
	while((c=getchar())!=' '&&c!='\n')
		a=a*10+c-48;
	a*=b;
	return a;
}
void input() {
	nitems=read_int();
	//scanf("%d",&nitems);
	REP(i,nitems) itemcost[i]=read_int();
		//scanf("%d",&itemcost[i]);
}

void makegroups() {
	sort(itemcost,itemcost+nitems);
	ngroups=0; REP(i,nitems) if(i==0||itemcost[i]!=itemcost[i-1]) { groupcnt[ngroups]=1; groupcost[ngroups]=itemcost[i]; ++ngroups; } else ++groupcnt[ngroups-1];
}

ll calcgood() {
	makegroups();
	nnodes=0;
	firstnode=nnodes++; lastnode=nnodes++;
	nextnode[firstnode]=lastnode; prevnode[firstnode]=-1; nodeval[firstnode]=INT_MAX;
	nextnode[lastnode]=-1; prevnode[lastnode]=firstnode; nodeval[lastnode]=INT_MIN;

	int maxfree=0,total=0;
	int z=0,znode=firstnode;
	for(int i=ngroups-1;i>=0;--i) {
//		printf("processing %d times %d\n",groupcnt[i],groupcost[i]); printlst();

		while(nodeval[nextnode[znode]]>=groupcost[i]) { ++z; znode=nextnode[znode]; }
//		printf("z=%d (znode=%d)\n",z,znode);

		int x,xnode;
		if(maxfree<=z+groupcnt[i]) { x=z,xnode=znode; } else { x=maxfree,xnode=prevnode[lastnode]; REP(j,groupcnt[i]) { --x; xnode=prevnode[xnode]; } }
//		printf("x=%d (xnode=%d)\n",x,xnode);

		nnewvals=0; int nmaxfree=min(min(total,maxfree+groupcnt[i]),(total+groupcnt[i])/2);
		FORE(n,maxfree+1,nmaxfree) {
			int val;
			if(x>total-n) { // -> nx=x-1	-> df(n)=2*cost-dg(x)
				val=2*groupcost[i]-nodeval[xnode];
				--x; xnode=prevnode[xnode];
			} else if(x<n-groupcnt[i]) { // -> nx=x+1		-> df(n)=dg(x+1)
				++x; xnode=nextnode[xnode];
				val=nodeval[xnode];
			} else { // -> nx=x	-> df(n)=cost
				val=groupcost[i];
			}
			newval[nnewvals++]=val;
		}
//		printf("%d new value(s):",nnewvals); REP(j,nnewvals) printf(" %d",newval[j]); puts("");

		// insert cost into existing vals
		int ninsert=min(groupcnt[i],maxfree-z),updatenode=lastnode;
		REP(j,ninsert) {
			nextnode[nnodes]=nextnode[znode]; prevnode[nnodes]=znode; nodeval[nnodes]=groupcost[i];
			nextnode[prevnode[nnodes]]=nnodes; prevnode[nextnode[nnodes]]=nnodes; ++nnodes;
			updatenode=prevnode[updatenode];
		}

		// set newvals
		REP(j,nnewvals) {
			if(updatenode==lastnode) {
				nextnode[nnodes]=lastnode; prevnode[nnodes]=prevnode[lastnode]; updatenode=nnodes;
				nextnode[prevnode[nnodes]]=nnodes; prevnode[nextnode[nnodes]]=nnodes; ++nnodes;
			}
			nodeval[updatenode]=newval[j]; updatenode=nextnode[updatenode];
		}
		while(updatenode!=lastnode) {
			prevnode[nextnode[updatenode]]=prevnode[updatenode];
			nextnode[prevnode[updatenode]]=nextnode[updatenode];
			updatenode=nextnode[updatenode];
		}

		maxfree=nmaxfree; total+=groupcnt[i];
	}
//	printf("done\n"); printlst();

	ll ret=0;
	REP(i,ngroups) ret+=(ll)groupcnt[i]*groupcost[i];
	for(int x=nextnode[firstnode];x!=lastnode;x=nextnode[x]) if(nodeval[x]>0) ret-=nodeval[x];
	return ret;
}

ll bfdp[1001][1001]; // bfdp[i][j]=minimum cost to get the items of groups [0..i), j of which need to be get free, because of purchases of items of group >=i


ll calcbfdp() {
	assert(nitems<=1000);
	makegroups();

	memset(bfdp,-1,sizeof(bfdp));
	bfdp[0][0]=0;
	REP(i,ngroups) REPE(j,nitems) if(bfdp[i][j]!=-1) {
		REPE(k,groupcnt[i]) {
			ll nval=bfdp[i][j]+(ll)k*groupcost[i]; int nj=max(0,j-k)+groupcnt[i]-k;
			if(bfdp[i+1][nj]==-1||nval<bfdp[i+1][nj]) bfdp[i+1][nj]=nval;
		}
	}
	return bfdp[ngroups][0];
}

void testrand() {
	nitems=30;
//	REP(i,nitems) itemcost[i]=(rand()*1000+rand())%1000000;
	REP(i,nitems) itemcost[i]=3+rand()%10;
	ll have=calcgood();
	ll want=calcbfdp();
	if(have!=want) {
		printf("%10lld vs %10lld\n",have,want);
		printf("%d\n",nitems);
		REP(i,nitems) { if(i!=0) printf(" "); printf("%d",itemcost[i]); } puts("");
		exit(0);
	}
}

void run(int casenr) {
	input();
	cout<<calcgood()<<endl;
//	cout<<calcbfdp()<<endl;
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
//	REP(i,1000) { printf("testing %d\n",i); testrand(); }
	return 0;
}
