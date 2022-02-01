#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int str4[13];


int main()
{

	char str[17][100];
	int i,j,len;
	memset(str,0,sizeof(str));
	while(scanf("%s",str[0]),str[0][0]!='-')
	{        
	
	    for(j=1;j<=15;j++)
	    {
	          memset(str4,0,sizeof(str4));  
	       len=strlen(str[j-1]);
	        for(i=0;i<len;i++)  
	            str4[str[j-1][i]-'0']++;
	           
	        for(i=0;i<10;i++)
	        	if(str4[i])sprintf(str[j],"%s%d%d", str[j],str4[i],i);       
	        //printf("%d  %s\n",j,str[j]);
	        bool pp=false;
	        for(i=j-1;i>=0;i--)
	            if(strcmp(str[j],str[i])==0)    
	            {
	                if(j==1)printf("%s is self-inventorying\n",str[0]);        
	                else if(i==j-1)printf("%s is self-inventorying after %d steps\n",str[0],j-1);
	                else printf("%s enters an inventory loop of length %d\n",str[0],j-i);
	                pp=true;  
	                break; 
	            }
	            
	        if(pp==true)break;
	
	    }
		if(j>15)printf("%s can not be classified after 15 iterations\n",str[0]);
		memset(str,0,sizeof(str));
	}
 return 0;
}
