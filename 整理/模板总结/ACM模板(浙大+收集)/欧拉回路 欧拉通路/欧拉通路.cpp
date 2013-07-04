/*
欧拉路:在一个连通图中，找到一条路径，将每条边都经过且仅经过一次。

欧拉路和欧拉回路的算法是一样的,区别在于:
1.欧拉路要求必须有且仅有2个点的度为奇数;
  这两个点就是源和汇,故在这种情况下,起点只能从这两个点中取一个;
2.而欧拉回路则是所有点的度都是偶数(N*);
  随便找一个起点就可以了;

3.通常用的算法类似于dfs遍历,只是把刚经过的边删掉;
  然后把度为0的依次插入就成了欧拉路;
*/

//zhulei632 2008-05-15
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> stk;
int n,  m;       //n-顶点数目; m-边的条数.
vector<vector<int> > mat; //邻接阵,相邻为1,否则为0
vector<int> ans; //欧拉路中的顶点序列
int start = 0;   //欧拉通路的起点

//判断是否存在欧拉通路
bool IsExitsEulerRoute()
{
    int num = 0;
    
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        for (int j = 0; j < n; ++j) 
            tmp += (mat[i][j]);// + mat[j][i]);        
        
        if (tmp%2 == 1) {//度数为奇数?
            ++num;
            start = i;
        }
    }
    //0个或2个奇度数顶点,则存在欧拉通路
    if (num == 0 || num == 2) 
        return true;
    else 
        return false;
}

//深度遍历
void dfs(int vex) 
{
    stk.push(vex);
    for (int i = 0; i < n; ++i) {
        if (mat[i][vex] != 0) {
            mat[i][vex] = mat[vex][i] = 0;
            dfs(i);
            break;
        }
    }
    return ;
}

//寻找欧拉通路
void findEulerRoute(int start)
{
    int i, top;

    stk.push(start);
    while (!stk.empty()) {        
        top = stk.top();
        stk.pop();

        //寻找度数为0的点
        bool flag = false;
        for (i = 0; i < n; ++i) {
            if (mat[top][i] > 0) {
                flag = true;  
                break;
            }
        }
        //没有点可以扩展
        if (flag == false)
            ans.push_back(top+1);
        //还可以扩展
        else 
            dfs(top);            
    }    
}

int main()
{
    int from, to;
    
    cin>>n;
    mat = vector<vector<int> >(n, vector<int>(n, 0));
    
    cin>>m;
    //mat中从下标0开始存数据
    for (int i = 0; i < m; ++i) {
        cin>>from>>to;
        mat[from-1][to-1] = 1; 
        mat[to-1][from-1] = 1;
    }
    
    if (IsExitsEulerRoute()) {
        findEulerRoute(start);
        for(int i = 0; i < ans.size(); ++i) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else {
        cout<<"No euler route exists."<<endl;
    }
    return 0;
}

/*

测试数据:
输入:
6 6

1 2 
1 6
2 6
3 4
4 5
5 6
输出:
3 4 5 6 2 1 6

*/