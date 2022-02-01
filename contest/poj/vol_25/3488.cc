#include"iostream"
using namespace std;
char str[1001][1001];
int main(){
    int k,len;
    while(~scanf("%d",&k)){
        for(int i=k-1;i>=0;i--){
           scanf(" %s",str[i]);
        }
        len=strlen(str[0]);
        for(int i=len-1;i>=0;i--){
           for(int j=0;j<k;j++){
              if(str[j][i]=='_')printf(" ");
              else if(str[j][i]=='\\')printf("\n");
              else printf("%c",str[j][i]);
           }
        }
        printf("\n\n");
    }
    return 0;
}
