#include"iostream"
using namespace std;
__int64 w[21][21],m[21][21];
void init(){
   int i,j,k;
   w[1][1]=m[1][1]=m[2][1]=w[2][2]=1;
   m[2][2]=w[2][1]=0;
   for(i=3;i<=20;i++){
      for(j=1;j<=i;j++){
         for(k=1;k<j;k++){
             w[i][j]+=m[i-1][k];
         }
      }
      for(j=1;j<=i;j++){
         m[i][j]=w[i][i-j+1];
      }
   }
}

int main(){
    int n,a;
    __int64 b;
    int res[21];
    init();
    scanf("%d",&n);
    while(n--){
        scanf("%d%I64d",&a,&b);
        int k=0;
        int t=0,j;
        
        while(++k){
           if(w[a][k]<b)b-=w[a][k];
           else{t=0;break;}
           if(m[a][k]<b)b-=m[a][k];
           else{t=1;break;}
        }
        res[0]=k;
    //   cout<<t<<endl; 
        for(int i=1;i<a;i++){
           if(t==0){
              j=1;
              while(m[a-i][j]<b){
                b-=m[a-i][j];
                j++;
              }
              res[i]=j;
              t=1;
           }
           else{
              j=res[i-1];
              while(w[a-i][j]<b){
                b-=w[a-i][j];
                j++;
              }
              res[i]=j;
              t=0;
           }
        }
      /*  for(int i=0;i<a;i++){
          if(i==a-1)printf("%d\n",res[i]);
          else printf("%d ",res[i]);
       }*/
        for(int i=1;i<=a;i++){
             for(int j=0;j<a;j++){
                 if(res[j]==i){
                    for(int k=j+1;k<a;k++){
                      if(res[k]>=i)res[k]++;
                    }
                    break;
                 }
             }
        }
       for(int i=0;i<a;i++){
          if(i==a-1)printf("%d\n",res[i]);
          else printf("%d ",res[i]);
       }
    }
//    system("pause");
    return 0;
}
