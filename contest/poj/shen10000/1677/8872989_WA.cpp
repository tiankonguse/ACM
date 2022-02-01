#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
//freopen("out.txt","w",stdout);
int n,m;
char str[5][20]={"all","beautiful","pretty","lovely"};
char name[7][50];
char word[300];
int i,j,k;
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)
scanf("%s",name[i]);
getchar();
while(m--)
{
int num=0;
gets(word);	
word[0]+=32;
bool pp=false;
for(i=0;word[i];i++)
{
if((word[i]==32||word[i]==33)&&pp){num++;pp=false;if(num==10)break;}
if(word[i]!=32&&word[i]!=33)pp=true;

}
bool a=num<10?false:true;
bool b=(strstr(word,str[0])!=0);	
bool c=((strstr(word,str[1])!=0)||
        (strstr(word,str[2])!=0)||
		(strstr(word,str[3])!=0));
if(b)printf("All:");
else
{
bool p=true;
for(i=0;i<n;i++)
{
if(p&&(strstr(word,name[i])!=0)){printf("%s",name[i]);p=false;continue;}
if(strstr(word,name[i])!=0)printf(" %s",name[i]);
}
printf(":");
}

if(!a){printf(" oh\n");continue;}
if(a&&c){printf(" xixi\n");continue;}
if(a){printf(" hehe\n");continue;}
}

	
	
//	getchar();getchar();
	return 0;
}
