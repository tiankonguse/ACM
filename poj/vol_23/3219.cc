#include"iostream"
using namespace std;
int dat[32];
int cnt(int n){
     int s=0;
     while(n){
       s+=n/2;
       n/=2;        
     }
     return s;
}
int main(){
    int n,k,e;
    while(~scanf("%d%d",&n,&k)){
        e=cnt(n)-cnt(k)-cnt(n-k);
        if(e>0)printf("0\n");
        else printf("1\n");
    }
    return 0;
}
