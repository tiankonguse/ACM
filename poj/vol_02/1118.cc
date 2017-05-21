#include"iostream"
#include"cstdlib"
using namespace std;
struct point{
  int x,y;
}P[701];
int main(){
    int N,max,cnt;
    while(scanf("%d",&N)&&N){
       for(int i=0;i<N;i++){
          scanf("%d%d",&P[i].x,&P[i].y);
       }
       max=0;
       for(int i=0;i<N;i++){
          for(int j=i+1;j<N;j++){
             cnt=0;
             for(int k=j+1;k<N;k++){
                 if((P[j].y-P[i].y)*(P[k].x-P[j].x)==(P[k].y-P[j].y)*(P[j].x-P[i].x)){
                     cnt++;
                 }
             }
             if(cnt>max)max=cnt;
          }
       }
       printf("%d\n",max+2);
    }
    return 0;
}
