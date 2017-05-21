#include"iostream"
using namespace std;
int main(){
    int N;
    while(scanf("%d",&N)&&N){
        if(N>2)printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}
