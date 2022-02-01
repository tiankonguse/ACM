#include"iostream"
#define MAXN 5005
using namespace std;
int parti[MAXN][2];
int cnt[MAXN];
bool cross(int x1,int y1,int x2,int y2){
    return x1*y2>x2*y1;
}
int main(){
    int N,M,x1,y1,x2,y2,x,y,z=0;
    while(scanf("%d",&N)&&N){
        if(z)printf("\n");
        z=1;
        scanf("%d%d%d%d%d",&M,&x1,&y1,&x2,&y2);
        for(int i=0;i<N;i++){
            scanf("%d%d",&parti[i][0],&parti[i][1]);
        }
        memset(cnt,0,sizeof(cnt));
        int l=0,h=N-1,mid;
        for(int i=0;i<M;i++){
            scanf("%d%d",&x,&y);
       //     if(x<=x1 || x>=x2 || y>=y1 || y<=y2)continue;
            l=0,h=N-1;
            while(l<=h){
                mid=(l+h)>>1;
                if(cross(x-parti[mid][1],y-y2,parti[mid][0]-parti[mid][1],y1-y2)){
                    l=mid+1;
                }
                else h=mid-1;
            }
            cnt[l]++;
        }
        for(int i=0;i<=N;i++){
            printf("%d: %d\n",i,cnt[i]);
        }
    }
    return 0;
}
