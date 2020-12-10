int size[N] , heavy[N] , tid[N] , Top[N] , ncnt , dep[N] , Fa[N];
// size : 子树大小
// heavy : 子树大小最大的子树（重边
// tid : 结点由重边串起来时的编号，在数据结构中维护
// Top : 结点所在重链的头
// Dep : 结点深度
// Fa  : 结点父亲
void FindHE(int x , int fa , int Dep) //找重边重儿子
{
    heavy[x] = 0 , size[x] = 1 , dep[x] = Dep , Fa[x] = fa;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != fa)
        {
            int y = e[i].x;
            FindHE(y , x , Dep + 1);
            size[x] += size[y];
            if (!heavy[x] || size[y] > size[heavy[x]])
                heavy[x] = y;
        }
}
void ConnectHE(int x , int anc) // 把重边串起来形成重链
{
    tid[x] = ++ ncnt , Top[x] = anc;
    update(1 , n , ncnt , a[x]); //单点更新值，顺便
    if (heavy[x])
        ConnectHE(heavy[x] , anc);
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != Fa[x] && e[i].x != heavy[x])
            ConnectHE(e[i].x , e[i].x);
}
int query(int x , int y) // 询问
{
    int ans = -1 << 30;
    while (Top[x] != Top[y]) // 两个结点不在一条重链上
    {
        if (dep[Top[x]] < dep[Top[y]])
            swap(x , y); // 让深度大的那条链整个遍历完，tid[Top[x]]其中包含最头那条轻边
        ans = max(ans , query(1 , n , tid[Top[x]] , tid[x]));
        x = Fa[Top[x]];
    }
    if (dep[x] > dep[y]) swap(x , y);//在一条链上了
    ans = max(ans , query(1 , n , tid[x] , tid[y]));
    return ans;
}
