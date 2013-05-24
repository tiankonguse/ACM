#include <iostream>
using namespace std;
int p, q, r, s;
inline unsigned long double solve_pqrs()
{
    unsigned long double res = 1.0;
    int i;
    if ( q > s) {
        for (i = 1; i <= q; ++i) {
            res *= p--, res /= i;
            if (i <= s) {
                res /= r--, res *= i;
            }
        }
    }
    else {
         for (i = 1; i <= s; ++i) {
            res /= r--, res *= i;
            if (i <= q) {
                res *= p--, res /= i;
            }
        }
    }    
    return  res;
}


int main()
{
    while (scanf("%d %d %d %d", &p, &q, &r, &s) == 4) {
        printf("%.5lf\n",solve_pqrs() );
    }
    return 0;
}
