#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<unistd.h>
#include <time.h>
#include<stdarg.h>
using namespace std;

#define DEC_1 0
#define DEC_2 1
#define DEC_3 2
#define DEC_3 2
#define DEC_3 2
#define DEC_3 2
#define DEC_3 2
#define DEC_3 2
#define DEC_3 2

#define DEC( n ) DEC_##n

#define CHR( x, y ) CHR1( x, y )
#define CHR1( x, y ) x##y


#define LEFT_1( n ) <--
#define LEFT_2( n ) CHR( LEFT_, DEC( n ) )( DEC( n ) )--
#define LEFT_3( n ) CHR( LEFT_, DEC( n ) )( DEC( n ) )--
#define LEFT(l,r, n ) l LEFT_##n(n) r

#define TO_STRING( x ) TO_STRING1( x )
#define TO_STRING1( x ) #x

int main() {
    char s[90] = "hello";
    char a[90] = "hello";
    char * const p = s;
    s = a;
    return 0;
}
