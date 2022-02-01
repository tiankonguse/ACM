#include"iostream"
using namespace std;
int main(){
    int N;
    char c,res[50][50];
    while(scanf("%d",&N)&&N){
       bool flag=false;
       int k=0;
       getchar();
       while(1){
           for(int i=0;i<N;i++){
              scanf("%c",&c);
              if(c=='\n'){flag=true;break;}
              if(k%2==1)res[N-i-1][k]=c;
              else res[i][k]=c;
           }
           if(flag)break;
           k++;
       }
       for(int i=0;i<N;i++){
          for(int j=0;j<k;j++)
            printf("%c",res[i][j]);
       }
       printf("\n");
    }
    return 0;
}
