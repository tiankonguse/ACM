#include<iostream>
#define SIZE 501
using namespace std;
int n,k,x,y;
int t[SIZE];
bool v[SIZE],a[SIZE][SIZE];
bool find(int x)
{
    for(int i=0;i<n;i++)
    {
        if(v[i]==false&&a[x][i]==true) //i未匹配，x到i有边 
        {
            v[i]=true;                 //选择x到i的边 
            if(t[i]==-1||find(t[i]))   
            {
                t[i]=x;
                return true;
            }
        }
    }
    return false;
}
int findMatch(void)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        memset(v,false,sizeof(v));
        if(find(i)) count++;
    }
    return count;
}        
int main()
{
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        memset(t,-1,sizeof(t));
        memset(a,false,sizeof(a));
        for(int i=0;k-i>0;i++)
        {
            scanf("%d %d",&x,&y);
            a[x-1][y-1]=true;
        }
        printf("%d\n",findMatch());
    }
    return 0;
}
