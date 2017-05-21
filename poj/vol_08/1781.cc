#include"iostream"
using namespace std;
int fun(int n){
    if(n==1)return 1;
    else if(n&1){
        return 2*fun(n/2)+1;
    }
    else return 2*fun(n/2)-1;
}
int main(){
    float a;
    int s;
    while(~scanf("%f",&a)){
       if(a==0)break;
       s=(int)a;
       printf("%d\n",fun(s));
    }
    return 0;
}
