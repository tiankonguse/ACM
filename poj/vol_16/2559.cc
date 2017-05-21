#include"iostream"
#include"stack"
#define typec __int64
using namespace std;
struct rec{
       typec h,l;
       rec(typec h,typec l):h(h),l(l){}
}t(0,0);
typec max(typec a,typec b){
   return a>b?a:b;
}
stack<rec>st;
int main(){
    int N;
    typec a,ans;
    while(scanf("%d",&N)&&N){
        while(!st.empty())st.pop();
        ans=0;
        st.push(rec(-1,1));
        for(int i=0;i<=N;i++){
            if(i==N)a=0;
            else scanf("%I64d",&a);
            if(a>=st.top().h)st.push(rec(a,1));
            else{
                int len=0;
                t=st.top();
                while(t.h>=a){
                   len+=t.l;
                   ans=max(ans,len*t.h);
                   st.pop();
                   t=st.top();
                }
                st.push(rec(a,len+1));
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
