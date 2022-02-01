#include <iostream>

using namespace std;

int main()
{
   // freopen("in.txt","r",stdin);
    int M,T,U,F,D,ud,fd,sum=0,r;
    char c;
    bool flag=false;
    scanf("%d%d%d%d%d",&M,&T,&U,&F,&D);
    ud=U+D;
    fd=F*2;
    r=T;
   // getchar();
    for(int i=0;i<T;i++){
      scanf(" %c",&c);
      if(!flag){
        if(c=='f')sum+=fd;
        else sum+=ud;
        if(sum>M){r=i;flag=true;}
      }
    }
    printf("%d\n",r);
    return 0;
}
