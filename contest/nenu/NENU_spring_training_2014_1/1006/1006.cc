#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 110
using namespace std;

struct point{
	int x,y;
}s,e;

int xnext[]={1,1,2,2,-1,-1,-2,-2};
int ynext[]={2,-2,1,-1,2,-2,1,-1};
int mp[maxn][maxn];

int main(){
	int x1,x2,y1,y2,i;
	char s1[10],s2[10];
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%s%s",s1,s2)!=EOF){
		queue<point>q;
		s.x=s1[0]-'a'+1;
		s.y=s1[1]-'0';
		x2=s2[0]-'a'+1;
		y2=s2[1]-'0';
		q.push(s);
		memset(mp,-1,sizeof(mp));
		mp[s.x][s.y]=0;
		while(!q.empty()){
			s=q.front();
			q.pop();
			for(i=0;i<8;i++){
				e.x=s.x+xnext[i];
				e.y=s.y+ynext[i];
				if(mp[e.x][e.y]!=-1)continue;
				if(e.x>8||e.x<=0||e.y>8||e.y<=0)continue;
				mp[e.x][e.y]=mp[s.x][s.y]+1;
				if(e.x==x2&&e.y==y2)break;
				q.push(e);
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n",s1,s2,mp[x2][y2]);
	}
	return 0;
}
