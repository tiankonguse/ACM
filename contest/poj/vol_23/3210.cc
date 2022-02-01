#include"iostream"
using namespace std;
int main(){
    int N;
    while(scanf("%d",&N)&&N){
       if(N%2==0)printf("No Solution!\n");
       else printf("%d\n",N-1);
    }
    return 0;
}
