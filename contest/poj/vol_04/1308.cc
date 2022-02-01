#include"iostream"
#define MAXN 5005
using namespace std;
int parents[MAXN];
bool used[MAXN];
int find(int a){
    if(parents[a]>0){
        parents[a]=find(parents[a]);
        return parents[a];
    }
    else return a;
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
void init(){
    memset(parents,0xff,sizeof(parents));
    memset(used,false,sizeof(used));
}
int main(){
    int a,b,ra,rb,num=0,d=0;
    int cnt=1;
    bool flag=true;
    init();
    while(scanf("%d%d",&a,&b)){
        if(a==-1)break;
        else if(a==0 && b==0){
            if(flag && d==num)printf("Case %d is a tree.\n",cnt++);
            else printf("Case %d is not a tree.\n",cnt++);
            init();
            d=num=0;
            flag=true;
            continue;
        }
        else if(flag){
            ra=find(a);
            rb=find(b);
         //   printf("%d %d\n",ra,rb);
            if(ra==rb)flag=false;
            else d=Union(ra,rb);
         //   printf("d=%d\n",d);
          //  printf("num=%d\n",num);
        }
        if(!used[a]){used[a]=true;num++;}
        if(!used[b]){used[b]=true;num++;}
    }
    return 0;
}
