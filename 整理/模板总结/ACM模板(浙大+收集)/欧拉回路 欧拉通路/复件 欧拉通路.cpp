/*欧拉路算法
1、找一个顶点进栈(存在奇度数的图一定将一个奇度数顶点进栈)
2、从栈顶元素开始，对图进行深度优先遍历，遍历过一条边就把那条边删除。一直到某一点没有与它相连的边。
3、将栈顶元素输出，出栈。如果栈没有空转向2。
*/
//参考程序
// http://liymouse.bokee.com/5054182.html
//输入一个无向图，先判断是否存在欧拉路，若有求出一条欧拉路
//先输入顶点数和边数，之后输入每条边连接的2个点
//例如
//5 6   (5个点，6条边)
//1 2
//1 3
//2 3
//2 4
//2 5
//4 5

#include <stdio.h>
#include <string.h>

struct stack{int top , node[210];} f; //顶点的堆栈
int a[201][201]; //图的邻接矩阵

int n;

void dfs(int x)     //图的深度优先遍历
{
	int i;
    f.top ++; f.node[f.top] = x;
    for (i = 1; i <= n; i ++)
        if (a[i][x] > 0) {
            a[i][x] = 0; a[x][i] = 0;   //删除此边
            dfs(i);
            break;
        }
}

void Euler(int x)   //欧拉路算法
{
	int i , b;
    f.top = 0; f.node[f.top] = x;   //入栈
    while (f.top >= 0) {
        b = 0;
        for (i = 1; i <= n; i ++)
			if (a[f.node[f.top]][i] > 0) {
				b = 1;
				break;
			}
			if (b == 0) {  //如果没有点可以扩展，输出并出栈
				printf("%d ", f.node[f.top]);
				f.top --;
			}
			else {
				f.top --;
				dfs(f.node[f.top+1]);
			}      //如果有，就DFS
    }
}

int main()
{
	int m , from , to;
	int tmp, num, start, i , j , s;

    //input
    scanf("%d %d" , &n , &m); //n顶点数  m边数
    memset(a , 0 , sizeof(a));
    for (i = 0; i < m; i ++) {
        scanf("%d %d" , &from , &to); //边的两端点
        a[from][to] = 1;
		a[to][from] = 1;
    }


    {//判断是否存在欧拉回路
        num = 0;
        start = 1;
        for (i = 1; i <= n; ++i) {
            tmp = 0;
            for (j = 1; j <= n; ++j)
                tmp += a[i][j];
            if (tmp % 2 == 1) {
                start = i;
                ++num;
            }
        }
    }

    if ((num == 0) || (num == 2))
		Euler(start);
    else
		printf("No Euler path\n");

    getchar();
	getchar();
    return 0;


}
