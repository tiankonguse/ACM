#include"iostream"
#include"algorithm"
using namespace std;
struct mk{
   int x,y;
}mon[50001];
int cmp(mk a,mk b){
    if(a.x==b.x)return a.y>b.y;
    else return a.x>b.x;
}
int main(){
    int N,mx,my,a,b,cnt;
    while(scanf("%d",&N)&&N){
       for(int i=0;i<N;i++){
          scanf("%d%d",&mon[i].x,&mon[i].y);
       }
       sort(mon,mon+N,cmp);
       my=mon[0].y;
       cnt=1;
       for(int i=0;i<N;i++){
           if(mon[i].y>my){
              my=mon[i].y;
              cnt++;
           }
       }
       printf("%d\n",cnt);
    }   
    return 0;
}
