#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,n,a,sum;
    while((scanf("%d%d",&m,&n))!=EOF){
    for(sum=m;m>=n;){
    sum+=m/n;
    m=m%n+m/n;
    }
    printf("%d\n",sum);
}
    return 0;
    }
