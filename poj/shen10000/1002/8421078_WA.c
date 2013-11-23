#include <stdio.h>
#include <string.h>
int number[10000010];
int main()
{
    char str[22];
    int num;
    int i,j,n,m,flag=0;
    int map[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9};


  memset(number,0,sizeof(number));
  for(i=0;i<10;i++)
  printf("%d\n",number[i]);
    scanf("%d",&n);
 for(i=0;i<n;i++)
 {
        num=0;
        scanf("%s",str);
       m=strlen(str); 
     //  printf("%s %d\n",str,m);
     for(j=0;j<m;j++)
     {
        //    printf("%d\n",str[j]);
         if(str[j]>=48&&str[j]<=57)
           {
               num*=10;
            num+=str[j]-48;
           }
             if(str[j]>=65&&str[j]<=89&&str[j]!=81)//字母按照开始建立的对应法则 进行对应
           {
             //   printf("%d\n",str[j]);
            num*=10;
            num+=map[str[j]-65];
           
           }
           
      }// printf("%ld\n",num);
        number[num]++;
 }

 for(i=0;i<10000000;i++)
 {
  if(number[i]>=2)
  {
   printf("%03d-%04d %d\n",i/10000,i%10000,number[i]);
   flag=1;
  }
 }
 if(!flag)printf("No duplicates.\n");
 getchar(); getchar();
 return 0;
}
