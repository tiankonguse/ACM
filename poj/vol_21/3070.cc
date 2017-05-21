#include"iostream"
using namespace std;
int ma[32][2][2]={1,1,1,0},e[2][2]={1,0,0,1},re[2][2];
void cal(int a[2][2],int b[2][2],int c[2][2],int len){
      int sum;
      for(int i=0;i<len;i++){
         for(int j=0;j<len;j++){
            sum=0;
            for(int k=0;k<len;k++){
               sum+=(a[i][k]%10000)*(b[k][j]%10000);
            }
            c[i][j]=sum%10000;
         }
      }
}
void bit(int n,int &k,int s[]){
    k=0;
    while(n){
       s[k++]=n%2;
       n/=2;
    }
}
int main(){
    for(int i=1;i<=31;i++){
      cal(ma[i-1],ma[i-1],ma[i],2);
    }
    int n,k,s[40];
    while(cin>>n){
       if(n==-1)break;
       if(n==0){cout<<0<<endl;continue;}
       e[0][0]=e[1][1]=1;
       e[1][0]=e[0][1]=0;
       bit(n,k,s);
       for(int i=0;i<k;i++){
         if(s[i]!=0){
                     cal(ma[i],e,re,2);
                     for(int l=0;l<2;l++)for(int m=0;m<2;m++)e[l][m]=re[l][m];
         }
       }
       printf("%d\n",re[0][1]);
       }
      /* for(int i=0;i<2;i++){
          for(int j=0;j<2;j++){
        printf("%d ",re[i][j]);
      }
      printf("\n");
}*/

    /*   cout<<k<<endl;
       for(int i=0;i<k;i++)cout<<s[i]<<" ";
       cout<<endl;
       } */
      /*  for(int i=0;i<2;i++){
          for(int j=0;j<2;j++){
        printf("%d ",ma[n][i][j]);
      }
      printf("\n");*
    }
    }*/
    /*
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        scanf("%d",&ma[i][j]);
      }
    }
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        scanf("%d",&mb[i][j]);
      }
    }
    int c[2][2];
    cal(ma,mb,c,2);
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        printf("%d ",c[i][j]);
      }
      printf("\n");
    }
    */
    return 0;
}
