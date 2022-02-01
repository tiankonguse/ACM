#include"iostream"
#define Dis(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
using namespace std;
int parents[1005];
double pos[1005][2];
double dist[1005][1005];
bool used[1005];
int Find(int x){
    int a=x,temp;
    while(parents[a]>0)a=parents[a];
    while(parents[x]>0 && parents[x]!=a){
        temp=parents[x];
        parents[x]=a;
        x=temp;
    }
    return a;
}
void Union(int a,int b){
    if(parents[a]<parents[b]){
        parents[a]+=parents[b];
        parents[b]=a;    
    }
    else{
        parents[b]+=parents[a];
        parents[a]=b;
    }
}
int main(){
    int N,a,b,ta,tb;
    double d;
    char c;
    memset(used,false,sizeof(used));
    memset(parents,-1,sizeof(used));
    scanf("%d%lf",&N,&d);
    d=d*d;
    for(int i=1;i<=N;i++){
        scanf("%lf%lf",&pos[i][0],&pos[i][1]);
    }
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            dist[i][j]=Dis(pos[i][0],pos[i][1],pos[j][0],pos[j][1]);
            dist[j][i]=dist[i][j];
        }
    }
    while(scanf(" %c",&c)!=EOF){
        if(c=='O'){
            scanf("%d",&a);
            used[a]=true;
            for(int i=1;i<=N;i++){
                if(i!=a && used[i] && dist[i][a]<=d){
                   ta=Find(a);
                   tb=Find(i);
                   if(ta!=tb)Union(ta,tb);
                }
            }
        }
        else {
            scanf("%d%d",&a,&b);
            if(Find(a)==Find(b))
            printf("SUCCESS\n");
            else 
            printf("FAIL\n");
        }
    }
    return 0;
}
