#include"iostream"
#include"stack"
#include"cstdlib"
#include"cstdio"
using namespace std;
struct rec{
       __int64 h,l,id;
      // rec(__int64 h,__int64 l,__int64 id):h(h),l(l),id(id){}
}t,st[100001];
__int64 max(__int64 a,__int64 b){
    return a>b?a:b;
}
int main(){
    __int64 N,a,ans,left,right,p;
    rec tmp;
    scanf("%I64d",&N);
        left=right=1;
        //while(!st.empty())st.pop();
        p=-1;
        ans=0;
        tmp.h=-1;tmp.l=1;tmp.id=0;
        st[++p]=tmp;
        for(__int64 i=0;i<=N;i++){
          if(i!=N)scanf("%I64d",&a);
          else a=0;
          if(a>=st[p].h){
             tmp.h=tmp.l=a;
             tmp.id=i+1;
             st[++p]=tmp;
          }
          else{
             __int64 len=0;
             t=st[p];
             while(t.h>=a){
                len+=t.l;
                if(ans<len*t.h){
                    left=t.id;
                    right=i;
                    ans=len*t.h;
                }
                p--;
                if(st[p].h<a)break;
                t=st[p];
             }
             tmp.h=a;
             tmp.l=len+a;
             tmp.id=t.id;
             st[++p]=tmp;
          }
        }
        printf("%I64d\n%I64d %I64d\n",ans,left,right);
    
    return 0;
}
