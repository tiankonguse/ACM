#include"iostream"
#include"algorithm"
using namespace std;
struct rec{
    int x,y;
}r[6];
int cmp(rec a,rec b){
    if(a.x==b.x)return a.y<b.y;
    else return a.x<b.x;
}
bool same(rec a,rec b){
    if(a.x==b.x && a.y==b.y)return true;
    else return false;
}
int main(){
    int a,b;
    for(int i=0;i<6;i++){
        scanf("%d%d",&a,&b);
        if(a<b){r[i].x=a;r[i].y=b;}
        else{ r[i].x=b;r[i].y=a;}
    }
    sort(r,r+6,cmp);
    if(same(r[0],r[1]) && same(r[2],r[3]) && same(r[4],r[5])){
          if(r[0].x==r[2].x){
               if((r[0].y==r[4].x)&&(r[2].y==r[4].y))printf("POSSIBLE\n");
               else printf("IMPOSSIBLE\n");
          }
          else if(r[2].x==r[4].x){
               if(r[0].x==r[2].y && r[0].y==r[4].y)printf("POSSIBLE\n");
               else printf("IMPOSSIBLE\n");
          }
          else printf("IMPOSSIBLE\n");
    }
    else printf("IMPOSSIBLE\n");
    return 0;
}
