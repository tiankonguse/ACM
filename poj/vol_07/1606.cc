#include"iostream"
using namespace std;
int main(){
    int ca,cb,n,a,b;
    while(scanf("%d%d%d",&ca,&cb,&n)!=EOF){
         a=b=0;
         while(b!=n){
            if(b==cb){
               printf("empty B\n");
               b=0;
            }
            else if(a==0){
               printf("fill A\n");
               a=ca;
            }
            else{
               printf("pour A B\n");
               b+=a;
               a=0;
               if(b>cb){
                  a+=b-cb;
                  b=cb;
               }
            }
         }
         printf("success\n");
    }
    return 0;
}
