#include"iostream"
using namespace std;
int dat[17][7];
int na[10],nb[10],nc[10],mx;
int main(){
    int T,la,lb,lc,a,b,c,sa,sb,sc;
    for(int i=2;i<=16;i++){
         dat[i][0]=1;
         for(int j=1;j<=6;j++){
            dat[i][j]=dat[i][j-1]*i;
         }
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        la=lb=lc=mx=0;
        while(a){
           na[la++]=a%10;
           if(na[la-1]>mx)mx=na[la-1];
           a/=10;
        }
        while(b){
           nb[lb++]=b%10;
           if(nb[lb-1]>mx)mx=nb[lb-1];
           b/=10;
        }
        while(c){
           nc[lc++]=c%10;
           if(nc[lc-1]>mx)mx=nc[lc-1];
           c/=10;
        }
        bool flag=false;
        for(int i=mx+1;i<=16;i++){
           sa=sb=sc=0;
           for(int j=0;j<la;j++)sa+=na[j]*dat[i][j];
           for(int j=0;j<lb;j++)sb+=nb[j]*dat[i][j];
           for(int j=0;j<lc;j++)sc+=nc[j]*dat[i][j];
           if(sa*sb==sc){
               printf("%d\n",i);
               flag=true;
               break;
           }
        }
        if(!flag)printf("0\n");
    }
   // system("pause");
    return 0;
}
