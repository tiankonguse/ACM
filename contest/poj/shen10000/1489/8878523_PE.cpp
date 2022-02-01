#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char cstr1[6]={"|n98r"};
char cstr0[30][40],cstr2[100];
int  istr0[30],istr1[30];
int n=1;

void fun0()
{
int p,m;
int i,j,k;
n=1;
for(i=0;;i++)
{
	istr0[i]=n;
	m=n;
	k=0;
	for(j=0;;j++)
	{
		p=m%10;
		while(p--)
		{
		cstr0[i][k++]=cstr1[j];	
		}
		
		
		
		m/=10;
		if(m==0)break;
		cstr0[i][k++]=' ';
	}
	
	istr1[i]=k+1;
	
	for(;k<34;k++)
	{
	cstr0[i][k]=32;		
	}	
	
	cstr0[i][34]='\0';	
	n*=2;
	if(n>99999)break;		
}
n=i;
n++;
//printf("%d\n",n);
//for(i=0;i<n;i++)
//printf("%8d %s %d\n",istr0[i],cstr0[i],istr1[i]);		
}


int fun2(char *p)
{
int n=0;
int i;

for(i=0;p[i];i++)
{
switch(p[i])
{
case '|':n+=1;break;	
case 'n':n+=10;break;	
case '9':n+=100;break;	
case '8':n+=1000;break;	
case 'r':n+=10000;break;
case ' ':break;		
}
	
}	
	
return n;	
	
	
}
char* fun3(int n)
{
	memset(cstr2,0,sizeof(cstr2));
	int i,j,k;
	int p;
	j=0;
	
	for(i=0;;i++)
	{
		p=n%10;
		int q=p;
		while(p--)
		{
			cstr2[j++]=cstr1[i];	
		}	
		n/=10;
		if(n==0)break;
		if(q)cstr2[j++]=' ';		
	}
	cstr2[j]='\0';

//printf("%s\n",cstr2);	
return cstr2;	
}


int main()
{
	//freopen("1489in.txt","r",stdin);
	//freopen("1489out.txt","w",stdout);
int i,j,k;
int n,p;
fun0();

char str1[100],str2[100];

while(1)
{

    str1[0]=getchar();
    if(str1[0]==10)break;
    for(i=1;;i++)
    {
    str1[i]=getchar();
    if(str1[i]==10){str1[i]='\0';break;}             
    }
    for(i=0;;i++)
    {
    str2[i]=getchar();
    if(str2[i]==10){str2[i]='\0';break;}             
    }
int x1=fun2(str1);//printf("%d %s\n",x1,str1);
int x2=fun2(str2);//printf("%d %s\n",x2,str2);
int x3=x1*x2;

n=x2;
for(i=0;;i++)
{
    p=n%2;
    if(p)cstr0[i][istr1[i]]='*';
    printf("%s%s\n",cstr0[i],fun3(x1));	
    if(p)cstr0[i][istr1[i]]=' ';
    x1*=2;
    n/=2;
    if(n==0)break;	
}	
printf("The solution is: %s\n",fun3(x3));
	
}

	//getchar();getchar();
return 0;	
}

