#include"iostream"
#include"algorithm"
using namespace std;
struct node{
   int idx,f,s;
}cows[50001];
int cmp1(node a,node b){
    return a.f>b.f;
}
int cmp2(node a,node b){
    return a.s>b.s;
}
int main(){
    int N,K,v1,v2;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%d%d",&v1,&v2);
        cows[i].idx=i;
        cows[i].f=v1;
        cows[i].s=v2;
    }
    sort(cows,cows+N,cmp1);
    sort(cows,cows+K,cmp2);
    printf("%d\n",cows[0].idx+1);
    //system("pause");
    return 0;
}
