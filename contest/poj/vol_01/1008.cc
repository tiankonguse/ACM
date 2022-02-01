#include"iostream"
#include"string"
using namespace std;
char haab[19][10]={"pop","no", "zip", "zotz", "tzec", 
                   "xul","yoxkin", "mol", "chen", "yax", 
                   "zac", "ceh", "mac", "kankin", "muan", 
                   "pax", "koyab", "cumhu","uayet"};
char tzo[20][10]={"imix", "ik", "akbal", "kan", "chicchan", 
                  "cimi", "manik", "lamat", "muluk", "ok", 
                  "chuen", "eb", "ben", "ix", "mem", 
                  "cib", "caban", "eznab", "canac", "ahau"}; 
int find(char* s){
   for(int i=0;i<19;i++)if(strcmp(s,haab[i])==0)return i;
}
int main(){
    int T,d,y,m,days;
    char str[10];
    scanf("%d",&T);
    printf("%d\n",T);
    while(T--){
       scanf("%d. %s %d",&d,str,&y);
       m=find(str);
       days=d+m*20+y*365;
       y=days/260;
       d=days%260;
       m=d%13+1;
       d=d%20;
       printf("%d %s %d\n",m,tzo[d],y);
    }
 //   system("pause");
    return 0;
}
