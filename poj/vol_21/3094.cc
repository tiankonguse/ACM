#include"iostream"
using namespace std;
int main(){
    char a[400];
    int l,sum;
    while(gets(a)){
       l=strlen(a);
       if(l==1 && a[0]=='#')break;
       sum=0;
       for(int i=0;i<l;i++){
          if(a[i]>='A' && a[i]<='Z')sum+=(a[i]-64)*(i+1);
       }
       printf("%d\n",sum);
    }
    return 0;
}
