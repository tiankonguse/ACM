#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 25;
struct ants
{
    int d,id;
    double p;
}a[maxn];
bool cmp(ants a,ants b){
    return a.p < b.p;
}
int n,l;
char op[19];
bool check()
{
    for(int i = 1; i <= n; ++i)
        if(a[i].p > 0 && a[i].p < l) return 0;
    return 1;
}
int main()
{
    //freopen("1.txt" , "r" , stdin);
    //freopen("1.out","w",stdout);
    while(scanf("%d%d",&n,&l),n || l){
        for(int i = 1; i <= n; ++i){
            scanf("%s%lf",op,&a[i].p);
            if(op[0] == 'L') a[i].d = 0;
            else a[i].d = 1;
            a[i].id = i;
        }
      //  printf("!!!\n")
        for(double t = 0.5;t <= 105.0; t += 0.5){
        //       printf("!!!\n");
            for(int i = 1; i <= n; ++i)
            if(a[i].d == 0){
                a[i].p -= 0.5;
            }
            else a[i].p += 0.5;
            for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j){
                if(i == j) continue;
                if(fabs(a[i].p - a[j].p) <1e-5){
                    if (fabs(t - 2) < 1e-5) {


                    }


                    double tt = floor(a[i].p + 1e-5);
                    if(fabs(tt - a[i].p) < 1e-5){
                            //printf("%lf %d %d!!!\n",t,a[i].id,a[j].id);
                        a[i].d = (a[i].d + 1) % 2;
                        a[j].d = (a[j].d + 1) % 2;
                    }
                }
            }
            //printf("%lf\n",t);
            ////for(int i = 1; i <= n; ++i){
             //   printf("%d %lf %d\n",a[i].d,a[i].p,a[i].id);
            //}
            if(check()){
                //    printf("!!!\n");
                    bool mark = 0;
                for(int i = 1; i <= n; ++i){
                    if(fabs(a[i].p) < 1e-5){
                        printf("%.0lf %d\n",t,a[i].id);
                        mark = 1;
                        break;
                    }
                }
                if(!mark){
                    for(int i = 1; i <= n; ++i){
                        if(fabs(a[i].p - l) < 1e-5){
                            printf("%.0lf %d\n",t,a[i].id);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    return 0;
}
