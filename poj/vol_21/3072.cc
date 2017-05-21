#include"iostream"
#include"cstdlib"
#include"queue"
#include"cmath"
#define MAXN 21
#define MAXE 500
using namespace std;
const double pi=acos(-1.0);
struct edges{
   int u,next;
   double d;
}e[MAXE];
struct points{
   double x,y;
}ps[MAXN];
double dir[MAXN];
int N;
double R;
double dist[MAXN];
int p[MAXN];
bool used[MAXN];
queue<int>q;
double dis(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double deg(int a,int b,double &dire){
    dire=atan2(ps[b].y-ps[a].y,ps[b].x-ps[a].x)*180.0/pi;
    double d=fabs(dire-dir[a]);
    if(d>180)d=360-d;
    return d;
}
void spfa(int s){
   int t,u;
   double d,dire,de;
   while(!q.empty())q.pop();
   for(int i=0;i<N;i++)dist[i]=1e11;
   memset(used,false,sizeof(used));
   dist[s]=0;
   q.push(s);
   while(!q.empty()){
       t=q.front();
       q.pop();
       used[t]=false;
       for(int i=p[t];i!=-1;i=e[i].next){
           u=e[i].u;
           d=e[i].d;
           de=deg(t,u,dire);
           if(dist[t]+d+de<dist[u]){
              dist[u]=dist[t]+d+de;
              dir[u]=dire;
              if(!used[u]){
                 used[u]=true;
                 q.push(u);
              }
           }
       }
   }
}

int main(){
    //freopen("robot.in","r",stdin);
    //freopen("testrobot.txt","w",stdout);
    int idx;
    double x,y,di,dire;
    while(scanf("%lf%d",&R,&N)){
        if(N==-1)break;
        memset(p,0xff,sizeof(p));
        for(int i=0;i<N;i++)scanf("%lf%lf",&ps[i].x,&ps[i].y);
        deg(0,N-1,dire);
        dir[0]=dire;
        idx=0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                di=dis(ps[i].x,ps[i].y,ps[j].x,ps[j].y);    
                if(di<=R){
                     e[idx].u=j;
                     e[idx].d=di;
                     e[idx].next=p[i];
                     p[i]=idx++;
                     e[idx].u=i;
                     e[idx].d=di;
                     e[idx].next=p[j];
                     p[j]=idx++;
                }
            }
        }
        spfa(0);
        if(dist[N-1]==1e11)printf("impossible\n");
        else printf("%d\n",(int)(dist[N-1]+0.5));
    }
    return 0;
}
