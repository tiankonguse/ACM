#include"iostream"
using namespace std;
char s1[10],s2[10];
int ab(int x){
   return x>0?x:-x;
}
int max(int x,int y){
   return x>y?x:y;
}
int main(){
    int T,x1,y1,x2,y2,ax,ay;
    scanf("%d",&T);
    while(T--){
       scanf(" %s%s",s1,s2);
       x1=s1[0]-'a';y1=s1[1]-'0';
       x2=s2[0]-'a';y2=s2[1]-'0';
       ax=ab(x1-x2);ay=ab(y1-y2);
       if(ax==0 && ay==0)printf("0 0 0 0\n");
       else{
           printf("%d ",max(ax,ay));
           if(x1==x2 || y1==y2 || ax==ay)printf("1 ");
           else printf("2 ");
           if(x1==x2 || y1==y2)printf("1 ");
           else printf("2 ");
           if((ax+ay)%2!=0)printf("Inf\n");
           else{
              if(ax==ay)printf("1\n");
              else printf("2\n");
           }
       }
    }
 //   system("pause");
    return 0;
}
