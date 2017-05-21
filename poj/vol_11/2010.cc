#include"iostream"
#include"cstdlib"
#include"algorithm"
#include"queue"
#define MAXN 100001
using namespace std;
priority_queue<int>myq1,myq2;
struct node{
       int s,f;
}cow[MAXN];
int cmp1(node a,node b){return a.s>b.s;}
int dp1[MAXN],dp2[MAXN];
int main(){
    int N,C,F;
    scanf("%d%d%d",&N,&C,&F);
    for(int i=0;i<C;i++){
       scanf("%d%d",&cow[i].s,&cow[i].f);
    }
    sort(cow,cow+C,cmp1);
    int sum1=0,sum2=0;
    int nu=N/2;
    for(int i=0;i<nu;i++){
       sum1+=cow[i].f;
       myq1.push(cow[i].f);
    }
    dp1[nu-1]=sum1;
    int tmp;
    for(int i=nu;i<C-nu;i++){
        tmp=myq1.top();
        if(cow[i].f<tmp){
          myq1.pop();
          myq1.push(cow[i].f);
          sum1=sum1-tmp+cow[i].f;
        }
        dp1[i]=sum1;
    }
    for(int i=C-1;i>=C-nu;i--){
       sum2+=cow[i].f;
       myq2.push(cow[i].f);
    }
    dp2[C-nu]=sum2;
    for(int i=C-nu-1;i>=nu;i--){
       tmp=myq2.top();
        if(cow[i].f<tmp){
          myq2.pop();
          myq2.push(cow[i].f);
          sum2=sum2-tmp+cow[i].f;
        }
        dp2[i]=sum2;
    }
    bool flag=true;
    for(int i=nu;i<C-nu;i++){
       if(dp1[i-1]+cow[i].f+dp2[i+1]<=F){
         printf("%d\n",cow[i].s);
         flag=false;
         break;
       }
    }
    if(flag)printf("-1\n");
    return 0;
}

