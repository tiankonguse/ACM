/*************************************************************************
    > File Name: b.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 13:11:48
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

const int N=1111;
int n,V,L,X;
int f[N];
int a[N];
int main() {

    int cas,i,j;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d",&L,&X,&n);
        V = L - X;

        if(V <= 0){
            printf("No\n");
            continue;
        }

        for(i=1;i<=n;i++)
          scanf("%d",&a[i]);

          memset(f,false,sizeof(f));

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i]+a[j]<=1000)
                    f[a[i]+a[j]]=1;
            }
        }
        bool ok=false;
        for(i=1;i<V;i++)
        {
           if(f[V-i] && f[i]){
               ok = true;
               break;
           }
        }

        printf("%s\n",ok?"Yes":"No");

    }

    return 0;
}
