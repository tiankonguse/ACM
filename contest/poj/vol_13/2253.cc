#include"iostream"
#include"cmath"
#include"queue"
#define MAXN 202
#define Distance(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int N;
int position[MAXN][2];
int dist[MAXN];
bool used[MAXN];
struct node{
    int index,dist;
    node(int i,int d):index(i),dist(d){}
};
bool operator<(const node& a,const node& b){
    return a.dist>b.dist;
}
priority_queue<node>my_queue;
//priority_queue<node,vector<node>,less<vector<node>::value_type> > my_queue;  
void solve(){
    while(!my_queue.empty())my_queue.pop();
    for(int i=1;i<N;i++)dist[i]=INT_MAX;
    memset(used,false,sizeof(used));
    node temp(0,0);
    dist[0]=0;
    my_queue.push(temp);
    while(1){
        temp=my_queue.top();
        my_queue.pop();
        if(used[temp.index])continue;
        else used[temp.index]=true;
        if(temp.index==1)return;
        for(int i=1;i<N;i++){
            if(used[i])continue;
            if(dist[i]>Max(dist[temp.index],Distance(position[temp.index][0],
            position[temp.index][1],position[i][0],position[i][1]))){
              dist[i]=Max(dist[temp.index],Distance(position[temp.index][0],
                      position[temp.index][1],position[i][0],position[i][1]));
              my_queue.push(node(i,dist[i]));
            }
        }
    }
}
int main(){
    int k=1;
    while(scanf("%d",&N) && N){
        for(int i=0;i<N;i++){
           scanf("%d%d",&position[i][0],&position[i][1]);
        }
        solve();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",k++,sqrt((double)dist[1]));
    }
    return 0;
}
