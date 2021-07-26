#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<functional>
#include<functional>
#include<algorithm>
using namespace std;

int str[30][30];
int mymap[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int main(){
    int n, m, i, j, k, tmp, tmp2;
    int ans, x, y;

    while(scanf("%d%d", &n, &m), n){
        memset(str, 0, sizeof(str));
        ans = -500;
        for(i = 1; i <= n; ++i){
            for(j = 1; j <= m; ++j){
                scanf("%d", &str[i][j]);
            }
        }
        for(i = 1; i <= n; ++i){
            for(j = 1; j <= m; ++j){
                tmp = 0;
                for(k = 0; k < 4; ++k){
                    tmp2 = str[i + mymap[k][0]][j + mymap[k][1]];
                    if(str[i][j] * tmp2 < 0){
                        tmp += abs(tmp2);
                    }else{
                        tmp -= abs(tmp2);
                    }

                }
               // printf("%d ",tmp);
                if(tmp > ans){
                    ans = tmp;
                    x = i;
                    y = j;
                }

            }
            //printf("\n");
        }
        printf("%d %d %d\n", x, y, ans);

    }

    return 0;
}
