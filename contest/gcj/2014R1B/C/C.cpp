//program C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>

using namespace std;

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  int data[5];
  for(int i=0;i<5;i++)
    {
      data[i]=x%10;
      x/=10;
    }
  for(int i=4;i>=0;i--)
    putchar(data[i]+48);
}

int p[50];

int getroot(int x)
{
  return (p[x]==x)?x:(p[x]=getroot(p[x]));
}

int main()
{
  freopen("C.in","r",stdin);
  //freopen("C.out","w",stdout);
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int n=get(),m=get();
      static int w[50];
      for(int i=0;i<n;i++)
        w[i]=get();
      static bool g[50][50];
      memset(g,0,sizeof(g));
      for(int i=0;i<m;i++)
        {
          int x=get()-1,y=get()-1;
          g[x][y]=g[y][x]=true;
        }
      printf("Case #%d: ",test);
      int root=0;
      for(int i=1;i<n;i++)
        if(w[i]<w[root])
          root=i;
      static bool flag[100],instack[100];
      memset(flag,0,sizeof(flag));
      memset(instack,0,sizeof(instack));
      flag[root]=instack[root]=true;
      static int sta[100];
      int top=1;
      sta[0]=root;
      output(w[root]);
      for(int i=1;i<n;i++)
        {
          int best=-1;
          for(int x=0;x<n;x++)
            {
              if(flag[x])
                continue;
              bool linked=false;
              for(int j=0;j<top;j++)
                if(g[x][sta[j]])
                  linked=true;
              if(!linked)
                continue;
              int first=top-1;
              while(!g[x][sta[first]])
                first--;
              for(int j=first+1;j<top;j++)
                instack[sta[j]]=false;
              for(int j=0;j<n;j++)
                p[j]=j;
              for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                  {
                    if(flag[j]&&!instack[j])
                      continue;
                    if(flag[k]&&!instack[k])
                      continue;
                    if(g[j][k])
                      p[getroot(j)]=getroot(k);
                  }
              bool connected=true;
              for(int j=0;connected&&j<n;j++)
                for(int k=0;connected&&k<n;k++)
                  {
                    if(flag[j]&&!instack[j])
                      continue;
                    if(flag[k]&&!instack[k])
                      continue;
                    if(getroot(j)!=getroot(k))
                      connected=false;
                  }
              for(int j=first+1;j<top;j++)
                instack[sta[j]]=true;
              if(!connected)
                continue;
              if(best==-1||w[x]<w[best])
                best=x;
            }
          flag[best]=true;
          instack[best]=true;
          while(!g[best][sta[top-1]])
            {
              top--;
              instack[sta[top]]=false;
            }
          sta[top++]=best;
          output(w[best]);
        }
      putchar('\n');
    }
  return 0;
}
