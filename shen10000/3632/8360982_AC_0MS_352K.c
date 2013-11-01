#include<stdio.h>
int main(){
    int t,a[20],n,i,j,max_,min_;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
    scanf("%d",&n); 
    max_=-1;
    min_=100;
    for(j=0;j<n;j++){
    scanf("%d",&a[j]);
    max_=(max_<a[j])?a[j]:max_;
    min_=(min_>a[j])?a[j]:min_;              
   } 
    printf("%d\n",2*(max_-min_));
   }
    return 0;
    }
