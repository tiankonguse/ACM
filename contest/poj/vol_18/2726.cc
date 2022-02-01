#include"iostream"
#include"algorithm"
using namespace std;
struct hotel{
    int x,y;
}h[10001];
int cmp(hotel a,hotel b){
     if(a.x==b.x)return a.y>b.y;
     else return a.x<b.x;
}
int main(){
    int N,min,cnt,tx;
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++)scanf("%d%d",&h[i].x,&h[i].y);
        sort(h,h+N,cmp);
        min=10001;
        tx=-1;
        cnt=0;
        for(int i=0;i<N;i++){
           if(h[i].y<min){
            min=h[i].y;
            if(h[i].x!=tx){
                cnt++;
                tx=h[i].x;    
            }
           }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
