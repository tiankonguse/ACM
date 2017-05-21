#include"iostream"
#include"string.h"
#include"cstdio"
#define inf 0x3f3f3f3f
using namespace std;
bool used[1001][1001];
int dist[1001][1001];
int N,NX,NY,sx,sy,dx,dy;
struct node{
    int x,y,t;
}q[1000000],tmp,tem;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int ab(int a){
    return a>0?a:-a;
}
int dis(int x1,int y1,int x2,int y2){
     return ab(x1-x2)+ab(y1-y2);
}
int init(){
     int l=0,h,tx,ty,max=0;
     memset(used,false,sizeof(used));
     for(h=0;h<N;h++){
        scanf("%d%d",&q[h].x,&q[h].y);
        q[h].t=0;
        used[q[h].x][q[h].y]=true;
        dist[q[h].x][q[h].y]=0;
     }
     while(l<h){
        tmp=q[l++];
        for(int i=0;i<4;i++){
            tx=tmp.x+dir[i][0];
            ty=tmp.y+dir[i][1];
            if(!used[tx][ty] && tx>=0 && tx<NX && ty>=0 && ty<NY){
                 used[tx][ty]=true;
                 dist[tx][ty]=tmp.t+1;
                 tem.x=tx;
                 tem.y=ty;
                 tem.t=tmp.t+1;
                 q[h++]=tem;
                 if(tem.t>max)max=tem.t;
            }
        }
     }
    return max;
}
int bfs(int d){
    if(dist[sx][sy]<d)return -1;
    int l=0,h=1,tx,ty;
    q[0].x=sx;
    q[0].y=sy;
    q[0].t=0;
  /*  for(int i=0;i<NX;i++){
       for(int j=0;j<NY;j++){
          used[i][j]=false;
       }
    }*/
    memset(used,false,sizeof(used));
    used[sx][sy]=true;
    while(l<h){
        tmp=q[l++];
        for(int i=0;i<4;i++){
            tx=tmp.x+dir[i][0];
            ty=tmp.y+dir[i][1];
            if(dist[tx][ty]>=d){ 
              if(tx==dx && ty==dy)return tmp.t+1;
              if(!used[tx][ty] && tx>=0 && tx<NX && ty>=0 && ty<NY){
                 used[tx][ty]=true;
                 tem.x=tx;
                 tem.y=ty;
                 tem.t=tmp.t+1;
                 q[h++]=tem;
              }
            }
        }
    }
    return -1;
}
int main(){
    int T,l,h,mid,r,res,rd;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&N,&NX,&NY);
        scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
    
        h=init();
        l=0;
        res=rd=0;
        
        while(l<=h){
            mid=(l+h)>>1;
            r=bfs(mid);
            //cout<<"mid="<<mid<<",r="<<r<<endl;
            if(r!=-1){
               res=mid;
               rd=r;
               l=mid+1;
            }
            else{
               h=mid-1;
            }
        }
        printf("%d %d\n",res,rd);
    }
   // system("pause");
    return 0;
}

