#include"iostream"
using namespace std;
int main(){
    int STEP,MOD;
    int gcd(int s,int m);
    while(cin>>STEP>>MOD){
            printf("%10d%10d",STEP,MOD);
            if(gcd(STEP,MOD)) printf("    Good Choice\n\n");
            else printf("    Bad Choice\n\n");
    }
    return 0;
}
int gcd(int s,int m){
      int tmp;
      while(s){
         if(s<m){
              tmp=s;
              s=m;
              m=tmp;
         }
         s=s-s/m*m;      
      }
      if(m==1) return 1;
      else return 0;
}
