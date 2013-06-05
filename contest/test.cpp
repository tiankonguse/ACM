#include <cstdio>
#include <cmath>
typedef double Type;
typedef long long LL;
double eps = 1e-6;
int const maxn = 1e6;
LL f(int *p, int i, int final){
    if(i == 0){
        return 0;
    }
    if(p[i] == final){
        return f(p,i-1,final);
    }else{
        return f(p,i-1,6 - p[i] - final) +
    }
}

int main(void) {

    return 0 ;
}
