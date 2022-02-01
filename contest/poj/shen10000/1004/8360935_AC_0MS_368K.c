#include<stdio.h>
int main(){
float m,sum;
int i;
for(sum=0,i=1;i<=12;i++){
scanf("%f",&m);
sum=sum+m;
}

printf("$%.2f\n",sum/12);
return 0;
}
