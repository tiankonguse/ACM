#include"iostream"
#include"cstdio"
#include"cmath"
#define MAXN 13
#define SIZE 27
using namespace std;
const double h=sqrt(3.0);
const double eps=1e-6;
struct Point{
    double x,y;
}p[SIZE][3];
double dist(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double equal(double a,double b){
    if(fabs(a-b)<eps)return true;
    else return false;
}
int cnt[SIZE];
int main(){
    int N,d;
    bool flag;
    char ch;
    while(scanf("%d",&N)&&N){
        memset(cnt,0,sizeof(cnt));
        for(double i=0;i<N;i++){
            for(double j=0;j<=i;j++){
                scanf(" %c",&ch);
                d=ch-'a';
                p[d][cnt[d]].x=i*h;
                p[d][cnt[d]].y=-i+2.0*j;
                cnt[d]++;
            } 
        }     
        flag=false;
        for(int i=0;i<SIZE;i++){
            if(cnt[i]==3){
                if(equal(dist(p[i][0],p[i][1]),dist(p[i][0],p[i][2])) &&
                   equal(dist(p[i][0],p[i][1]),dist(p[i][1],p[i][2]))){
                       flag=true;
                       printf("%c",i+'a');
                   }
            }
        }
        if(flag)printf("\n");
        else printf("LOOOOOOOOSER!\n");
    }
//    system("pause");
    return 0;
}
