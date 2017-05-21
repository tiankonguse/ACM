#include"iostream"
#include"algorithm"
#include"cstdlib"
using namespace std;
struct node{
    int a,b,length;   
}con[15001];
int cmp(struct node a,struct node b){
    return a.length<b.length;
}
int parents[1001];
int Find(int x){
   int a=x,tmp;
   while(parents[a]>0)a=parents[a];
   while(parents[x]>0 && parents[x]!=a){
      tmp=parents[x];
      parents[x]=a;
      x=tmp;
   }
   return a;
}
int Union(int a,int b){
   if(parents[a]<parents[b]){
       parents[a]+=parents[b];
       parents[b]=a;
       return -parents[a];
   }
   else{
       parents[b]+=parents[a];
       parents[a]=b;
       return -parents[b];
   }
}
int main(){
    int N,M,count=0,ta,tb,i;
    scanf("%d%d%",&N,&M);
    memset(parents,0xff,(N+1)*sizeof(parents[0]));
    for(i=1;i<=M;i++){
       scanf("%d%d%d",&con[i].a,&con[i].b,&con[i].length);
    }
    sort(con+1,con+M+1,cmp);
   // for(i=1;i<=M;i++)cout<<con[i].a<<" "<<con[i].b<<" "<<con[i].length<<endl;
    for(i=1;i<=M;i++){
       ta=Find(con[i].a);
       tb=Find(con[i].b);
      // cout<<ta<<" "<<tb<<endl;
       if(ta!=tb){
            count++; 
            if(Union(ta,tb)==N)break;
       }
       else{
            con[i].a=-1;
       }
    }
    printf("%d\n%d\n",con[i].length,count);
    for(int j=1;j<=i;j++){
       if(con[j].a!=-1)printf("%d %d\n",con[j].a,con[j].b);
    }
 //   system("pause");
    return 0;
}
