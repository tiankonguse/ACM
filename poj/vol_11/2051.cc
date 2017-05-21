#include"iostream"
#include"queue"
#include"algorithm"
using namespace std;
struct ar{
    int id,p,op;
   bool operator <(const ar &a) const
   {
      if(a.p==p)return id>a.id;
      else return p>a.p;
   }
}a,t;
priority_queue<ar>q;
char str[10];
int main(){
    int k;
    while(scanf("%s",str)){
       if(str[0]=='#'){
          scanf("%d",&k);
          while(k--){
              t=q.top();
              q.pop();
              printf("%d\n",t.id);     
              t.p+=t.op;
              q.push(t);
          }
          break;
       }
       scanf("%d%d",&a.id,&a.op);
       a.p=a.op;
       q.push(a);
    }
   // system("pause");
    return 0;
}
