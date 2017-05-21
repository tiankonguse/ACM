#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#define MAXN (1<<21)
#define MAXM 105
#define MAXS 25
using namespace std;
struct node{
    int sta,t;
    node(){}
    node(int a,int b){
        sta=a,t=b;
    }
    friend bool operator>(node a,node b){
        return a.t>b.t;
    }
}tmp;
priority_queue<node,vector<node>,greater<node> >q;
int n,m;
struct product{
    int sta,sts,opa,ops,t;
}pro[MAXM];

int mark[MAXN];
char str1[MAXS],str2[MAXS];

int bfs(){
    int s,next;
    while(!q.empty())q.pop();
    memset(mark,0x3f,sizeof(mark));
    node cur((1<<n)-1,0);
    q.push(cur);
    mark[(1<<n)-1]=true;
    int res=1e9;
    while(!q.empty()){
        tmp=q.top();
        q.pop();
        s=tmp.sta;
        if(s==0){
           // return tmp.t;
            if(tmp.t<res)res=tmp.t;
            continue;
        }
        for(int i=0;i<m;i++){
          //  cout<<pro[i].sts<<endl;
          //  cout<<(s|pro[i].sts)<<endl;
            if(((s & pro[i].sta) == pro[i].sta) && ((s | pro[i].sts) == pro[i].sts)){
                next=((s|pro[i].opa) & pro[i].ops);
              //  cout<<"op="<<i<<",next="<<next<<endl;system("pause");
                if(tmp.t+pro[i].t<mark[next]){
                    mark[next]=tmp.t+pro[i].t;
                    q.push(node(next,mark[next]));
                }
            }
        }
    }
    if(res!=1e9)return res;
    else return -1;
}
int main(){
    int sta,sts,opa,ops;
    int cnt=1;
    while(scanf("%d%d",&n,&m) && n){
        for(int i=0;i<m;i++){
            scanf("%d %s %s",&pro[i].t,str1,str2);
            sta=sts=opa=ops=0;
            for(int i=0;i<n;i++){
                if(str1[i]=='0'){
                    sta = sta<<1;
                    sts = sts<<1|1;
                }
                else if(str1[i]=='-'){
                    sta = sta<<1;
                    sts = sts<<1;
                }
                else if(str1[i]=='+'){
                    sta = sta<<1|1;
                    sts = sts<<1|1;
                }
            }
            for(int i=0;i<n;i++){
                if(str2[i]=='0'){
                    opa = opa<<1;
                    ops = ops<<1|1;
                }
                else if(str2[i]=='-'){
                    opa = opa<<1;
                    ops = ops<<1;
                }
                else if(str2[i]=='+'){
                    opa = opa<<1|1;
                    ops = ops<<1|1;
                }
            }
            pro[i].sta=sta;
            pro[i].sts=sts;
            pro[i].opa=opa;
            pro[i].ops=ops;
        }
        printf("Product %d\n",cnt++);
        int res=bfs();
        if(res==-1)printf("Bugs cannot be fixed.\n\n");
        else printf("Fastest sequence takes %d seconds.\n\n",res);
    }
    return 0;
}
