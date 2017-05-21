#include"iostream"
#define MAXN 700
#define MAXM 100005
#define WORD_LEN 1005
#define inf 0x3f3f3f3f
using namespace std;
struct edges{
    int u,c,next;
}e[MAXM];
int N,M,idx;
int p[MAXN],dist[MAXN],cnt[MAXN];
int st[MAXM];
bool used[MAXN];
void init(){
    idx=0;
    memset(p,0xff,sizeof(p));
}
void addedge(int u,int v,int c){
    e[idx].u=v;
    e[idx].c=c;
    e[idx].next=p[u];
    p[u]=idx++;
}
bool spfa(int s){
    int t,u,w;
    int l=0;
    memset(used,false,sizeof(used));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<700;i++)dist[i]=inf;
    //cnt[s]=1;
    dist[s]=0;
    st[l++]=s;
    while(l){
        t=st[--l];
        used[t]=false;
        for(int i=p[t];i!=-1;i=e[i].next){
            u=e[i].u;
            w=e[i].c;
            if(dist[t]+w<dist[u]){
               // printf("dist[%d]+%d<dist[%d]\n",t,w,u);
                dist[u]=dist[t]+w;
                if(!used[u]){
                    used[u]=true;
                    cnt[u]++;
                //    cout<<"cnt["<<u<<"]++"<<endl;
                    if(cnt[u]>N)return true;
                    st[l++]=u;
                }
            }
        }
    }
    return false;
}
struct ee{
    int u,v,c;
    char str[WORD_LEN];
}edge[MAXM];
bool hash[700];
int main(){
    int len,l,h,mid;
    while(scanf("%d",&M)&&M){
        l=inf;
        h=0;
        N=0;
        memset(hash,false,sizeof(hash));
        for(int i=0;i<M;i++){
            scanf("%s",&edge[i].str);
            len=strlen(edge[i].str);
            edge[i].c=len*1000;
            if(edge[i].c>h)h=edge[i].c;
            if(edge[i].c<l)l=edge[i].c;
            edge[i].u=(edge[i].str[0]-'a')*26+(edge[i].str[1]-'a')+1;
            edge[i].v=(edge[i].str[len-2]-'a')*26+(edge[i].str[len-1]-'a')+1;
            if(!hash[edge[i].u]){hash[edge[i].u]=true;N++;}
            if(!hash[edge[i].v]){hash[edge[i].v]=true;N++;}
        }
        //for(int i=0;i<M;i++)printf("%s %d %d\n",edge[i].str,edge[i].u,edge[i].v);
        int res=-1;
       // cout<<l<<","<<h<<endl;
        while(l<=h){
            mid=(l+h)>>1;
            init();
          //  printf("mid=%d\n",mid);
            memset(hash,false,sizeof(hash));
            for(int i=0;i<M;i++){
                addedge(edge[i].u,edge[i].v,-edge[i].c+mid);
                if(!hash[edge[i].u]){
                    hash[edge[i].u]=true;
                    addedge(0,edge[i].u,0);
                  //  printf("add(%d,%d)=%d\n",0,edge[i].u,0);
                }
                if(!hash[edge[i].v]){
                    hash[edge[i].v]=true;
                    addedge(0,edge[i].v,0);
                 //   printf("add(%d,%d)=%d\n",0,edge[i].v,0);
                }
             //   printf("add(%d,%d)=%d\n",edge[i].u,edge[i].v,-edge[i].c+mid);
            }
            if(spfa(0)){
              //  printf("yes\n");
                res=mid;
                l=mid+1;
            }
            else{
              //  printf("no\n");
                h=mid-1;
            }
        }
        if(res==-1)printf("No solution.\n");
        else {
            double r=1.0*res/1000.0;
            printf("%.2lf\n",r);
        }
    }
    return 0;
}
