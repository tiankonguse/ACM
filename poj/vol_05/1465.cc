#include"iostream"
#include"queue"
#include"cstdlib"
#include"string"
#include"algorithm"
using namespace std;
struct node{
   int n;
   string s;
   node(int i,string s0):n(i),s(s0){}
};
int N,m,dg[11];
bool used[5001];
queue<node>myqueue;
void BFS(){
   int t;
   memset(used,false,sizeof(used));
   while(!myqueue.empty())myqueue.pop();
   node cur(0,""),cur2(0,"");
   myqueue.push(cur);
   while(!myqueue.empty()){
     cur=myqueue.front();
     myqueue.pop();
     for(int i=0;i<m;i++){
        t=cur.n*10+dg[i];
        //cout<<t<<endl;
        if(t==0)continue;
        t%=N;
        if(!used[t]){
            used[t]=true;
            if(t==0){
              //  for(int k=0;k<cur.s.length();k++)printf("%c",cur.s[k]);
                cout<<cur.s<<dg[i]<<endl;
              //  printf("%d\n",dg[i]);
                return;
            }
            cur2.n=t;
            cur2.s=cur.s+(char)(dg[i]+'0');
            myqueue.push(cur2);
        }
     }
   }
   printf("0\n");
}
int main(){
    while(scanf("%d",&N)!=EOF){
        scanf("%d",&m);
        for(int i=0;i<m;i++){
           scanf("%d",&dg[i]);
        }       
        if(N==0)cout<<0<<endl;
        else{
         sort(dg,dg+m);
         BFS();
        }
    }
    return 0;
}
