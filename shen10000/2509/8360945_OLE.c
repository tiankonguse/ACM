#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,n,a,sum;
    while((scanf("%d",&m)&&scanf("%d",&n))!=EOF){
    for(sum=m;m>=n;){
    a=m%n;
    m=m/n;
    sum=m+sum;
    m=a+m;
    }
    printf("%d\n",sum);
}
    system("pause");
    return 0;
    }
