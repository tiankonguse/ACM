#include"iostream"
using namespace std;
int main(){
    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        printf("%d\n",(N/2)*((N-1)/2));
    }
    return 0;
}
