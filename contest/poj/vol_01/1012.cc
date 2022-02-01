#include"iostream"
using namespace std;
int main(){
    int a[15],n;
    for(n=1;n<=13;n++){
         int sum=n*2,now=0,m=0,k=0;
         while(++m){
             k=0;
             now=0;
             sum=n*2;
           //  cout<<"n="<<n<<",m="<<m<<endl;
             while(1){
               now=(now+m-1)%sum+1;
            //   cout<<"now="<<now<<endl;
           //  system("pause");
               if(now<=n)break;
               else{
                    sum--;
                    now--;
                    k++;
                    if(k==n)break;
               }
             }
             if(k==n)break;
         }     
         a[n]=m;
    }
    
    while(scanf("%d",&n)&&n){
       printf("%d\n",a[n]);
    }
    return 0;
}
