#include<stdio.h>
#include<string.h>
const int M= 1000001;
bool map[M];
int str[M];
int ans[M];
int p;
int prame()
{
    memset(map,true,sizeof(map));
    int k=0;
    str[k++]=2;
    for(int i=3;i<M;i+=2)
        if(map[i])
        {
			//printf("%d :%d\n",k,i);
            str[k++]=i;
            
            for(int j=i;j<M;j+=i)
                map[j]=false;
        }
return k;
}

void print(int *p,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d:%d\n",i,p[i]);
	}	
	printf("\n");
}

int euler(int n,int m)
{

    if(m==1)return 1;
    if(n==1)return m;

    memset(map,true,sizeof(map));
    int i=0,num=n;
    for(;num!=1;)
    {
		//printf("%d   %d\n",num,str[i]);
        if(num%str[i]==0)
        {
            
            while(num%str[i]==0)num/=str[i];
            for(int j=str[i];j<n;j+=str[i])
            {
                map[j]=false;
            }

        }
        i++;
    }
    num=0;
    for(i=1;i<n;i++)
    {
        if(map[i])
        {
		//	printf("%d  %d\n",num,i);
            ans[++num]=i;
        }
    }
    ans[0]=ans[num];
    return ans[m%num]+(m-1)/num * n;

}

int main()
{
prame();
//print(str,100);
int n,m;
while(scanf("%d%d",&n,&m)!=EOF)
{
printf("%d\n",euler(n,m));
}
return 0;
}
