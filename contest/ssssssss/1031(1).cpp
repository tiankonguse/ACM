#include <iostream>
 
using namespace std;
 
const int nn = 1002, mm = nn * 2, inf = 1000000000;
int n, tot, now;
int a[nn], b[nn], head[nn], color[nn];
int adj[mm], next[mm];
int stack[3][nn];
bool result;
 
void addEdge(int x, int y) //�ӱ�
{
    ++ tot;
    adj[tot] = y;
    next[tot] = head[x];
    head[x] = tot;
}
 
bool dfs(int i) //DFSȾɫ,���ͼ�Ƿ��Ƕ���ͼ�ľ����㷨
{
    int temp = head[i];
    while (temp) //�ڽӱ�,���ÿһ����
    {
        if (! color[adj[temp]]) //����뵱ǰ���Ľ�㻹δȾɫ
        {
            color[adj[temp]] = 3 - color[i]; //����Ⱦɫ
            dfs(adj[temp]); //DFS
        }
        if (color[adj[temp]] == color[i]) return false;
            //����������ڽ��Ⱦɫ��ͬ,˵����ͼ���Ƕ���ͼ,�����޽�
        temp = next[temp];
    }
    return true;
}
 
int main()
{
   ///freopen("twostack.in", "r", stdin);
   // freopen("twostack.out", "w", stdout);
 
    //����
    while(~scanf("%d", &n)){
    for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
 
    //Ԥ����b����
    b[n + 1] = inf;
    for (int i = n; i >= 1; -- i) b[i] = min(b[i + 1], a[i]); //"min" in STL
 
    //ö������(i,j)���ӱ�
    tot = 0;
    for (int i = 1; i <= n; ++ i)
        for (int j = i + 1; j <= n; ++ j)
            if (b[j + 1] < a[i] && a[i] < a[j])
            {
                addEdge(i, j);
                addEdge(j, i);
            }
 
    //DFSȾɫ
    memset(color, 0, sizeof(color));
    result = true;
    for (int i = 1; i <= n; ++ i) //ÿ���ҵ�ǰδȾɫ�ı����С�Ľ��,��Ⱦ��ɫ1
        if (! color[i]) //��ǰλ����δ��Ⱦɫ
        {
            color[i] = 1;
            if (! dfs(i)) //Ⱦɫʱ����ì��,��ʱͼ����һ������ͼ,���޷����䵽����ջ��
            {
                result = false; //��¼�޽�
                break;
            }
        }
 
    if (! result) //�޽�
        printf("0\n");
    else //�н�
    {
        //ģ�����
        now = 1;
        for (int i = 1; i <= n; ++ i)
        {
            //����ǰ����ѹ���Ӧ��ջ
            if (color[i] == 1)
                printf("a ");
            else
                printf("c ");
            stack[color[i]][0] ++;
            stack[color[i]][stack[color[i]][0]] = a[i]; //this will work even if stack[1][0] = 0
 
            //ѭ�����,������ԵĻ��ʹ�ջ������Ԫ��
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
