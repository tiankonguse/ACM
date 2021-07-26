/**************************************************************************
 **      File Name: 5.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/30 18:19:20
/**************************************************************************/

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

struct T{
    int x,y;
    void set(int x,int y){
        this->x = x;
        this->y = y;
    }
}array[1111];
int ans;
int str[111][20];
int __a[]={1,0};
int num;

int mapx[]={-2, -1, -1,  0, 0,  1, 1, 2};
int mapy[]={ 0, -1,  1, -2, 2, -1, 1, 0};

void dfs(int lev,int k){
    if(lev == num){
        if(ans < k)ans = k;
        return;
    }

    int x = array[lev].x, y = array[lev].y;

    if(str[x][y] > 0){
        dfs(lev+1,k);
        return ;
    }

    str[x][y]++;
    bool ok = true;
    for(int i=0;i<8;i++){
        if(str[x+mapx[i]][y+mapy[i]] > 0){
            ok = false;
            for(int j=i-1;j>=0;j--){
                str[x+mapx[i]][y+mapy[i]]--;
            }
            break;
        }else{
            str[x+mapx[i]][y+mapy[i]]++;
        }
    }
    if(ok){
        dfs(lev+1,k+1);
    }
    str[x][y]--;
    for(int i=0;i<8;i++){
        str[x+mapx[i]][y+mapy[i]]--;
    }

    dfs(lev+1,k);

}

/*
6 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
*/
int main(){
    int n,m,i,j;
    while(scanf("%d%d",&n,&m)!=EOF){

        n+=2;
        m+=2;

        for(i=0;i<2;i++){
            for(j=0;j<20;j++){
                str[i][j] = -100;
            }
        }
        for(i=m;i<m+3;i++){
            for(j=0;j<20;j++){
                str[i][j] = -100;
            }
        }


        num = 0;
        ans = 0;

        for(i=2;i<n;i++){
            for(j=2;j<m;j++){
                scanf("%d",&str[i][j]);
                if(str[i][j] == 1){
                    array[num++].set(i,j);
                    str[i][j] = 0;
                }else{
                    str[i][j] = -100;
                }
            }
        }


        dfs(0,0);
        printf("%d\n",ans);
    }

    return 0;
}
