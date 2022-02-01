#include"iostream"
#include"algorithm"
using namespace std;
char str[81];
int main(){
    int T,p,len;
    scanf("%d%",&T);
    for(int i=1;i<=T;i++){
       scanf("%d%s",&p,str);
       len=strlen(str);
       if(next_permutation(str,str+len)){
           printf("%d %s\n",p,str);
       }
       else{
           printf("%d BIGGEST\n",p);
       }
    }
   // system("pause");
    return 0;
}
