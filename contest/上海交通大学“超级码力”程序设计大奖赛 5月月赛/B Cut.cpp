/*************************************************************************
    > File Name: B . Cut.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 20:31:48
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int main() {
    long long  a,b,n,sq_n,ab,aa;

    while(~scanf("%lld%lld%lld",&a,&b,&n)){

        ab = a*b;

        if(n == 0 || ab == n){
            puts("0");
            continue;
        }



        if(ab<n){
            puts("-1");
            continue;
        }

        if(a>b)swap(a,b);

        n = min(n,ab-n);
//        cout<<sqrt(n)<<endl;
//        printf("----%d\n",sqrt(n));
        sq_n = (long long)(sqrt(n));
//        printf("----%d\n",sq_n);
        if(sq_n * sq_n < n){
            sq_n++;
        }

        aa = min(a,sq_n);


        if(aa == a){
            if(n%aa == 0){
                printf("%lld\n",aa);
            }else{
                printf("%lld\n",aa+1);
            }
        }else{
            printf("%lld\n",aa<<1);
        }





    }

    return 0;
}
