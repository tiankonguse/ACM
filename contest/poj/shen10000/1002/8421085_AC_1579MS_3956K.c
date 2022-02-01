#include<stdio.h>
#include<string.h>
char aaa[100010][16],bbb[16];
char str1[50011][15],str2[50011][15];

void bubblesort(int n)
{
 int i,j;
 char bbb[16];
 for(i=0;i<n-1;i++)
 for(j=0;j<n-1-i;j++)
    if(strcmp(aaa[j],aaa[j+1])>0) 
    {    
    strcpy(bbb,aaa[j]); 
    strcpy(aaa[j],aaa[j+1]); 
    strcpy(aaa[j+1],bbb); 
    memset(bbb,0,sizeof(bbb));
    }   
        
}

void merge(int p,int q,int r)
{
	int x,y,i,k,j;
		
	x=q-p+1;
	y=r-q;
	for(i=0;i<x;i++)
	strcpy(str1[i],aaa[p+i]);
	for(i=0;i<y;i++)
	strcpy(str2[i],aaa[q+1+i]);
	str1[x][0]=60;
	str2[y][0]=60;
	i=0;j=0;
	for(k=p;k<=r;k++)

		if(strcmp(str1[i],str2[j])>=0)	
		{strcpy(aaa[k],str2[j]);j++;}	
		else{strcpy(aaa[k],str1[i]);i++;}	

}

void mergesort(int p,int r)
{
	int q,i;
	if(p!=r)
	{
		q=(p+r)/2;
		mergesort(p,q);	
		mergesort(q+1,r);
		merge(p,q,r);
	}
	
		
}


int main()
{
	long n,i,j,k,m;
	long fff[50011];
	int ddd[100011];

  	scanf("%d",&n);

for(i=0;i<100011;i++)ddd[i]=1;		

	for(i=0;i<n;i++)
	{
		scanf("%s",aaa[i]);
		
		//****************************************
		//去除无用字符 
		m=strlen(aaa[i]);
		for(j=0,k=0;j<m;j++)
			if((aaa[i][j]>=48&&aaa[i][j]<=57)||(aaa[i][j]>=65&&aaa[i][j]<=90&&aaa[i][j]!='Q'&&aaa[i][j]!='Z'))
			{
				bbb[k]=aaa[i][j];
				k++;
			}
		//printf("%s\n",bbb);	
		//***************************************
		//把字母全变为数字 
	//	m=strlen(bbb);//m一定为七吧
      //  printf("\n%d\n",m); 
		for(j=0;j<7;j++)
		switch(bbb[j])
		{
		case'A':	
		case'B':
		case'C':bbb[j]='2';break;
		case'D':
		case'E':
		case'F':bbb[j]='3';break;
		case'G':
		case'H':
		case'I':bbb[j]='4';break;
		case'J':	
		case'K':	
		case'L':bbb[j]='5';break;
		case'M':	
		case'N':	
		case'O':bbb[j]='6';break;	
		case'P':	
		case'R':	
		case'S':bbb[j]='7';break;	
		case'T':	
		case'U':
		case'V':bbb[j]='8';break;
		case'W':
		case'X':
		case'Y':bbb[j]='9';break;
		default:break;		
		}
		
        
        
        //*******************************
        //将bbb复制给aaa[i]后初始化bbb 
		strcpy(aaa[i],bbb);	
	memset(bbb,0,sizeof(bbb));
	}

//*******************************
//这时所有aaa【i】都为7位字符，且全为数字
//用二分法给aaa【i】排序
if(n>50000)	
mergesort(0,n-1);
else
bubblesort(n);
//for(i=0;i<n;i++)
//printf("%s\n",aaa);
//计算重复的字符串以及个数 
for(i=0,k=0;i<n-1;i++)
{
	if(strcmp(aaa[i],aaa[i+1])==0)
	{
	fff[k]=i;
	ddd[k]++;
	}
	else
		if(ddd[k]>1)k++;

}

if(strcmp(aaa[n-1],aaa[n-2])==0)k++;
for(i=0;i<k;i++)
{

		for(j=0;j<7;j++)
		{
			printf("%c",aaa[fff[i]][j]);	
			if(j==2)printf("-");	
		}
	printf(" %d\n",ddd[i]);	
}
if(k==0)printf("No duplicates.\n");
return 0;	
}