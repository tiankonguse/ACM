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
bool f[4][N];
int a[i];
int que[4][N];
int queNum[4];

int main() {

    int cas,i,j,tmp;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d",&L,&X,&n);
        V = L - X;

        if(V <= 0){
            printf("No\n");
            continue;
        }

        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        memset(f,false,sizeof(f));

        queNum[0] = 0;
        for(i=0;i<n;++i){
            if(!f[0][a[i]]){
                que[0][queNum[0]++]=a[i];
                f[0][a[i]]=true;
            }
        }

        queNum[1] = 0;


        for(i=0;i<n;i++){
            for(j=0;j<queNum[0];j++){
                tmp = a[i] + que[0][j];
                if(tmp > V)continue;
                if(f[1][a[i]]){

                }
            }
        }

        for(i=1;i<=4;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                {
                    f[i][j]=f[i]
                }
            }
        }
        printf("%s\n",str[V] == V?"Yes":"No");

    }

    return 0;
}
