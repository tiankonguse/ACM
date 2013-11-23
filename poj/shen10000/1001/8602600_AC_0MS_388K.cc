#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[10];
char str2[26][155];
int str3[26];

void fun2(int a,int b,int c)
{
int str4[155],str5[155];
char *p1=str2[a], *p2=str2[b];
int i,j;
int n=str3[a];
int m=str3[b];

int p=0,q=-1;
memset(str5,0,sizeof(str5));

for(i=0;i<n;i++)
{
    memset(str4,0,sizeof(str4));
    for(j=0;j<m;j++)
    {
        int num1=(p1[i]-'0')*(p2[j]-'0')+str4[i+j];
            
        str4[i+j]=num1%10;
        p=i+j;
        if(num1>9)
        {
            p++;
            str4[p]+=num1/10;
        }
    }

    for(int k=0;k<=p;k++)  
    {
        str5[k]+=str4[k];
        q=k;
        if(str5[q]<10)
        {
        str5[q]=str5[q]%10;
        }
        else 
        while(str5[q]>9)
        {
            
            str5[q+1]+=str5[q]/10;
            str5[q]=str5[q]%10; 
            q++;   
        }    
    }
}    
for(i=0;i<=q;i++)
{
    str2[c][i]=str5[i]+'0';    

}  

str2[c][i]='\0';   
 str3[c]=i;   
}


void fun1(int n)
{

if(str3[n]!=-1)return; 
  
if(n==1)
{
    strcpy(str2[1],str1);
    str3[1]=strlen(str2[1]);
    return; 
}
 
fun1((n+1)/2);
fun1(n/2);

fun2((n+1)/2,n/2,n);
   
return;        
}



int main()
{
char str0[10];
int n;
while(scanf("%s%d",str0,&n)!=EOF)
{
    memset(str3,-1,sizeof(str3)); 
    memset(str2,0,sizeof(str2));
      
    int r=strlen(str0);    
    int k=0;
    
    while(str0[k]!='.')k++;//小数点的位置 
    int i;
    for(i=r-1;i>k;i--)    
    {
        if(str0[i]!='0')
            break;    
    }   
    
    int m=i-k;//小数的位数 
    r=i+1;//剩余的字符的个数
    int j;
    for(j=0;i>=0;i--)
        if(str0[i]!='.') 
        {
            str1[j]=str0[i];
            j++;    
        }      
   
        str1[j]='\0';
    

    fun1(n);
   
    int num1=strlen(str2[n]);
    if(str2[n][num1-1]=='0')
    {
        printf(".");
        for(i=num1-2;i>=0;i--)    
            printf("%c",str2[n][i]);
        printf("\n");    
    }
    else if(m==0)
    {
            for(i=num1-1;i>=0;i--)    
            printf("%c",str2[n][i]);
        printf("\n");     
    }
    else
    {
        for(i=num1-1;i>=0;i--)
        {
             printf("%c",str2[n][i]);
            
             if(i==n*m)printf(".");       
        }
           
         printf("\n");      
    }
}

return 0;
}

