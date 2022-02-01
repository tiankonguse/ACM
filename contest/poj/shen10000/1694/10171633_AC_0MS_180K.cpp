#include<stdio.h>
#include<stdlib.h>

struct T
{
 int num;
 int * next;
}str[220];

int cmp(const void *a,const void *b)
{
 return *((int*)b)     -     *((int*)a);
}

int fun(int k)
{
        int num=str[k].num;
         if(0==num)return 1;
         int *q=str[k].next;
         int *p=new int[num];
         for(int i=0;i<num;i++)
         {
                  p[i]=fun(q[i]);
         }
         qsort(p,num,sizeof(int),cmp);
         int sum=0,key=0;
         for(int i=0;i<num;i++)
         {
                 if(key<p[i]){sum+=(p[i]-key);key=p[i];}
                 key--;
         }

         return sum;
}

int main()
{
        int t,n;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                for(int i=1;i<=n;i++)
                {

                       scanf("%*d%d",&str[i].num);
                       if(0==str[i].num)continue;
                       int *p = new int[str[i].num+1];
                       for(int j=0;j<str[i].num;j++)
                       {
                                scanf("%d",&p[j]);
                       }
                       str[i].next=p;
                }
                printf("%d\n",fun(1));
        }

     return 0;
}