/*
ID: dd.ener1
PROG: fc
LANG: C++
*/

#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

struct point{
	double x,y;
	double agl;
	point operator-(point p)const{
		point r;
		r.x=x-p.x;
		r.y=y-p.y;
		return r;
	}
}P[11000];
int N;
int s[11000];//stack
int S;//size
double res;

void input(){
	freopen("fc.in","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%lf%lf",&P[i].x,&P[i].y);
}
int compare(const void* a,const void* b){
	if(((point*)a)->agl<((point*)b)->agl)return -1;
	if(((point*)a)->agl>((point*)b)->agl)return 1;
	return 0;
}
void pretreat(){
	int min=0;
	for(int i=1;i<N;++i)
		if(P[i].y<P[min].y||(P[i].y==P[min].y&&P[i].x<P[min].x))
			min=i; 
	point t=P[0];
	P[0]=P[min];
	P[min]=t;
	for(int i=1;i<N;++i)
		P[i].agl=atan2(P[i].y-P[0].y,P[i].x-P[0].x);
	qsort(P+1,N-1,sizeof(point),compare);
}
inline int zcross(point a,point b){
	double p=a.x*b.y-b.x*a.y;
	if(p>0)
		return 1;
	if(p<0)
		return -1;
	return 0;
}
inline double sqr(double d){
	return d*d;
}

inline double length(int a,int b){
	return sqrt(sqr(P[a].x-P[b].x)+sqr(P[a].y-P[b].y));
}

inline bool badjob(const point& a,const point& b,const point& c){
	return zcross(b-a,c-a)<0;
}

void solve(){
	res=0;
	if(N<=3)return;
	pretreat();
	s[0]=0;
	s[1]=1;
	s[2]=2;
	S=3;
	for(int i=3;i<N;++i){
		while(badjob(P[s[S-2]],P[s[S-1]],P[i]))
			--S;
		s[S++]=i;
	}
	for(int i=0;i<S-1;++i)
		res+=length(s[i],s[i+1]);
	res+=length(s[S-1],s[0]);
}

void output(){
	freopen("fc.out","w",stdout);
	if(res==0){
		for(int i=0;i<N-1;++i)
			res+=length(i,i+1);
		res+=length(N-1,0);
	}
	printf("%.2lf\n",res);
} 

int main(){
	//freopen("fc.log","w",stdout);
	input();
	solve();
	output();
}
