#include"iostream"
using namespace std;
int countbit[3000501];
int main(){
    countbit[0]=0;
    for(int i=1;i<3000501;i++){
        countbit[i]=1+countbit[i-((i^(i-1))&i)];
    }
    int n,c;
    while(scanf("%d",&n)&&n){
       c=countbit[n];
       for(int i=n+1;;i++){
          if(countbit[i]==c){
             printf("%d\n",i);
             break;
          }
       }
    }
    return 0;
}
