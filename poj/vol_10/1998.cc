#include"iostream"
using namespace std;
int map[1001][1001];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char str[4][10]={"doleva","doprava","nahoru","dolu"};
int R,C;
bool check(int x,int y){
    if(x>=0 && x<R && y>=0 && y<C)return true;
    else return false;
}
int main(){
    int T,q,x,y,tx,ty,tmp;
    bool flag;
    scanf("%d",&T);
    for(int c=1;c<=T;c++){
        scanf("%d%d",&R,&C);
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==0){
                   x=i;
                   y=j;
                }
            }
        }
        printf("Skladacka cislo %d:\n",c);
        while(scanf("%d",&q)&&q){
                flag=false;
                for(int i=0;i<4;i++){
                    tx=x+dir[i][0];
                    ty=y+dir[i][1];
                    if(check(tx,ty)&&map[tx][ty]==q){
                        flag=true;
                        printf("Kamen %d presunut %s.\n",q,str[i]);
                        tmp=map[x][y];
                        map[x][y]=map[tx][ty];
                        map[tx][ty]=tmp;
                        x=tx;
                        y=ty;
                    }
                    if(flag)break;
                }
                if(!flag)printf("Neplatny tah kamenem %d.\n",q);
        }
        for(int i=0;i<R;i++){
           for(int j=0;j<C;j++){
               printf("%d ",map[i][j]);
           }
           printf("\n");
        }
        printf("\n");
    }
   // system("pause");
    return 0;
}
