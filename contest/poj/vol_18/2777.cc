#include"iostream"
#define MAXN 100001
using namespace std;
int tree[MAXN*3];
bool tcov[MAXN*3];
int countbit(int a){
   int num=0;
   while(a){
       a&=(a-1);
       num++;
   }
   return num;
}
void create(int l,int r,int p){
    tree[p]=1;
    if(l==r)return;
    int mid=(l+r)>>1;
    create(l,mid,2*p);
    create(mid+1,r,2*p+1);
}
int update(int a,int b,int c,int l,int r,int p){
   if(a==l && b==r){
       tcov[p]=true;
       tree[p]=c;
       return c;
   }
   if(tcov[p]){
      tree[2*p]=tree[p];
      tree[2*p+1]=tree[p];
      tcov[2*p]=true;
      tcov[2*p+1]=true;
      tcov[p]=false;
   }
   int mid=(l+r)>>1;
   if(b<=mid)tree[p]=update(a,b,c,l,mid,2*p)|tree[2*p+1];
   else if(a>mid)tree[p]=update(a,b,c,mid+1,r,2*p+1)|tree[2*p];
   else tree[p]=update(a,mid,c,l,mid,2*p)|update(mid+1,b,c,mid+1,r,2*p+1);
   return tree[p];
}
int query(int a,int b,int l,int r,int p){
   if(a==l && b==r){
        return tree[p];
   }
   int mid=(l+r)>>1;
   if(tcov[p]){
      tree[2*p]=tree[p];
      tree[2*p+1]=tree[p];
      tcov[2*p]=true;
      tcov[2*p+1]=true;
      tcov[p]=false;
   }
   if(b<=mid)return query(a,b,l,mid,2*p);
   else if(a>mid)return query(a,b,mid+1,r,2*p+1);
   else return query(a,mid,l,mid,2*p) | query(mid+1,b,mid+1,r,2*p+1);
}
int main(){
    int N,T,O,a,b,c,t;
    char ch;
    while(scanf("%d%d%d",&N,&T,&O)!=EOF){
         memset(tree,0,sizeof(tree));
         memset(tcov,false,sizeof(tcov));
         tree[1]=1;
         tcov[1]=true;
        //create(1,N,1);
       //  for(int i=1;i<=10;i++)cout<<tree[i]<<endl;
         while(O--){
             scanf(" %c",&ch);
             if(ch=='C'){
                scanf("%d%d%d",&a,&b,&c);
                if(a>b){t=a;a=b;b=t;}
                c=(1<<(c-1));
                update(a,b,c,1,N,1);
              //  for(int i=1;i<=10;i++)cout<<tree[i]<<endl;
             }
             else{
                scanf("%d%d",&a,&b);
                if(a>b){t=a;a=b;b=t;}
                printf("%d\n",countbit(query(a,b,1,N,1)));
             }
         }
    }
    return 0;
}
