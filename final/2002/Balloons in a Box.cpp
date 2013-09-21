#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
const int N=7;
int n;
double v,sv;
struct po{
    double x, y, z,r;
    void read(){scanf("%lf%lf%lf",&x,&y,&z);r=0;}
}p[N],b[2];
double len[N][N];
bool vis[N];
int sta[N],s;

const double pi = acos(-1.0)*(4.0/3.0); //pi=3.141592653
const double inf=10000000000.0;
 
double min(double a,double b){
       if(a<b)
       return a;
       else
       return b;
}

double square(double r){
	return r*r;
}

double ditance(int a,int b){
	return sqrt(square(p[a].x-p[b].x)+square(p[a].y-p[b].y)+square(p[a].z-p[b].z));
}

double findmin(const po &a,const po &b){
	double m=inf,tmp;
	tmp=fabs(a.x-b.x);if(tmp<m)m=tmp;
	tmp=fabs(a.y-b.y);if(tmp<m)m=tmp;
	tmp=fabs(a.z-b.z);if(tmp<m)m=tmp;
	return m;
}

double minst(int i){//找点i上的气球的最大半经 
		int j;
		double m=inf,tmp;
		for(j=0;j<s;j++){
			tmp=len[sta[j]][i]-p[sta[j]].r;
			if(tmp<=0.0)return 0.0;
			if(tmp<m)m=tmp;
		}
       
       tmp=findmin(b[0],p[i]);
       if(tmp<m)m=tmp;
       
       tmp=findmin(b[1],p[i]);
       if(tmp<m)m=tmp;

      return m;
}
 
void dfs(int step,double bv){
	
    if(step==n){if(bv>v)v=bv;return ;}
    step++;
    
	for(int i=0;i<n;i++){
		if(!vis[i]){
		     vis[i]=true;
		     p[i].r=minst(i);
		     sta[s++]=i;
		     dfs(step,bv + p[i].r * p[i].r * p[i].r * pi);
		     s--;
		     vis[i]=false;
		}
	}

     
}
void read(){
	s=0;
	memset(vis,0,sizeof(vis));
	v=0;
	
	b[0].read();
	b[1].read();
    sv=fabs((b[0].x-b[1].x)*(b[0].y-b[1].y)*(b[0].z-b[1].z));//算出长方体的体积 
    
	for(int i=0;i<n;i++){
		p[i].read();
    }
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
		len[i][j]=len[j][i]=ditance(i,j);
	}
}
int main(){
	int k=1;
    while(scanf("%d",&n),n){
		read();
        dfs(0,0.0);
        printf("Box %d: %.lf\n\n",k++,sv-v);
    }
    return 0;    
}
