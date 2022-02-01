#include"iostream"
#include"string"
using namespace std;
int main(){
    string s;
    char a;
    while(cin>>s){
          printf("300 420 moveto\n310 420 lineto\n");
          int x=310,y=420,d=1;
          for(int i=0;i<s.length();i++){
                  if(s[i]=='A'){
                     d++;
                     d%=4;
                  }
                  else{
                     d--;
                     d+=4;
                     d%=4;
                  }
                  switch(d){
                            case 0:y+=10;break;
                            case 1:x+=10;break;
                            case 2:y-=10;break;
                            case 3:x-=10;break;
                  }
                  printf("%d %d lineto\n",x,y);
          }
          printf("stroke\nshowpage\n");
    }
    return 0;
}
