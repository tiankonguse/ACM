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
#include<stdarg.h>
using namespace std;
typedef long long LL;


int main() {
int size=256<<20;
char *p=(char*)malloc(size)+size;
__asm__("movl %0, %%esp\n"::"r"(p));

    return 0;
}