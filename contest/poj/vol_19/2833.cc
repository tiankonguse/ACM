#include"iostream"
#include"cstdio"
#include"queue"
using namespace std;
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int> > q2;
int main(){
    int n1,n2,n,a;
    __int64 s;
    while(scanf("%d%d%d",&n1,&n2,&n)){
        if(n==0)break;
        s=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            s+=a;
            q1.push(a);
            if(i>n2)q1.pop();
            q2.push(a);
            if(i>n1)q2.pop();
        }
        while(!q1.empty()){
            s-=q1.top();
            q1.pop();
        }
        while(!q2.empty()){
            s-=q2.top();
            q2.pop();
        }
        printf("%.6f\n",(double)s/(n-n1-n2));
    }
    return 0;
}
