#include"iostream"
#include"string"
#include"algorithm"
using namespace std;
int s[101],sg[10001],num[10001];
void inti(int* s,int k){
    sg[0]=0;
    for(int i=1;i<=10000;i++){
            for(int j=0;j<k;j++){
                    if(i-s[j]<0)break;
                    num[sg[i-s[j]]]=i;
            }
            for(int j=0;j<=10000;j++){
                    if(num[j]!=i){
                                  sg[i]=j;
                                  break;
                    }
            }
    }
}
int main(){
    int k,m,l,t,p;
    string s0;
    while(scanf("%d",&k)==1){
       if(k==0)break;
       for(int i=0;i<k;i++){
               scanf("%d",&s[i]);
       }
       sort(s,s+k);
       inti(s,k);
       scanf("%d",&m);
       for(int i=0;i<m;i++){
               scanf("%d",&l);
               t=0;
               for(int j=0;j<l;j++){
                       scanf("%d",&p);
                       t^=sg[p];
               }
               if(t)printf("W");
               else printf("L");
       }
       printf("\n");
      
    }    
    return 0;
}
