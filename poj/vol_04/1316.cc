#include"iostream"
#include"cstdlib"
using namespace std;
int gen(int a){
    int s=a;
    while(a){
       s+=a%10;
       a/=10;
    }
    return s;
}
int main(){
    bool a[10001];
    memset(a,false,sizeof(a));
    int g;
    for(int i=1;i<=10000;i++){
          if(a[i])continue;
          printf("%d\n",i);
         
             a[i]=true;
             g=gen(i);
             while(!a[g] && g<=10000){
                 a[g]=true;
                 g=gen(g);
             }   
         
    }
    //system("pause");
    return 0;
}
