#include"iostream"
#include"cstdio"
#include"string.h"
using namespace std;
char str[20500],str2[20500];
int N,e1[20500],e2[20500];
int change(char c){
    if(c>='A')return c-55;
    else return c-'0';
}
int main(){
    while(~scanf(" %s%s",str,str2)){
    N=strlen(str);
    for(int i=0;i<N;i+=2){
       e1[i]=change(str[i])*16+change(str[i+1]);
       e2[i]=change(str2[i])*16+change(str2[i+1]);
    }
    e2[N]=change(str2[N])*16+change(str2[N+1]);
    int text=32,key;
    key=text^e2[0];
    printf("%02X",key);
    for(int i=0;i<N;i+=2){
       text=key^e1[i];
       key=text^e2[i+2];
       printf("%02X",key);
    }
    printf("\n");
    }
    //system("pause");
    return 0;
}
