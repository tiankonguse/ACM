#include"iostream"
#include"algorithm"
using namespace std;
int cnt[101];
bool hard[101];
struct point{
    int s,id;
}p[101];
int cmp(point a,point b){
    if(a.s==b.s)return a.id<b.id;
    else return a.s<b.s;
}
int main(){
    int N,P;
    bool flag;
    scanf("%d%d",&N,&P);
    for(int i=0;i<N;i++){
       for(int j=0;j<P;j++){
          scanf("%d",&p[j].s);
          p[j].id=j;
       }
       sort(p,p+P,cmp);
       for(int j=0;j<P;j++){
          if(p[j].s>p[0].s)break;
          cnt[p[j].id]++;
       }
       for(int j=P-1;j>=0;j--){
          if(p[j].s<p[P-1].s)break;
          hard[p[j].id]=true;
       }
    }
    flag=false;
    for(int i=0;i<P;i++){
        if(!hard[i] && cnt[i]>N/2){
                    if(i==P-1)printf("%d\n");
                    else printf("%d ",i+1);
                    flag=true;
        }
    }
    if(!flag)printf("0\n");
    return 0;
}
