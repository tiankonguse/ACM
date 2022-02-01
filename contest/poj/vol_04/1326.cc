#include"iostream"
#include"string"
using namespace std;
int main(){
    char s1[100],s2[100],c;
    int m,sum=0;
    while(scanf(" %s",s1)){
       if(strcmp(s1,"#")==0)break;
       if(strcmp(s1,"0")==0){printf("%d\n",sum);sum=0;continue;}
       scanf(" %s %d %c",s2,&m,&c);
       if(c=='F')sum+=(int)(2.0*m+0.5);
       else if(c=='B')sum+=(int)(1.5*m+0.5);
       else{
           if(m>500)sum+=m;
           else sum+=500;
       }
    }
    return 0;
}
