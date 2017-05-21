#include"iostream"
using namespace std;
char board[25][35];
char str[8]={'a','b','c','d','e','f','g','h'};
char list[16]={'K','Q','R','B','N','P','k','q','r','b','n','p'};
int main(){
    bool flag;
    for(int i=16;i>=0;i--)scanf("%s",board[i]);
    printf("White: ");
    flag=true;
    for(int k=0;k<6;k++){
       for(int i=1;i<16;i+=2){
          for(int j=2;j<=30;j+=4){
              if(board[i][j]==list[k]){
                     if(k<5)printf("%c%c%d,",board[i][j],str[j/4],(i+1)/2);
                     else{
                        if(flag){
                          printf("%c%d",str[j/4],(i+1)/2);
                          flag=false;
                        }
                        else printf(",%c%d",str[j/4],(i+1)/2);
                     }
              }
          }
       }
    }
    printf("\nBlack: ");
    flag=true;
    for(int k=6;k<12;k++){
       for(int i=15;i>=0;i-=2){
          for(int j=2;j<=30;j+=4){
              if(board[i][j]==list[k]){
                     if(k<11)printf("%c%c%d,",board[i][j]-32,str[j/4],(i+1)/2);
                     else{
                        if(flag){
                          printf("%c%d",str[j/4],(i+1)/2);
                          flag=false;
                        }
                        else printf(",%c%d",str[j/4],(i+1)/2);
                     }
              }
          }
       }
    }
    printf("\n");
   // system("pause");
    return 0;
}
