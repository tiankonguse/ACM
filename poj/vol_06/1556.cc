#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <queue>
#define MAXN 1010
#define MAXM 100100
#define inf 1e15
#define eps 1e-4
#define x real()
#define y imag()
using namespace std;
typedef complex<double> Point;
double cross(Point a,Point b){return imag(conj(a)*b);}
double dmul(Point a,Point b){return real(conj(a)*b);}
double sgn(double a){return (a>eps) - (a<-eps);}
double dis(Point a,Point b){return hypot(a.x-b.x,a.y-b.y);}
bool crosspoint(Point p1,Point p2,Point q1,Point q2){
    double a=cross(p2-p1,q2-q1),b=cross(p2-p1,p2-q1);
    double c=cross(q2-q1,p2-p1),d=cross(q2-q1,q2-p1);
    if(a==0){return b!=0? 0: (sgn(dmul(q1-p1,q1-p2))<=0 || sgn(dmul(q2-p1,q2-p2)<=0));}
    else return (sgn(b/a)>=0 && sgn(b/a-1)<=0 && sgn(d/c)>=0 && sgn(d/c-1)<=0);
}


struct edges{
    int u,next;
    double c;
}e[MAXM];
int p[MAXN],idx;
void addedge(int u,int v,double c){
    e[idx].u=v;
    e[idx].c=c;
    e[idx].next=p[u];
    p[u]=idx++;
}
void init(){
    idx=0;
    memset(p,0xff,sizeof(p));
}
double dist[MAXN];
bool used[MAXN];
queue<int>q;
void spfa(int s,int N){
    int t,u;
    double w;
    while(!q.empty())q.pop();
    memset(used,false,sizeof(used));
    for(int i=0;i<N;i++)dist[i]=inf;
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        t=q.front();
        q.pop();
        used[t]=false;
        for(int i=p[t];i!=-1;i=e[i].next){
            u=e[i].u;
            w=e[i].c;
            if(dist[t]+w<dist[u]){
                dist[u]=dist[t]+w;
                if(!used[u]){
                    used[u]=true;
                    q.push(u);
                }
            }
        }
    }
}
int main(){
    int num;
    double px,py;
    Point p[MAXN];
    while(scanf("%d",&num)&& num!=-1){
        p[0]=Point(0,5);
        int cnt=1;
        for(int i=0;i<num;i++){
            scanf("%lf",&px);
            for(int j=0;j<4;j++){
                scanf("%lf",&py);
                p[cnt++]=Point(px,py);
            }
        }
        p[cnt++]=Point(10,5);

        init();
        for(int i=0;i<num;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<1+i*4;k++){
                    int d=1+i*4+j;
                    bool flag=true;
                    for(int l=(k==0?0:(k-1)/4+1);l<i;l++){
                        int d2=1+l*4;
                       // cout<<p[k].x<<","<<p[k].y<<"->"<<p[d].x<<","<<p[d].y<<endl;
                        if(crosspoint(p[d],p[k],Point(p[d2].x,0),p[d2]) ||
                           crosspoint(p[d],p[k],p[d2+1],p[d2+2]) ||
                           crosspoint(p[d],p[k],p[d2+3],Point(p[d2].x,10))){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        addedge(k,d,dis(p[k],p[d]));
                    //    cout<<"add("<<k<<","<<d<<")"<<dis(p[k],p[d])<<" \n";
                    }
                }
            }
        }
        for(int k=0;k<cnt-1;k++){
                    int d=cnt-1;
                    bool flag=true;
                    for(int l=(k==0?0:(k-1)/4+1);l<num;l++){
                        int d2=1+l*4;
                        if(crosspoint(p[d],p[k],Point(p[d2].x,0),p[d2]) ||
                           crosspoint(p[d],p[k],p[d2+1],p[d2+2]) ||
                           crosspoint(p[d],p[k],p[d2+3],Point(p[d2].x,10))){
                            flag=false;
                            break;
                        }
                    }
                     if(flag){
                        addedge(k,d,dis(p[k],p[d]));
                   //    cout<<"add("<<k<<","<<d<<")"<<dis(p[k],p[d])<<" \n";
                    }
        }

        spfa(0,cnt);
       // for(int i=0;i<cnt;i++)cout<<dist[i]<<endl;
        printf("%.2f\n",dist[cnt-1]);
    }
    return 0;
}
