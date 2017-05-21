#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;

int main(){
    int n, a, b, c, d, s;
    int at, bt, ct, dt;
    while(scanf("%d%d%d%d%d", &n, &a, &b, &c, &d) && n + a + b + c + d){
        s = a + 5 * b + 10 * c + 25 * d;
        at = a, bt = b, ct = c, dt = d;
        while(d){
            if(s - 25 >= n){
                s -= 25;
                d--;
            }
            else break;
        }
        if(s == n){ printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", a, b, c, d); continue;}
        while(c){
            if(s - 10 >= n){
                s -= 10;
                c--;
            }
            else break;
        }
        if(s == n){ printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", a, b, c, d); continue;}
        while(b){
            if(s - 5 >= n){
                s -= 5;
                b--;
            }
            else break;
        }
        if(s == n){ printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", a, b, c, d); continue;}
        while(a){
            if(s - 1 >= n){
                s -= 1;
                a--;
            }
            else break;
        }
        while(a + 5 <= at && c - 3 >= 0 && d + 1 <= dt){
            a += 5;
            c -= 3;
            d += 1;
        }
        if(s == n){ printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", a, b, c, d); continue;}
        else puts("Charlie cannot buy coffee.");
    }
    return 0;
}
