#include<stdio.h>
int num=2;
int str[79000];
bool map[1000000]={false};
void fun(int N)
{
	 
	int k;
	for(int i=str[num-1]+2;i<=N;i+=2)    
	{
	    for(k=1;k<num;k++)
	        if(i%str[k]==0)
	            break;            
	    
	    if(k>=num)
	    {
	        str[num++]=i; 
	        map[i]=true;
		}     
	}        
	 
}

int main()
{

str[0]=2;map[2]=true;
str[1]=3;map[3]=true;
int n,p;
while(scanf("%d",&n),n)
{
	if(n>str[num-1])fun(n);
    int k=1;
    for(int i=1;;i++)
    {
	p=n-str[i];
	if(map[p]){printf("%d = %d + %d\n",n,str[i],p);break;}

    } 

}   
    

return 0;
}

