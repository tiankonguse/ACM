#include"cstdio"
using namespace std;
int main(){
    int T,h,m;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
       scanf("%d:%d",&h,&m);
       if(m!=0)printf("0\n");
       else{
          h+=12;
          if(h>24)h-=24;
          printf("%d\n",h);
       }
    }
    return 0;
}
