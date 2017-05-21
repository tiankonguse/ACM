#include"iostream"
using namespace std;
double r2[5]={9,36,81,144,225};
int score[5]={100,80,60,40,20};
int find(double x,double y){
   int i;
   double r=x*x+y*y;
   for(i=0;i<5;i++){
      if(r<=r2[i])break;
   }
   return i;
}
int main(){
    int s1,s2;
    double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",
          &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&x5,&y5,&x6,&y6)){
        if(x1==-100)break;
        s1=score[find(x1,y1)]+score[find(x2,y2)]+score[find(x3,y3)];
        s2=score[find(x4,y4)]+score[find(x5,y5)]+score[find(x6,y6)];
        printf("SCORE: %d to %d, ",s1,s2);
        if(s1==s2)printf("TIE.\n");
        else if(s1>s2)printf("PLAYER 1 WINS.\n");
        else printf("PLAYER 2 WINS.\n");
        
    }
    return 0;
}
