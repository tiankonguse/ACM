#include"iostream"
#include"cstdlib"
#define MAXN 1000001
using namespace std;
int fail[MAXN];
char pat[MAXN],str[MAXN];
int kmp(char *str,char* pat){
    int i,j,k;
    int cnt=0,len;
    memset(fail,-1,sizeof(fail));
    for(i=1;pat[i];++i){
       for(k=fail[i-1];k>=0&&pat[i]!=pat[k+1];k=fail[k]);
       if(pat[k+1]==pat[i])fail[i]=k+1;
    }
    len=i;
    i=j=0;
    while(str[i]){
       if(pat[j]==str[i]){
           ++i,++j;
           if(j==len){cnt++;j=fail[j-1]+1;}
       }
       else if(j==0)++i;
       else j=fail[j-1]+1;
    }
    return cnt;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
       scanf("%s %s",pat,str);
       printf("%d\n",kmp(str,pat));
    }
    return 0;
}
