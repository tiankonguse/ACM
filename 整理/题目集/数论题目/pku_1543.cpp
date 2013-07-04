#include <iostream>
using namespace std;

int nCubes[101];
int main()
{
    int n, a, b, c, d;
    for (int i = 1; i <= 100; ++i) {
        nCubes[i] = i*i*i;
    }
    cin>>n;
    for (a = 5; a <= n; ++a) {
        for (b = 2; b < n; ++b) {
            for (c = b+1; c < n; ++c) {
                for (d = c+1; d < n; ++d) {
                //    if (a*a*a == b*b*b + c*c*c + d*d*d) {
                //    if (pow(1.0*a,3) == pow(1.0*b,3) + pow(1.0*c,3) + pow(1.0*d,3)) {//速度慢很多很多
                    if (nCubes[a] == nCubes[b] + nCubes[c] + nCubes[d]) {
                    printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }
    return 0;
}
