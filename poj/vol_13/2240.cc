#include"iostream"
#include"cstdlib"
using namespace std;
int N,M;
char names[30][30];
struct node{
     int start,end;
     double rate;       
}edges[1000];
double rates[31];
int cmp(const void* a,const void* b){
   return strcmp((char *)a,(char *)b);
}
int find(char *a){
    int left=0,right=N-1,mid;
    while(left<=right){
        mid=(left+right)/2;
        if(strcmp(a,names[mid])==0)return mid;
        else if(strcmp(a,names[mid])<0)right=mid-1;
        else left=mid+1;
    }
}
bool solve(){
   memset(rates,0,sizeof(rates));
   rates[N]=1;
   for(int i=N;i>0;i--){
       for(int j=M+N-1;j>=0;j--){
          if(rates[edges[j].start]!=0){
             if(rates[edges[j].start]*edges[j].rate>rates[edges[j].end])
             rates[edges[j].end]=rates[edges[j].start]*edges[j].rate;
          }
       }
   }
   for(int i=0;i<M+N;i++){
      if(rates[edges[i].start]*edges[i].rate>rates[edges[i].end])
      return true;
   }
   return false;
}
int main(){
    char first[30],second[30];
    double rat;
    bool flag;
    int ca=1;
    while(scanf("%d",&N) && N){
        for(int i=0;i<N;i++)scanf("%s",names[i]);
        qsort(names,N,sizeof(names[0]),cmp);
        scanf("%d",&M);
        for(int i=0;i<M;i++){
           scanf("%s%lf%s",first,&rat,second);
           edges[i].start=find(first);
           edges[i].end=find(second);
           edges[i].rate=rat;
        }
        for(int i=M;i<M+N;i++){
           edges[i].start=N;
           edges[i].end=i-M;
           edges[i].rate=1;
        }
        printf("Case %d: ",ca++);
        if(solve())printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
