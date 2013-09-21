#include <iostream>
#include <string>
#include <queue>
using namespace std;
//////////////////////////////////////////////////////////////////////////

class info {
public:
    int x, y;
    info(int i=0, int j=0):x(i),y(j){};
};
//////////////////////////////////////////////////////////////////////////
//全局变量
int W, H;
char a[20][20];
//////////////////////////////////////////////////////////////////////////
//递归解法
int reach(int x, int y)
{
    if (x < 0 || x > H-1 || y < 0 || y > W-1 || a[x][y] == '#') 
        return 0;
    
    a[x][y] = '#';
    return 1+reach(x-1, y)+reach(x+1, y)+reach(x, y-1)+reach(x, y+1); 
}
//////////////////////////////////////////////////////////////////////////
//宽度搜索
int reach_BFS(int x, int y)
{
    int count = 0;
    queue<info> open;
    bool flags[20][20];
    memset(flags, false, 20*20*sizeof(bool) );
    //                上  下 左 右
    int delta_x[4] = {-1, 1, 0, 0};
    int delta_y[4] = { 0, 0,-1, 1};
    
    open.push(info(x, y));
    while (!open.empty()) {
        info temp = open.front();
        open.pop();
        flags[temp.x][temp.y] = true;

        if (a[temp.x][temp.y] == '.' || a[temp.x][temp.y] == '@') {
            ++count;
            a[temp.x][temp.y] = '#';
        }
        for (int i  = 0; i < 4; ++i) {
            int x0 = temp.x + delta_x[i], y0 = temp.y + delta_y[i];
            //越界或为黑砖
            if (x0 < 0 || x0 > H-1 || y0 < 0 || y0 > W-1 || a[x0][y0] == '#')
                continue;

            if (flags[x0][y0] == false && a[x0][y0] == '.') {
                open.push(info(x0, y0));
                flags[x0][y0] = true;
            }
        }
    }
    return count;
}
//////////////////////////////////////////////////////////////////////////

int main()
{
    int x, y, pos_x, pos_y;
    while (cin>>W>>H ) {
        if (W == 0 || H == 0) 
            break;
        
        for (x = 0; x < H; ++x) {
            for (y = 0; y < W; ++y) {
                cin>>a[x][y];
                if (a[x][y] == '@') {
                    pos_x = x;
                    pos_y = y;
                }
            }//for
        }//for
       // cout<<reach(pos_x, pos_y)<<endl; //递归解法
        cout<<reach_BFS(pos_x, pos_y)<<endl; //宽度搜索
    }
    return 0;
}
