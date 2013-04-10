#include <iostream>
 
using namespace std;
 
const int nn = 1002, mm = nn * 2, inf = 1000000000;
int n, tot, now;
int a[nn], b[nn], head[nn], color[nn];
int adj[mm], next[mm];
int stack[3][nn];
bool result;
 
void addEdge(int x, int y) //加边
{
    ++ tot;
    adj[tot] = y;
    next[tot] = head[x];
    head[x] = tot;
}
 
bool dfs(int i) //DFS染色,检查图是否是二分图的经典算法
{
    int temp = head[i];
    while (temp) //邻接表,检查每一条边
    {
        if (! color[adj[temp]]) //如果与当前结点的结点还未染色
        {
            color[adj[temp]] = 3 - color[i]; //进行染色
            dfs(adj[temp]); //DFS
        }
        if (color[adj[temp]] == color[i]) return false;
            //如果两个相邻结点染色相同,说明此图不是二分图,返回无解
        temp = next[temp];
    }
    return true;
}
 
int main()
{
   ///freopen("twostack.in", "r", stdin);
   // freopen("twostack.out", "w", stdout);
 
    //输入
    while(~scanf("%d", &n)){
    for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
 
    //预处理b数组
    b[n + 1] = inf;
    for (int i = n; i >= 1; -- i) b[i] = min(b[i + 1], a[i]); //"min" in STL
 
    //枚举数对(i,j)并加边
    tot = 0;
    for (int i = 1; i <= n; ++ i)
        for (int j = i + 1; j <= n; ++ j)
            if (b[j + 1] < a[i] && a[i] < a[j])
            {
                addEdge(i, j);
                addEdge(j, i);
            }
 
    //DFS染色
    memset(color, 0, sizeof(color));
    result = true;
    for (int i = 1; i <= n; ++ i) //每次找当前未染色的编号最小的结点,并染颜色1
        if (! color[i]) //当前位置尚未被染色
        {
            color[i] = 1;
            if (! dfs(i)) //染色时出现矛盾,此时图不是一个二分图,即无法分配到两个栈中
            {
                result = false; //记录无解
                break;
            }
        }
 
    if (! result) //无解
        printf("0\n");
    else //有解
    {
        //模拟求解
        now = 1;
        for (int i = 1; i <= n; ++ i)
        {
            //将当前数字压入对应的栈
            if (color[i] == 1)
                printf("a ");
            else
                printf("c ");
            stack[color[i]][0] ++;
            stack[color[i]][stack[color[i]][0]] = a[i]; //this will work even if stack[1][0] = 0
 
            //循环检查,如果可以的话就从栈顶弹出元素
            while (stack[1][stack[1][0]] == now || stack[2][stack[2][0]] == now)
            {
                if (stack[1][stack[1][0]] == now)
                {
                    printf("b ");
                    stack[1][0] --;
                }
                else if (stack[2][stack[2][0]] == now)
                {
                    printf("d ");
                    stack[2][0] --;
                }
                now ++;
            }
        }
    }
	}
	return 0;
}
