#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

#define N 100005
int m , ca;
priority_queue<int> Q[101];

void work()
{
    int i , t , x , y;
    char str[10];
    printf("Case #%d:\n" , ++ ca);
    scanf("%d",&m);
    for (i = 0 ; i <= 100 ; ++ i)
        while (!Q[i].empty())
            Q[i].pop();
    while (m --)
    {
        scanf("%s" , str);
        if (*str == 'A')
        {
            scanf("%d",&t);
            pair<int , int> res(-1 << 30 , -1 << 30);
            for (i = 0 ; i <= 100 ; ++ i)
                if (!Q[i].empty())
                    res = max(res , make_pair(Q[i].top() + t * i , i));
            printf("%d %d\n" , res.first , res.second) , Q[res.second].pop();
        }
        else
        {
            scanf("%d%d%d",&t,&x,&i);
            Q[i].push(x - t * i);
        }
    }
}

int main(){
    int T;
    //freopen("1.txt","r",stdin);
    scanf("%d",&T);
    while (T --)
        work();
    return 0;
}
