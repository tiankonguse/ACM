#include"iostream"
using namespace std;
int fun(int n,int s,int r){
    int res=0;
    for(int i=2;i<=n;i++){
        res=(res+s)%i;
    }
    res=(res+1+r)%(n+1);
    if(res==0)return n+1;
    else return res;
}
int main(){
    int n,k,m;
    while(scanf("%d%d%d",&n,&k,&m)){
        if(n==0 && k==0 && m==0)break;
        printf("%d\n",fun(n-1,k,m));    
    }
    return 0;
}
