#include<stdio.h>
int main()
{
     int istr[10007];
     int t,n;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d",&n);
         for(int i=1;i<=n;i++)
             scanf("%d",&istr[i]);

           int sum=0;
           for(int i=1,j;i<=n;i++)
           {
                   for(j=1;j<=n;j++)
                   {
                        if(istr[j]!=j)
                       {
                                sum++;
                              //  printf("%d %d %d\n",sum,istr[j],istr[istr[j]]);
                               int k=istr[j];
                               istr[j]=istr[k];
                               istr[k]=k;
                               break;
                       }
                   }
                   if(j==n)break;
           }



              printf("%d\n",sum);



     }
     return 0;
}