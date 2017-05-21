#include"iostream"
#include"cstdio"
#include"cstdlib"
#include"string.h"
#define MAXN 33
using namespace std;
char map[MAXN][MAXN];
int main(){
    int T,x,y,ca=1;
    char c;
    scanf("%d",&T);
    while(T--){
       for(int i=0;i<32;i++)for(int j=0;j<32;j++)map[i][j]='.';
       scanf("%d %d",&y,&x);
       x=32-x;
       while((c=getchar())!='.'){
           switch(c){
               case 'N':map[x-1][y]='X';x--;break;
               case 'S':map[x][y-1]='X';x++;break;
               case 'W':map[x-1][y-1]='X';y--;break;
               case 'E':map[x][y]='X';y++;break;
           }
       }
       printf("Bitmap #%d\n",ca++);
       for(int i=0;i<32;i++){
           for(int j=0;j<32;j++)
              printf("%c",map[i][j]);
           printf("\n");
       }
       printf("\n");
    }
 //   system("pause");
    return 0;
}
