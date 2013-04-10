/*
ID: shen1002
PROG: test
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
using namespace std;

int main() {
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int a, b;
    scanf("%d%d",&a,&b);
    printf("%d\n",a+b);
    return 0;
}
