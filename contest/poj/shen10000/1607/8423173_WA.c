#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
//#include<iostream>
//using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int n,m,str1[100000];
    double str2[100000];
    memset(str1,0,sizeof(str1));
    m=1;
    printf("Cards  Overhang\n");
    while(scanf("%d",&n)!=EOF)
    {
        if(str1[n]==0)      
            for(;m<=n;m++)
            {   
                str1[m]=1;
                str2[m]=str2[m-1]+(1/(2.0*m));
            }
        printf("%5d  ",n);  
        printf("%8.3lf\n",str2[n]);             
    }

//getchar();getchar();
return 0;
}
