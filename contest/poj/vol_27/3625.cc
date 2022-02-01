#include"iostream"
#include"cstdlib"
#include"cmath"
#define MAXN 1001
using namespace std;
struct point{
   double x,y;       
}ps[MAXN];
double map[MAXN][MAXN];
int N,M;
bool inTree[MAXN];   
double min_length[MAXN];     
double prim(int n)   
{   
    double res=0;
    memset(inTree,false,sizeof(inTree));
    for(int i=1;i<n;i++)min_length[i]=1e10;
    min_length[0]=0;
    for(int i=0;i<n;i++){
        int min_index=-1;
        for(int j=0;j<n;j++){
          if(!inTree[j]&&(min_index==-1 || min_length[j]<min_length[min_index])){
             min_index=j;
          }
        }
        inTree[min_index]=true;
        res+=min_length[min_index];
        for(int j=0;j<n;j++){
           if(!inTree[j] && map[j][min_index]<min_length[j]){
                 min_length[j]=map[j][min_index];
           }
        }
    }
    return res;
}   
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    int a,b;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
         scanf("%lf%lf",&ps[i].x,&ps[i].y);
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            map[i][j]=map[j][i]=dist(ps[i].x,ps[i].y,ps[j].x,ps[j].y);
        }
    } 
    for(int i=0;i<M;i++){
        scanf("%d%d",&a,&b);
        map[a-1][b-1]=map[b-1][a-1]=0;
    }
    printf("%.2lf\n",prim(N));
   // system("pause");
    return 0;
}
