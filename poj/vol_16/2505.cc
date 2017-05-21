#include"iostream"
using namespace std;
__int64 k[16];
void inti(){
     k[0]=1;
     for(int i=1;i<16;i+=2){
             k[i]=k[i-1]*9;
             k[i+1]=k[i]*2;
     }
}
int main(){
    int n;
    inti();
    while(scanf("%d",&n)==1){
        for(int i=0;i<16;i++){
             if(n<=k[i]){
                        if(i%2==0)printf("Ollie wins.\n");
                        else printf("Stan wins.\n");
                        break;
             }
        }
    }
    return 0;
}
