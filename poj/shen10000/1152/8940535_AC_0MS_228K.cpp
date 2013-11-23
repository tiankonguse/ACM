#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int map[129],num,sum,i,max;
int main()
{
for(i='0';i<='9';i++)
    map[i]=i-48;
    
for(i='A';i<='Z';i++)
    map[i]=i-55;
    
for(i='a';i<='z';i++)
   map[i]=i-61;
   
char str[65000];

while(gets(str))
{
	max=1;
	sum=0;
	for(i=0;str[i];i++)
	{
		num=map[str[i]];
		max=max>num?max:num;
		sum+=num;	
	}
	//if(max==0){printf("such number is impossible!\n");continue;}
	for(i=max;i<62;i++)
	{
		num=sum%i;
		if(num==0){printf("%d\n",i+1);break;}		
	}
	if(i>=62)printf("such number is impossible!\n");

}

return 0;
}
