#define N 20005
#define M 2000005

int n , m , nodecnt;
int s , t , pre[N] , mcnt;
struct arc
{
    int x , f , next;
}e[M];
void addarc(int x ,int y ,int z)
{
    e[mcnt] = (arc) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , z , pre[y]} , pre[y] = mcnt ++;
}

int q[N] , d[N] , cur[N] , gap[N] , neck[N] , backup[N] , p[N];

void BFS()
{
    int i , x , top = 0 , bot = -1;
    memset(gap , 0 , sizeof(gap));
    for (i = 1 ;i <= nodecnt ; i ++)
        d[i] = nodecnt + 1;
    q[++ bot] = t , d[t] = 0;
    while (top != bot + 1)
    {
        x = q[top ++];
        for (i = pre[x] ; ~i ; i = e[i].next)
        {
            int y = e[i].x;
            if (e[i ^ 1].f && d[y] == nodecnt + 1)
            {
                d[y] = d[x] + 1 , ++ gap[d[y]];
                q[++ bot] = y;
            }
        }
    }
}
int SAP()
{
    BFS();
    int x = s , i , j , y , maxflow = 0 , flow = 1 << 30;
    memcpy(cur , pre , sizeof(int) * (nodecnt + 1));
    neck[s] = s;
    while (d[s] < nodecnt)
    {
        backup[x] = flow;
        for (i = cur[x] ; ~i ; i = e[i].next)
            if (d[x] == d[e[i].x] + 1 && e[i].f)
                break;
        if (~i)
        {
            cur[x] = i;
            y = e[i].x;
            if (e[i].f < flow)
                flow = e[i].f , neck[y] = x;
            else
                neck[y] = neck[x];
            p[y] = i , x = y;
            if (x == t)
            {
                maxflow += flow;
                for (i = x ; i != s ; i = e[p[i] ^ 1].x)
                    e[p[i]].f -= flow , backup[i] -= flow , e[p[i] ^ 1].f += flow;
                x = neck[x] , flow = backup[x];
            }
        }
        else
        {
            j = -1;
            for (i = pre[x] ; ~i ;i = e[i].next)
                if (e[i].f && (!~j || d[e[i].x] < d[e[j].x]))
                    j = i;
            if (!~j || !-- gap[d[x]]) break;
            cur[x] = j;
            ++ gap[d[x] = d[e[j].x] + 1];
            if (x != s)
                x = e[p[x] ^ 1].x , flow = backup[x];
        }
    }
    return maxflow;
}
