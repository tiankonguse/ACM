#include<string>
#include<iostream>
#include<queue>
using namespace std;
const int N=120;
char map[N][N];
int n,m;
int str[9][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void dfs(int i,int j){
	if(i<0 || i>=n || j<0 || j>=m || (map[i][j]=='.'))return;
	map[i][j]='.';
	for(int k=0;k<8;k++){
		dfs(i+str[k][0],j+str[k][1]);
	}
}

int find(){
	int ans=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
		if(map[i][j]=='W'){
			ans++;
			dfs(i,j);
		}
	}
	return ans;
}

int main()
{

while(~scanf("%d%d",&n,&m)){
	for(int i=0;i<n;i++){
		scanf("%s",map[i]);
	}
	printf("%d\n",find());
}

return 0;
}
