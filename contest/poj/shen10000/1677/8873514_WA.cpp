#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[5][20]={"all","beautiful","pretty","lovely"};

bool fun(char *a1,char *p1)
{ int n=strlen(p1);
	char *b1=strstr(a1,p1);
	if(b1==0)return false;
	if( (b1==a1 && (*(b1+n)==32)) || (b1!=a1 && (*(b1-1)==32) && (*(b1+n)==32)) )return true;	
	
return false; 		
}
int main()
{
//freopen("out.txt","w",stdout);
int n,m;

char name[7][500];

int i,j,k;
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)
scanf("%s",name[i]);
getchar();

while(m--)
{
	char word[500];	
	int num=0;
	
	gets(word);	
	
	bool pp=false;
	for(i=0;word[i];i++)
	{
		if(word[i]>=65&&word[i]<=90)word[i]+=32;
		if(word[i]<97||word[i]>122)word[i]=32;
		if((word[i]==32)&&pp){num++;pp=false;if(num==10)break;}
		if(word[i]!=32)pp=true;	
	}
	
	
	bool b=fun(word,str[0]);

	if(b)printf("All");
	else
	{
		bool p=true;
		bool str1[8];
		memset(str1,true,sizeof(str1));
		for(i=0;i<n;i++)
		{
			if(str1[i]&&p&&(fun(word,name[i])!=0)){str1[i]=false;printf("%s",name[i]);p=false;continue;}
			if(str1[i]&&fun(word,name[i])!=0){str1[i]=false;printf(" %s",name[i]);}
		}
	}
	
	
	bool a=(num==10?false:true);
	if(a){printf(": oh\n");continue;}
	
	bool c=((fun(word,str[1])!=0)||
	        (fun(word,str[2])!=0)||
			(fun(word,str[3])!=0));	
	if(c){printf(": xixi\n");continue;}
	
	printf(": hehe\n");
}

	
	
//	getchar();getchar();
	return 0;
}


/*

1，是按名字表出现的顺序输出
2，句子的第一个单词是大写，那么可能就是名字了，考虑变成小写，才能和名字匹配
3，注意小于等于9个的话就输出oh，不管有没有beautiful，pretty，lovely这三个，还有不要弄错边界
4，注意可能出现多次的空格和'!'连在一起的情况
5，注意格式输出
6.！可能会出现在词首，即存在一开始就是空句子的情况，好多程序没有考虑到这一点，
比如：!a!
7.同一个女生的名字可能在一个wish中出现多次！！
*/


