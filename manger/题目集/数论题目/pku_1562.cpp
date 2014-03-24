#pragma  warning(disable:4786)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m, n;
vector<string> grids;

int dfs(int x, int y)
{
    int res = 1;
    grids[x][y] = '?';
    if (x < 0 || y < 0 || x >= m || y >= n) {
        return 0;
    }
    else {
        //上下左右
        if (x-1 >= 0 && grids[x-1][y] == '@')
            res += dfs(x-1, y);
        if (x+1 < m  && grids[x+1][y] == '@')
            res += dfs(x+1, y);
        if (y-1 >= 0 && grids[x][y-1] == '@')
            res += dfs(x, y-1);
        if (y+1 < n  && grids[x][y+1] == '@')
            res += dfs(x, y+1);
        //主次对角方向
        if (x-1 >= 0 && y-1 >= 0 && grids[x-1][y-1] == '@')
            res += dfs(x-1, y-1);

        if (x+1 < m  && y-1 >= 0 && grids[x+1][y-1] == '@')
            res += dfs(x+1, y-1);

        if (x-1 >= 0 && y+1 < n  && grids[x-1][y+1] == '@')
            res += dfs(x-1, y+1);

        if (x+1 < m  && y+1 < n  && grids[x+1][y+1] == '@')
            res += dfs(x+1, y+1);
    }
    return res;        
}

int main()
{
    int i, j;
    int nums;
    while (cin>>m>>n && m && n) {
        grids.resize(m);
        nums = 0;
        for (i = 0; i < m; ++i) 
                cin>>grids[i];        

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j)
                if (grids[i][j] == '@'){
                    dfs(i, j);
                    ++nums;
                }
        }
        cout<<nums<<endl;
    }
    return 0;
}
