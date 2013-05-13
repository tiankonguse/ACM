
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
#include<vector>
#include<functional>

#define PI acos(-1.0);
#define inf 0x3ffffffff;
using namespace std;
int sum(int x)
{
    return x*x;
}


int main(){

    int i,j,t;
    int a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int Min = sum(a)*300+(sum(a+b)-sum(a))*100+(sum(a+b+c)-sum(a+b))*50;
        int Max = sum(c)*50 + (sum(b+c)-sum(c))*100+(sum(a+b+c)-sum(b+c))*300;
        cout<<Min << " "<<Max<<endl;
    }
    return 0;
}
