#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define N 2005
int n , m , R;
struct ball
{
    int x , y , z , R;
}C[N];
struct Point
{
    int x , y , z;
}p[16] , E;
double F[16];
int f[N] , cnt[1 << 15];

bool in(Point A , ball B)
{
    int x = A.x - B.x;
    int y = A.y - B.y;
    int z = A.z - B.z;
    return x * x + y * y + z * z <= B.R * B.R;
}

bool ins(Point A , Point B , ball C)
{
    //if (in(A , C) && in(B , C)) return 1;
    B.x -= A.x , B.y -= A.y , B.z -= A.z;
    int x = A.x - C.x , y = A.y - C.y , z = A.z - C.z;
    int a = B.x * B.x + B.y * B.y + B.z * B.z;
    int b = 2 * x * B.x + 2 * y * B.y + 2 * z * B.z;
    int c = x * x + y * y + z * z - C.R * C.R;
    int delta = b * b - 4 * a * c;
    if (delta < 0)
        return 0;
    if (delta == 0)
    {
        double p = 1.0 * -b / (2 * a);
        return p > 0 && p < 1;
    }
    double p = 1.0 * (-b + sqrt(delta)) / (2 * a);
    //if (C.R == 15)
    //    printf("**%f\n" , p);
    if (p > 0 && p < 1)
        return 1;
    p = 1.0 * (-b - sqrt(delta)) / (2 * a);
    //if (C.R == 15)
    //    printf("**%f\n" , p);
    if (p > 0 && p < 1)
        return 1;
    return 0;
}

void work()
{
    int i , j , x;
    for (i = 0 ; i < n ; ++ i)
        scanf("%d%d%d%d",&C[i].x,&C[i].y,&C[i].z,&C[i].R);
    for (i = 0 ; i < m ; ++ i)
        scanf("%d%d%d%lf",&p[i].x,&p[i].y,&p[i].z,&F[i]);
    scanf("%d%d%d",&E.x,&E.y,&E.z);
    memset(f , 0 , sizeof(f));
    memset(cnt , 0 , sizeof(cnt));
    for (i = 0 ; i < m ; ++ i)
    {
        x = (p[i].x - E.x) * (p[i].x - E.x) + (p[i].y - E.y) * (p[i].y - E.y) + (p[i].z - E.z) * (p[i].z - E.z);
        F[i] = F[i] / x;
        for (j = 0 ; j < n ; ++ j)
            if (ins(p[i] , E , C[j]))
                f[j] |= 1 << i;
    }
    //for (i = 0 ; i < n ; ++ i)
    //    printf("%d\n" , f[i]);
    for (i = 0 ; i < 1 << m ; ++ i)
        for (j = 0 ; j < n ; ++ j)
            if ((f[j] & i))
                ++ cnt[i];

    //puts("dsds");
   // for (i = 0 ; i < 1 << m ; ++ i)
    //    printf("%d\n" , cnt[i]);
    double ans = 0;
    for (i = 0 ; i < 1 << m ; ++ i)
        if (cnt[i] <= R)
        {
            double res = 0;
            for (j = 0 ; j < m ; ++ j)
                if (i >> j & 1)
                    res += F[j];
            ans = max(ans , res);
        }
    printf("%.10f\n" , ans);
}

int main(){
   // freopen("1.txt" , "r" , stdin);
    while (scanf("%d%d%d",&n,&m,&R) , n)
        work();
    return 0;
}
