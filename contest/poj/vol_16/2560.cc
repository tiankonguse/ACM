#include"iostream"
#include"cmath"
#include"cstdlib"
#include"algorithm"
using namespace std;
struct Point{
   double x,y;
}points[101];
struct Edge{
   int a,b;
   double len;
}edges[5501];
int cmp(struct Edge a,struct Edge b){
    return a.len<b.len;
}
double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int parents[101];
int Find(int x){
    int a=x,tmp;
    while(parents[a]>=0)a=parents[a];
    while(parents[x]>=0 && parents[x]!=a){
       tmp=parents[x];
       parents[x]=a;
       x=tmp;
    }
    return a;
}
int Union(int a,int b){
    if(parents[a]<parents[b]){
        parents[a]+=parents[b];
        parents[b]=a;
        return -parents[a];
    }
    else{
        parents[b]+=parents[a];
        parents[a]=b;
        return -parents[b];
    }
}
int main(){
    int N,k=0,ta,tb;
    double length=0;
    scanf("%d",&N);
    memset(parents,0xff,sizeof(parents));
    for(int i=0;i<N;i++){
        scanf("%lf%lf",&points[i].x,&points[i].y);
        for(int j=0;j<i;j++){
            edges[k].a=i;
            edges[k].b=j;
            edges[k].len=dis(points[i],points[j]);
            k++;
        }
    }
    sort(edges,edges+k,cmp);
 //   for(int i=0;i<k;i++)cout<<edges[i].a<<" "<<edges[i].b<<":"<<edges[i].len<<endl;
    for(int i=0;i<k;i++){
        ta=Find(edges[i].a);
        tb=Find(edges[i].b);
        if(ta!=tb){
             length+=edges[i].len;
             int u=Union(ta,tb);
             if(u==N)break;
        }
        ta=Find(edges[i].a);
        tb=Find(edges[i].b);
    }
    printf("%.2f\n",length);
    return 0;
} 
