#include"iostream"
#include"cstdlib"
using namespace std;
struct node{
       int s,e;
       double r,c;
}edges[205];
double value[105];
int N,M,S;
double V;
bool solve(){
   memset(value,0,sizeof(value));
   value[S]=V;
   int flag;
   for(int i=0;i<N;i++){
      flag=1;
      for(int j=0;j<2*M;j++){
         if(value[edges[j].s]>0){
            if((value[edges[j].s]-edges[j].c)*edges[j].r>value[edges[j].e]){
               value[edges[j].e]=(value[edges[j].s]-edges[j].c)*edges[j].r;
               flag=0;
            }
         }
      }
      if(flag)break;
   }
   for(int j=0;j<2*M;j++){
         if((value[edges[j].s]-edges[j].c)*edges[j].r>value[edges[j].e])return true;
   }
   if(value[S]>V)return true;
   else return false;
}
/*
int solve()  
{  
    memset(value,0,sizeof(value));  
    value[S]=V;  
    for(int i=0;i<N;i++)  
    {  
        for(int j=0;j<2*M;j++)  
        {  
            if(value[edges[j].s]>0)  
            {  
                if((value[edges[j].s]-edges[j].c)*edges[j].r>value[edges[j].e])  
                    value[edges[j].e]=(value[edges[j].s]-edges[j].c)*edges[j].r;  
            }  
        }  
    }  
    for(int j=0;j<2*M;j++)  
    {  
        if((value[edges[j].s]-edges[j].c)*edges[j].r>value[edges[j].e]) return true;  
    }  
    if(value[S]>V) return true;  
    else return false;  
}  */
int main(){
    int a,b;
    double r1,c1,r2,c2;
    scanf("%d%d%d%lf",&N,&M,&S,&V);
    for(int i=0;i<M;i++){
       scanf("%d%d%lf%lf%lf%lf",&a,&b,&r1,&c1,&r2,&c2);
       edges[2*i].s=edges[2*i+1].e=a;
       edges[2*i].e=edges[2*i+1].s=b;
       edges[2*i].r=r1;
       edges[2*i].c=c1;
       edges[2*i+1].r=r2;
       edges[2*i+1].c=c2;
    }
    if(solve())printf("YES\n");
    else printf("NO\n");
    return 0;
}
