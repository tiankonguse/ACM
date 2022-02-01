#include"iostream"
using namespace std;
char str[15];
int num[15];
int main(){
    int i;
    while(~scanf("%s",str)){
      // if(str[0]=='E')break;
       for(i=0;str[i];i++){
          num[i]=(num[i]+(str[i]-'0'))%10;
       }
    }
    for(int j=0;j<i;j++){
       printf("%d",num[j]);
    }
    printf("\n");
   // system("pause");
    return 0;
}
