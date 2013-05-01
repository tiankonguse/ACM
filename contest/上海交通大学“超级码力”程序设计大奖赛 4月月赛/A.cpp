/*************************************************************************
    > File Name: A.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 18:58:11
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

double str[10];
bool solve(int left)
{
    if(left == 1)
    {
        if(fabs(number[0] - 24.0) < 1E-6)
            return true;
        return false;
    }
    for(int i = 0; i < left; ++i)
        for(int j = i+1; j < left; ++j)
        {
            double a = number[i];
            double b = number[j];

            number[i] = a + b;
            number[j] = number[left-1];
            if(solve(left-1))
                return true;

            number[i] = a - b;
            number[j] = number[left-1];
            if(solve(left-1))
                return true;

            number[i] = b- a;
            number[j] = number[left-1];
            if(solve(left-1))
                return true;

            number[i] = a * b;
            number[j] = number[left-1];
            if(solve(left-1))
                return true;

            if(b)
            {
                number[i] = a / b;
            number[j] = number[left-1];
                if(solve(left-1))
                    return true;
            }

            if(a)
            {
                number[i] = b / a;
                number[j] = number[left-1];
                if(solve(left-1))
                    return true;
            }
            number[i] = a;
            number[j] = b;
        }
    return false;
}
int main() {

    int n,t;
    int cas,i;
    cin>>cas;
    while(cs--){
        cin>>n>>t;
        for(i=0;i<n;i++){
            cin>.str[i];
        }

    }

    return 0;
}
