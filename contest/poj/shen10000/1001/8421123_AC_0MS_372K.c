#include<stdio.h>
#include<string.h>


char aaa[26][130];
int ccc[29]={0},hhh[29];
int l;
char bbb[130]={0},ddd[130]={0};
			int fab(int m)
			{	
				memset(ddd,0,sizeof(ddd));
				int num1,num2,i,j;
				if(ccc[m]==1)return 0;
				if(m==1){ccc[1]=1;return 0;}
					fab((m+1)/2);
					fab(m/2);
					num1=hhh[(m+1)/2];
					num2=hhh[m/2];
					for(i=0;i<num2;i++)
					for(j=0;j<num1;j++)
						{	
							ddd[j+i]+=aaa[(m+1)/2][j]*aaa[m/2][i];
							ddd[j+i+1]+=ddd[j+i]/10;
							ddd[j+i]=ddd[j+i]%10;
						}
						int num3;	
						if(ddd[j+i-1]!=0)
						num3=j+i;
						else
						num3=j+i-1;
					hhh[m]=num3;	
					for(i=0;i<num3;i++)
						aaa[m][i]=ddd[i];
					memset(bbb,0,sizeof(bbb));
					memset(ddd,0,sizeof(ddd));
					ccc[m]=1;
				return 0;
			}
int main()
{
	char fff[130]={0};
	char str[7]={'0'};
	int n,a,i,x,y,j;
	while(scanf("%s%d",str,&n)!=EOF)
	{
		memset(hhh,0,sizeof(hhh));
			l=strlen(str);
		    for(x=l-1;x>0;x--)
		 		if(str[x]==46)break; 
			a=0;
			if(x!=0)
			{	
				while(str[l-1-a]=='0')
					a++;
			l=l-a;
			a=l-1-x;
		}
			for(i=0,j=0;i<l;i++)
			{				
				if(str[i]==46)
					i++;
				fff[j]=str[i]-48;
				j++	;	
			}
			if(x!=0)l--;
		for(i=0;i<l;i++)
			aaa[1][l-1-i]=fff[i];
		hhh[1]=l;	
		fab(n);
	if(aaa[n][hhh[n]-1]!=0)
	printf("%d",aaa[n][hhh[n]-1]);
	for(i=1;i<hhh[n];i++)
	{	
	if(hhh[n]-i==a*n&&a!=0)printf(".");
	printf("%d",aaa[n][hhh[n]-1-i]);
	
	
	}	
		printf("\n");
	memset(bbb,0,sizeof(bbb));	
	memset(ccc,0,sizeof(ccc));
	memset(aaa,0,sizeof(aaa));
	memset(fff,0,sizeof(fff));
	}
getchar();
return 0;	

}
