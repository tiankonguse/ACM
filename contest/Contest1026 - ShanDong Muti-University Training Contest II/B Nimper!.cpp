/*************************************************************************
    > File Name: B Nimper!.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/14 22:09:49
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
#define LL long long
#define ULL unsigned long long
const double eps=1e-6;
const int INF=0x3f3f3f3f;
int main()
{
    //freopen("data.in","r",stdin);
    int n;
    while(cin>>n)
    {
        int a,b,A=0,B=0;
        while(n--)
        {
            cin>>a>>b;
            if(abs(A+a-B)<=500)
            {cout<<"A";A+=a;}
            else
            {cout<<"G";B+=b;}
        }
        cout<<endl;
    }

    return 0;
}
