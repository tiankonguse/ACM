#include"iostream"
#include"algorithm"
using namespace std;
int digit[4];
int leng(int n){
     int r=0;
     while(n){
         r++;
         n/=10;
     }
     return r;
}
int init(int n,int len){
   for(int i=0;i<len;i++){
              digit[i]=n%10;
              n/=10;
   }
   sort(digit,digit+len);
   int n1=0,n2=0;
   for(int i=0;i<len;i++){
       n1=n1*10+digit[i];
       n2=n2*10+digit[len-1-i];
   }
   printf("%d-%d=%d\n",n2,n1,n2-n1);
   return n2-n1;
}
int main(){
    int N,k,cnt,res;
    while(scanf("%d",&N)){
       if(N==-1)break;
       printf("N=%d:\n",N);
       if(N<1000 || N>=10000)printf("No!!\n");
       else{
          k=N;
          for(int i=0;i<4;i++){
              digit[i]=N%10;
              N/=10;
          }      
          if(digit[0]==digit[1] && digit[0]==digit[2] && digit[0]==digit[3]){
              printf("No!!\n");
          }
          else{
               cnt=0;
               while(++cnt){
                   k=init(k,leng(k));
                   if(k==0 || k==6174){
                      printf("Ok!! %d times\n",cnt);
                      break;
                   }
               } 
          }
       }
    }
    return 0;   
}    
