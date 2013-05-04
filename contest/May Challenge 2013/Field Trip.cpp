/*************************************************************************
    > File Name: Field Trip.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/3 19:54:59
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
bool ok[1010][1010];
double str[1010][1010];
double fun(int m,int n){
	if(ok[m][n])return str[m][n];
	if(m==n || n==0)return ok[m][n]=true,str[m][n]=1;
	if(m<n)return ok[m][n]=true,str[m][n]=0;
	return ok[m][n]=true,str[m][n]=fun(m-1,n-1)+fun(m-1,n);
}

int main() {
    memset(ok,false,sizeof(ok));
    printf("%lf\n",fun(1000,500));
    int t,s,n,m,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&s,&n,&m,&k);

    }

    return 0;
}
