#include"iostream"
using namespace std;
int dat[26]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
char str[30];
int main(){
    int len;
  //  char c;
  int c;
    while(~scanf("%s",str)){
       len=strlen(str);
   //    c='.';
       c=-1;
       for(int i=0;i<len;i++){
          if(dat[str[i]-'A']!=c){
        //       c=str[i];
               c=dat[str[i]-'A'];
               if(c!=0)printf("%d",c);
          }
       }
       printf("\n");
    }
    return 0;
}
