#include"iostream"
#include"algorithm"
#define MAXN 1005
using namespace std;
struct edge{
    int y1,y2;
    friend bool operator<(edge a,edge b){
        return a.y1==b.y1?a.y2<b.y2:a.y1<b.y1;
    }
}parti[MAXN];
int cnt[MAXN],res[MAXN];
bool cross(int x1,int y1,int x2,int y2){
    return x1*y2>=x2*y1;
}
int main(){
    int N,M,x1,y1,x2,y2,x,y;
    while(scanf("%d",&N)&&N){
        scanf("%d%d%d%d%d",&M,&x1,&y1,&x2,&y2);
        for(int i=0;i<N;i++){
            scanf("%d%d",&parti[i].y1,&parti[i].y2);
        }
        sort(parti,parti+N);
        memset(cnt,0,sizeof(cnt));
        memset(res,0,sizeof(res));
        int l=0,h=N-1,mid;
        for(int i=0;i<M;i++){
            scanf("%d%d",&x,&y);
       //     if(x<=x1 || x>=x2 || y>=y1 || y<=y2)continue;
            l=0,h=N-1;
            while(l<=h){
                mid=(l+h)>>1;
                if(cross(x-parti[mid].y2,y-y2,parti[mid].y1-parti[mid].y2,y1-y2)){
                    l=mid+1;
                }
                else h=mid-1;
            }
            cnt[l]++;
        }
        for(int i=0;i<=N;i++){
            if(cnt[i])res[cnt[i]]++;
        }
        printf("Box\n");
        for(int i=1;i<=M;i++){
            if(res[i])printf("%d: %d\n",i,res[i]);
        }
    }
    return 0;
}
