/*
用anMaxLen[i][j]记录从点anHeight[i][j]出发的最短路径(初始化时没有延伸,只有自己,也就是初始值为1)
状态转移方程anMaxLen[i][j]=max{opt[i+1][j], anMaxLen[i-1][j], anMaxLen[i][j+1], anMaxLen[i][j-1]} + 1   　
也就是说, anMaxLen[i][j]的值等于从anHeight[i][j]的上下左右四个方向出发所滑的最长值+1；
而这道题并不是简单的动归,计算anMaxLen[i][j]的过程需要类似DFS的递归方法.这就是记忆化搜索.
*/

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////
short delta_x[] = {-1,+1,0,0};
short delta_y[] = {0,0,-1,+1};

long nRow, nColum, x0, y0, tmp;
long anHeight[102][102], anMaxLen[102][102];
//////////////////////////////////////////////////////////////////////////

int get_max_len(int x, int y)
{
    if (anMaxLen[x][y] != 1)
        return anMaxLen[x][y];

    long max = -1;
    for (int i = 0; i < 4; ++i) {//往周围四个方向进行探测.
        x0 = x+delta_x[i];
        y0 = y+delta_y[i];
        if (x0 < 1 || x0 > nRow || y0 < 1 || y0 > nColum) {
            continue;
        }
        if (anHeight[x][y] > anHeight[x0][y0]) {
            tmp = get_max_len(x0, y0);
            if (anMaxLen[x][y] < tmp+1) {
                anMaxLen[x][y] = tmp+1;
            }
        }
    }
    return anMaxLen[x][y];
}
//////////////////////////////////////////////////////////////////////////

int main()
{
    cin>>nRow>>nColum;
    int i, j;
    for (i =1; i <= nRow; ++i) {
        for (j = 1; j <= nColum; ++j) {
            scanf("%d",&anHeight[i][j]);
            anMaxLen[i][j] = 1;//初始只包含点本身,区域长度为1
        }
    }

    long maxLen = -1;
    for (i =1; i <= nRow; ++i) {
        for (j = 1; j <= nColum; ++j) {
            if (maxLen < get_max_len(i,j)) {
                maxLen = anMaxLen[i][j];
            }
        }
    }
    cout<<maxLen<<endl;
    return 0;
}
