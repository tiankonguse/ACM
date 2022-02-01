#include"iostream"
#include"string"
using namespace std;
int main(){
    char c;
    bool flag=false;
    while(~scanf("%c",&c)){
        if(c=='"'){
           if(!flag)printf("``");
           else if(flag)printf("\'\'");
           flag=!flag;
        }
        else putchar(c);
    }
    return 0;
}
