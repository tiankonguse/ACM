#include"iostream"
using namespace std;
int main(){
    int T,a,b,l,r;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d%d",&a,&b);
        l=r=0;
        while(a!=1 && b!=1){
            if(a>b){
                l+=a/b;   
                a=a%b;
            }
            else{
                r+=b/a;
                b=b%a;
            }
        }
        if(a>b)l+=a-1;
        else r+=b-1;
        printf("Scenario #%d:\n%d %d\n\n",i,l,r);
    }
    return 0;
}
