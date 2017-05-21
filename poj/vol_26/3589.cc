#include"iostream"
using namespace std;
int main(){
    int N,ca,cb;
    char a[10],b[10];
    scanf("%d",&N);
    while(N--){
        ca=cb=0;
        scanf(" %s%s",a,b);
        //  cin>>a>>b;
        for(int i=0;i<4;i++){
           for(int j=0;j<4;j++){
              if(a[i]==b[j]){
                  if(i==j)ca++;
                  else cb++;
                  break;
              }
           }
        }
        printf("%dA%dB\n",ca,cb);
    }
    return 0;
}
