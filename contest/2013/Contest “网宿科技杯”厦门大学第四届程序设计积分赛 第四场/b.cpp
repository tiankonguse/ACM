/*************************************************************************
    > File Name: b.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/4 19:19:04
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

int main() {
        int a,b;
        while(cin>>a>>b){
            cout<<(a==b && a==1?"Bob":"Alice")<<endl;
        }
    return 0;
}
