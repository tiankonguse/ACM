#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
while(n--){
int m;
scanf("%d",&m);
int sum=0,p;
for(int i=0;i<m;i++){
scanf("%d",&p);
sum+=p;    
}    
printf("%d\n",sum+1-m);    
} 
return 0;
}
