#include"iostream"
#include"queue"
#include"cmath"
#include"cstdio"
using namespace std;
priority_queue<double>q;
int main(){
    int N;
    double a,b,c;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lf",&a);
        q.push(a);
    }
    for(int i=1;i<N;i++){
        a=q.top();q.pop();
        b=q.top();q.pop();
        a=2.0*sqrt(a*b);
        q.push(a);
    }
    printf("%.3lf\n",a);
  //  system("pause");
    return 0;
}
