#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const int N = 111;
int str[4][N][N];
bool have[N][N];
int in[N][N];
const int MIN = -100*100*100*4;
// 0 往上， 1往右，  2往下 3 当前最大值
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int NOW = 3;
int getnowMax(int i,int j){
	return max(str[UP][i][j], max(str[RIGHT][i][j], str[DOWN][i][j]));
}

int main(int argc, char* argv[]) {

	int n,m;
	int i,j;
	int _,__;
	scanf("%d",&__);
	for(_ =1; _ <= __; _++){
		scanf("%d%d",&n,&m);
		memset(str,0,sizeof(str));
		memset(have,false,sizeof(have));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&in[i][j]);
			}
		}
		str[UP][0][0] = MIN;
		str[DOWN][0][0] = str[RIGHT][0][0] = in[0][0];
		str[NOW][0][0] = getnowMax(0,0);

		for(i=1;i<n;i++){
			str[UP][i][0] = str[RIGHT][i][0] = MIN;
			str[DOWN][i][0] = str[DOWN][i-1][0] + in[i][0];
			str[NOW][i][0] = getnowMax(i,0);
		}

		for(j=1;j<m;j++){
			for(i=0;i<n;i++){
				str[RIGHT][i][j] = str[NOW][i][j-1] + in[i][j];
			}
			str[DOWN][0][j] = str[RIGHT][0][j];
			for(i=1;i<n;i++){
				str[DOWN][i][j] = max(str[RIGHT][i-1][j], str[DOWN][i-1][j]) + in[i][j];
			}
			str[UP][n-1][j] = str[RIGHT][n-1][j];
			for(i=n-2;i>=0;i--){
				str[UP][i][j] = max(str[RIGHT][i+1][j], str[UP][i+1][j]) + in[i][j];
			}
			for(i=0;i<n;i++){
				str[NOW][i][j] = getnowMax(i,j);
			}
		}
		printf("Case #%d:\n%d\n",_,str[NOW][0][m-1]);


	}
    return 0;
}






