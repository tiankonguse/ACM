#include"iostream"
using namespace std;
int main(){
    int T,y,mo,d,h,m,s;
    char c;
    scanf("%d",&T);
    while(T--){
       scanf("%d/%d/%d-%d:%d:%d",&y,&mo,&d,&h,&m,&s);
       if(h>=12){
           c='p';
           if(h>12)h-=12;
       }
       else{
           c='a';
           if(h==0)h=12;
       }
       printf("%02d/%02d/%04d-%02d:%02d:%02d%cm\n",mo,d,y,h,m,s,c);
    }
    //system("pause");
    return 0;
}
