#include"iostream"
#include"cmath"
using namespace std;
int sum(int a){
    int s=0;
    while(a){
        s+=a%10;
        a/=10;
    }
    return s;
}
int main(){
    int N,t,tm,s1,s2;
    while(scanf("%d",&N)&&N){
        for(int i=N+1;;i++){
            s1=sum(i);
            s2=0;
            t=i;
            tm=(int)sqrt(t*1.0);
            for(int j=2;j<=tm;j++){
                while(t%j==0){
                    t/=j;
                    s2+=sum(j);
                    tm=(int)sqrt(t*1.0);
                }
            }
            if(t==i)continue;
            if(t!=1)s2+=sum(t);
            if(s1==s2){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
