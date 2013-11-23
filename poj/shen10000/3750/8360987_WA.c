#include<stdio.h>
#include<string.h>
int main(){
char string[16];
char str[65][16];
int i,w,s,n,j,k;
scanf("%d",&n);
for(i=0;i<=n;i++)
gets(str[i]);
scanf("%d,%d",&w,&s);
for(j=0;j<n;j++){
k=s;
while(n-j-w+1<k){
k-=n-j-w+1;
i=k;
}
if(n-j-w+1>=s)
i=w+s-1;              
puts(str[i]);
w=(i==n-j)?1:i;
for(;i<n-j;i++){
strcpy(str[i],str[i+1]);
}   
          
} 
return 0;
}
