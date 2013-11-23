#include <cstdio>
#include <string.h>
using namespace std;
int main()
{
    int T,used[256],A,B;
    char chs1[20],chs2[20];
    scanf("%d",&T);
    while (T--){
          scanf("%s %s",chs1,chs2);
          memset(used,0,sizeof(used));
          for (int i=A=0;i<4;i++)A+=(chs1[i]==chs2[i]);
          for (int i=0;i<4;i++)used[chs1[i]]++;
          for (int i=B=0;i<4;i++)B+=used[chs2[i]];
          printf("%dA%dB\n",A,B-A);
    }
    return 0;
}
