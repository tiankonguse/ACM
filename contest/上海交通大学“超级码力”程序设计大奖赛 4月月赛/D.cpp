/*************************************************************************
    > File Name: D.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 19:00:23
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;


int r; //原线性规划问题中的变量个数 ，即松弛变量前的变量个数，这里也就是食品种类数
int m; //线性约束条件个数，这题目里面的，就是选手数
const double Max = 1 << 30; //最大值
double map[222][222]; //单纯性算法的表格


int main() {

    int cas;
    char name[111];
    scanf("%d",&cas);

	while(scanf("%d%d%s",&r,&m,name)!=EOF){
		//输入第一部分，是目标函数的系数
		for (int j = 1; j <= r; j++){
			scanf("%lf", &map[m+1][j]);
			map[m+1][j]=-map[m+1][j];
		}
		map[m+1][r+1]=0;//目标函数最优解初始为0
		//各个约束条件的输入
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= r + 1; j++)
				scanf("%lf", &map[i][j]);
		while (1) {
			//寻找非基本变量
			int ru;
			for (ru = 1; ru <= r + 1; ru++) {
				if (map[m + 1][ru] < 0)
					break;
			}
			//若找不到合适的非基本变量，说明目标函数已最优
			if (ru > r + 1)	break;
			double min = Max;
			//寻找基本变量
			int chu;
			for (int j = 1; j <= m; j++) {
				if (map[j][ru] > 0) {
					double term = map[j][r + 1] / map[j][ru];
					if (term < min) {
						min = term;
						chu = j;
					}
				}
			}
			//由于题目保证有解，所以基本变量一定可以找到的。此处不判断。
			//先修改表格map[chu][ru]
			map[chu][ru] = 1.0 / map[chu][ru];
			//修改表格的主元行
			for (int j = 1; j <= r + 1; j++) {
				if (j == ru)
					continue;
				map[chu][j] *= map[chu][ru];
			}
			//修改表格中其他单元格
			for (int i = 1; i <= m + 1; i++) {
				if (i == chu)
					continue;
				for (int j = 1; j <= r + 1; j++) {
					if (j == ru)
						continue;
					map[i][j] -= map[chu][j] * map[i][ru];
				}
			}
			//修改表格中主元列
			for (int j = 1; j <= m + 1; j++) {
				if (j == chu)
					continue;
				map[j][ru] = -map[j][ru] * map[chu][ru];
			}
		}
		//要求最大花销，即最优解乘以人数，向上取整。
		int ans=(int)ceil(map[m + 1][r + 1]*m);
		printf("Nasa can spend %d taka.\n",ans);
	}
	return 0;
}

