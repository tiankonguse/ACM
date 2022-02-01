#include"iostream"
using namespace std;
char str[80];
int main(){
    int len;
    bool flag;
    while(scanf("%s",str)){
        if(str[0]=='*')break;
        len=strlen(str);
        flag=false;
        for(int d=1;d<len-1;d++){
           for(int i=0;i<len-d;i++){
              for(int j=i+1;j<len-d;j++){
                  if(str[i]==str[j] && str[i+d]==str[j+d]){
                     flag=true;
                     break;
                  }
              }
              if(flag)break;
           }
           if(flag)break;
        }
        if(!flag)printf("%s is surprising.\n",str);
        else printf("%s is NOT surprising.\n",str);
    }
    return 0;
}
