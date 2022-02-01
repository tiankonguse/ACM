#include"iostream"
#include"cmath"
#include"algorithm"
#define MAXN 501
using namespace std;
double map[MAXN][MAXN];
bool inTree[MAXN];   
double min_length[MAXN];     
double prim(int n)   
{   
    double sum_length=0;
    memset(inTree,false,sizeof(inTree));
    for(int i=1;i<n;i++)min_length[i]=1e15;
    min_length[0]=0;
    for(int i=0;i<n;i++){
        int min_index=-1;
        for(int j=0;j<n;j++){
          if(!inTree[j]&&(min_index==-1 || min_length[j]<min_length[min_index])){
             min_index=j;
          }
        }
        inTree[min_index]=true;
        sum_length+=min_length[min_index];
        for(int j=0;j<n;j++){
           if(!inTree[j] && map[j][min_index]<min_length[j]){
                 min_length[j]=map[j][min_index];
           }
        }
    }
    return sum_length;
}
double dist(double x1,double y1,double x2,double y2){
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double coor[MAXN][2];
int main(){
    int T,S,P;
    scanf("%d",&T);
    while(T--){
         scanf("%d%d",&S,&P);
         for(int i=0;i<P;i++)scanf("%lf%lf",&coor[i][0],&coor[i][1]);
         for(int i=0;i<P;i++){
             for(int j=i;j<P;j++){
                  map[i][j]=map[j][i]=dist(coor[i][0],coor[i][1],coor[j][0],coor[j][1]); 
             }
         }
         prim(P);
         sort(min_length,min_length+P);
         printf("%.2lf\n",min_length[P-S]);
    }
    return 0;
}
