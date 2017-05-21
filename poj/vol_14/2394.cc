#include"iostream"
#include"queue"
#include"cstdlib"
#define inf 36000000
using namespace std;
int N,P,C,M;
int map[501][501];
int dist[501];
bool used[501];
struct node{
    int index,second;
    node(int i,int s):index(i),second(s){}
};
bool operator<(const node& a,const node& b){
   return a.second>b.second;
}
priority_queue<node> myqueue;
queue<int>mq;
void dijkstra(){
    for(int i=0;i<=N;i++)dist[i]=inf;
    node temp(1,0);
    dist[1]=0;
    myqueue.push(temp);
    while(!myqueue.empty()){
       temp=myqueue.top();
       myqueue.pop();
       if(used[temp.index])continue;
       else used[temp.index]=true;
       for(int j=1;j<=N;j++){
          if(used[j])continue;
          if(dist[j]>temp.second+map[temp.index][j]){
            dist[j]=temp.second+map[temp.index][j];
            myqueue.push(node(j,dist[j]));
          }
       }
    }
}
int main(){
    int a,b,c,count=0;
    memset(used,false,sizeof(used));
    scanf("%d%d%d%d",&N,&P,&C,&M);
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            map[i][j]=inf;
        }
    }
    for(int i=0;i<P;i++){
         scanf("%d%d%d",&a,&b,&c);
         if(map[a][b]!=inf && c>=map[a][b])continue;
            map[a][b]=c;
            map[b][a]=c;
          
    }
    dijkstra();
    for(int i=1;i<=C;i++){
       scanf("%d",&a);
       if(dist[a]<=M){
          mq.push(i);
          count++;
       }
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++){
       a=mq.front();
       mq.pop();
       printf("%d\n",a);
    }
    //system("pause");
    return 0;
}
