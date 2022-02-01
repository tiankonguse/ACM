#include"iostream"
using namespace std;
int main(){
    int n;
    while(~scanf("%d",&n)){
        if((n&-n)==n)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
