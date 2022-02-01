#include"iostream"
using namespace std;
int main(){
    int N,r;
    double v,t,tt;
    while(scanf("%d",&N)&&N){
        int min=INT_MAX;
        for(int i=0;i<N;i++){
            scanf("%lf%lf",&v,&t);
            if(t>=0){
               tt=16200.0/v;
               if(tt>(int)tt)tt++;
               r=(int)(tt+t);
               if(r<min)min=r;
            }
        }
        printf("%d\n",min);
    }
    return 0;
}
