#include"iostream"
using namespace std;
int a[9];
int main(){
    int f,ab;
    bool flag;
    while(~scanf("%d",&a[0])){
       for(int i=1;i<9;i++)scanf("%d",&a[i]);
       f=0;
       flag=true;
       while(f<9){
           if(a[f]!=0){
               if(flag){
                    flag=false;
                    ab=abs(a[f]);
                    if(a[f]<0)printf("-");
                    if(ab!=1)printf("%d",ab);
                    if(f==7)printf("x");
                    else if(f==8){
                         if(ab==1)printf("%d",ab);
                    }
                    else printf("x^%d",8-f);
               }
               else{
                    if(a[f]<0)printf(" - ");
                    else printf(" + ");
                    ab=abs(a[f]);
                    if(ab!=1)printf("%d",ab);
                    if(f==7)printf("x");
                    else if(f==8){
                         if(ab==1)printf("%d",ab);
                    }
                    else printf("x^%d",8-f);
               }
           }  
           f++;  
       }
       if(flag)printf("0\n");
       else printf("\n");
    }
    return 0;
}
