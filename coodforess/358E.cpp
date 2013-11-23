#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef int LL;

const int N = 1111;
bool str[N][N];
bool have[N][N];
int n,m;
int _x[] = {0,0,1,-1};
int _y[] = {1,-1,0,0};


int maxEdge,oldEdgeNum;
int maxDotNum, dotNum;

bool haveAngle(int x, int y){
    return (str[x-1][y] && str[x][y+1]) || (str[x-1][y] && str[x][y-1]) || (str[x+1][y] && str[x][y-1]) || (str[x+1][y] && str[x][y+1]);
}

int getEdge(int x, int y){
    int ans = 0;
    for(int i=0;i<4;i++){
        ans += str[x+_x[i]][y+_y[i]] ;
    }
    return ans;
}

LL gcd(LL x,LL y){
	if(!x || !y)return x?x:y;
	for(LL t;t=x%y;x=y,y=t);
	return y;
}

void dfs(int x,int y){
    dotNum++;
    have[x][y] = true;
    bool angle = haveAngle(x,y);
    int edge = getEdge(x,y);

    if(edge & 1){
        oldEdgeNum++;
    }
    int xx,yy;
    for(int i=0;i<4;i++){
        xx = x + _x[i];
        yy = y + _y[i];
        if(str[xx][yy] && !have[xx][yy]){
            dfs(xx,yy);
        }
    }
}

void findMaxEdge(){
    int now;
    for(int i=1;i<=n;i++){
        int pre = -1;
        for(int j=1;j<=m;j++){
            if(str[i][j]){
                if(pre == -1){
                    pre = j;
                }else{
                    if(haveAngle(i,j)){
                        now = j - pre;
                        if(maxEdge == -1){
                            maxEdge = now;
                        }else{
                            maxEdge = gcd(maxEdge,now);
                            if(maxEdge == 1){
                                return ;
                            }
                        }
                        pre = j;
                    }
                }
            }else{

                if(pre!=-1 && j> pre+1){
                        now = j -1  - pre;
                        if(maxEdge == -1){
                            maxEdge = now;
                        }else{
                            maxEdge = gcd(maxEdge,now);
                            if(maxEdge == 1){
                                return ;
                            }
                        }
                }
                pre = -1;
            }
        }
    }
//    printf("mm =%d\n",maxEdge);
     for(int j=1;j<=m;j++){
        int pre = -1;
        for(int i=1;i<=n;i++){
            if(str[i][j]){
                if(pre == -1){
                    pre = i;
                }else{
                    if(haveAngle(i,j)){
                        now = i - pre;
                        if(maxEdge == -1){
                            maxEdge = now;
                        }else{
                            maxEdge = gcd(maxEdge,now);
                            return ;
                        }
                        pre = i;
                    }
                }
            }else{
                if(pre != -1 && i > pre+1){
                        now = i -1  - pre;
                        if(maxEdge == -1){
                            maxEdge = now;
                        }else{
                            maxEdge = gcd(maxEdge,now);
                            if(maxEdge == 1){
                                return ;
                            }
                        }
                }
                pre = -1;
            }
        }
    }

    if(maxEdge == -1){
        maxEdge = maxDotNum - 1;
    }
}

int main() {

    int i,j,tmp;
    bool ok ;
    int x,y;
    while(~scanf("%d%d",&n,&m)){
        maxEdge = -1;
        ok = true;
        dotNum = maxDotNum = 0;
        oldEdgeNum = 0;

        memset(str,false,sizeof(str));
        memset(have,false,sizeof(have));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&tmp);
                if(ok  && tmp){
                    ok = false;
                    x = i,y = j;
                }
                if(tmp){
                    maxDotNum++;
                }
                str[i][j] = tmp;
            }
        }
        dfs(x,y);

        if(maxDotNum > 2 && dotNum == maxDotNum && (oldEdgeNum==0 || oldEdgeNum==2) ){
            findMaxEdge();
//            printf("max=%d\n",maxEdge);
            if(maxEdge == 1){
                printf("-1\n");
            }else{
                for(i=2;i<=maxEdge;i++){
                    if(maxEdge % i == 0){
                        printf("%d ",i);
                    }
                }
                puts("");

            }

        }else{
            printf("-1\n");
        }


    }



    return 0;
}
/*
11 11
1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 1

*/
