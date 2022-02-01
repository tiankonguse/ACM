#include <stdio.h>

int main()
{
    int a,b,h,yu;
//	freopen("in.txt","r",stdin);
//	freopen("out2.txt","w",stdout);
    while(scanf("%d %d",&a,&b)!=EOF){
        h=yu=0;
        while(a >= 1){
            h += a;
            yu += a % b;
            a /= b;
            printf("%d  %d  %d\n",h,yu,a);
            if(yu/b>=1){
                a += yu / b;
                yu -= a * b;
            }
        }
        printf("%d\n",h);
    }
    return 0;
}
