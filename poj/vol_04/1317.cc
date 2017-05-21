#include"iostream"
using namespace std;
char str[80],st[80];
int main(){
    int k,ci,len;
    char pl;
    while(scanf("%d",&k)&&k){
       scanf("%s",str);
       len=strlen(str);
       for(int i=0;i<len;i++){
          if(str[i]=='_')ci=0;
          else if(str[i]=='.')ci=27;
          else ci=str[i]-'a'+1;
          pl=(ci+i+28)%28;
          if(pl==0)pl='_';
          else if(pl==27)pl='.';
          else pl+='a'-1;
          st[k*i%len]=pl;
       }
       for(int i=0;i<len;i++){
          printf("%c",st[i]);
       }
       printf("\n");
    }
    return 0;
}
