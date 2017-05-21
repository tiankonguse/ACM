#include"iostream"
using namespace std;
int main(){
    int N,a,c1,c2,c3,c4;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&a);
        c1=a/25;
        a%=25;
        c2=a/10;
        a%=10;
        c3=a/5;
        a%=5;
        c4=a;
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",i,c1,c2,c3,c4);
    }
    return 0;
}
