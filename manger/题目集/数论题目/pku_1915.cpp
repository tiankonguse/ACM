#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//////////////////////////////////////////////////////////////////////////
typedef struct {  
    int x, y;
    int depth;
}Point;
//////////////////////////////////////////////////////////////////////////

int nBoardSize, nIndexTop;
bool bVisited[300][300];

//八个不同的方向移动时坐标变化大小
int delta_x[8] = {-2,-2,-1,-1,+1,+1,+2,+2};
int delta_y[8] = {-1,+1,-2,+2,-2,+2,-1,+1};
//////////////////////////////////////////////////////////////////////////

int search_the_path(Point& start, Point& end)
{ 
    if (start.x == end.x && start.y == end.y) {
        return 0;
    }

    Point pre, child;
    int new_x, new_y;
    //queue<Point> open; 
    vector<Point> open;
    
    nIndexTop = 0;
    open.push_back(start);
    while (!open.empty()) {
        // pre = open.front(); 
        pre = open[nIndexTop];
        // open.pop();
        nIndexTop++;        
        bVisited[pre.x][pre.y] = true;
        
        for (int i = 0; i < 8; ++i) {
            new_x = pre.x+delta_x[i];
            new_y = pre.y+delta_y[i];
            
            //越界或者已经访问过
            if (new_x < 0 || new_x > nBoardSize-1 || new_y < 0 || new_y > nBoardSize-1
                || bVisited[new_x][new_y] == true) {
                continue;
            }

            //新状态为目标状态
            if (new_x == end.x && new_y == end.y) {            
                return pre.depth+1;
            }
            //不是目标状态
            else { 
                child.x = new_x;
                child.y = new_y;
                child.depth = pre.depth + 1;
                bVisited[child.x][child.y] = true;
                open.push_back(child);
            }
        }//for
    }//while
    return -1;
}
//////////////////////////////////////////////////////////////////////////

int main()
{
    int n;
    Point start, end;
    cin>>n;
    while (n--) {
        cin>>nBoardSize;
        cin>>start.x>>start.y;
        cin>>end.x  >>end.y;
        start.depth = 0;
        memset(bVisited, false, 300*300*sizeof(bool) );
        cout<<search_the_path(start, end)<<endl;
    }
    return 0;
}
