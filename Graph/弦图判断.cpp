#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N=1005;

/*
弦图定义：不存在环满足(长度大于3)&&(环上任意非相邻点间无边) 的一个图。
完美消除序列的性质是：
对于序列中第i个点Vi。
令S={Vj | (j>i) && ((Vi,Vj) in E)}，那么S+Vi成一个团。
一个图是弦图当且仅当存在完美消除序列.
另有求弦图色数的经典性质:
{
	色数(用最少种颜色涂满图中的点，使得每条边两端的点颜色都不同)>=团数(最大团的点数)
	因为是弦图，由完美消除序列的性质可以构造得色数=团数，于是达到下界。
	于是直接利用完美消除序列的性质求出团数即可。
}
使用说明：
	点标号从1~n，mat[x][y]=1表示有边.
*/

int n,m;
int label[N];
int Cnt[N];
int mat[N][N];
int Q[N];
vector <int> vec;

void make_sequence(){
	for (int i=1;i<=n;i++) Cnt[i]=label[i]=0;
	for (int i=n;i>=1;i--){
		int Max=-1;
		int Maxi=-1;
		for (int j=1;j<=n;j++)
			if (!label[j] && Cnt[j]>Max){
				Max=Cnt[j];
				Maxi=j;
			}
		label[Maxi]=i;
		Q[i]=Maxi;
		for (int j=1;j<=n;j++)
			if (label[j]==0 && mat[Maxi][j])
				Cnt[j]++;
	}
}

bool check(){
	for (int i=1;i<=n;i++){
		vec.clear();
		for (int j=1;j<=n;j++)
			if (mat[i][j] && label[j]>label[i])
				vec.push_back(j);
		for (int j=1;j<vec.size();j++)
			if (label[vec[j]]<label[vec[0]])
				swap(vec[j],vec[0]);
		for (int j=1;j<vec.size();j++)
			if (!mat[vec[0]][vec[j]]) return false;
	}
	return true;
}

int main(){
	while (1){
		scanf("%d%d",&n,&m);
		if (!n && !m) break;
		memset(mat,0,sizeof(mat));
		for (int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			mat[x][y]=mat[y][x]=1;
		}
		make_sequence();
		if (check()) printf("Perfect\n\n");
		        else printf("Imperfect\n\n");
	}
}
