
#include<cstdio>
#include<cstring>
#include<algorithm>
char const X = 'x';
char const S = 'S';
char const dot = '.';

char str[81][81];

struct T{
    int x,y;
    void init(int _x,int _y){
        x = _x;y=_y;
    }
}start;

int _map[4][2]={{0,-1},{0,1},{1,0},{-1,0}};


bool bfs(int x,int y,int lev){
//    printf("---%d  %d\n",x,y);


//    printf("--lev=%d  x=%d  y=%d\n",lev,x,y);
    str[x][y] = X;
    int _x,_y;
    for(int i=0;i<4;i++){
            _x = x+_map[i][0];
            _y = y+_map[i][1];
        if(str[_x][_y] == X)continue;
        if(!bfs(_x,_y,lev+1)){
            str[x][y] = dot;
            return true;
        }
    }
    str[x][y] = dot;

    return false;
}

int main(){
    int n,m,i,j;
    while(~scanf("%d%d",&n,&m)){
        memset(str,X,sizeof(str));
        for(i=1;i<=n;i++){
            scanf("%s",str[i]+1);
            str[i][m+1] = X;
        }
        bool ok = false;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                    if(str[i][j] == S){
                        start.init(i,j);
                        str[i][j] = dot;
                        ok = true;
                        break;
                    }
            }
            if(ok){
                break;
            }
        }
//        printf("x=%d  y=%d\n",start.x,start.y);
//        for(i=0;i<=n+1;i++){
//            for(j=0;j<=m+1;j++){
//                putchar(str[i][j]);
//            }
////            puts("");
//        }
//        puts("--begin");
        printf("%s\n",(bfs(start.x,start.y,0))?"Yes":"No");

    }
}

