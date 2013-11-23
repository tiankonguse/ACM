#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include<iostream>
#include <algorithm>

using namespace std;
int mypoint[202][2];
pair<int,int> p;
set<pair<int,int> >lines;
int gcd(int x,int y){
    if(!x || !y)return x?x:y;
    for(int t;t=x%y;x=y,y=t);
    return y;
}
int main()
{
int n,dx,dy;
while(scanf("%d",&n)!=EOF){
	lines.clear();
	for(int i=0;i<n;i++){
		scanf("%d%d",&mypoint[i][0],&mypoint[i][1]);
	}
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++){
		dx=mypoint[j][0]-mypoint[i][0],dy=mypoint[j][1]-mypoint[i][1];
		int g=gcd(dx,dy);
		dx/=g;
		dy/=g;
		lines.insert(pair<int,int>(dx,dy));
		
	}
	printf("%d\n",lines.size());
}
return 0;
}
