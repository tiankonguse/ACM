#include"iostream"
#include"cstdlib"
using namespace std;
int main(){
    int N;
    char c;
    int b[4];
    int bit[8]={128,64,32,16,8,4,2,1};
    scanf("%d",&N);
    while(N--){
       memset(b,0,sizeof(b));
       for(int i=0;i<32;i++){
          scanf(" %c",&c);
          if(c=='1'){
             b[i/8]+=bit[i%8];
          }
       }   
       printf("%d.%d.%d.%d\n",b[0],b[1],b[2],b[3]);
    }
    return 0;
}
