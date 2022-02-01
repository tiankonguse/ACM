#include"iostream"
#include"algorithm"
#include"cstdlib"
using namespace std;
char str[105][25];
char tmp[105][25];
char tez[25];
int cmp(const void *a, const void *b)
{
  char *x=(char *)a;
	char *y=(char *)b;
	return strcmp(x,y);
}

int main(){
    int cnt=0;
    bool flag;
    while(scanf("%s",str[cnt])){
        if(strcmp(str[cnt],"XXXXXX")==0)break;
        cnt++;
    }
    qsort(str,cnt,sizeof(str[0]),cmp);
    memcpy(tmp,str,sizeof(str));
    for(int i=0;i<cnt;i++){
         sort(tmp[i],tmp[i]+strlen(tmp[i]));
    }
    while(scanf("%s",tez)){
        if(strcmp(tez,"XXXXXX")==0)break;
        flag=true;
        sort(tez,tez+strlen(tez));
        for(int i=0;i<cnt;i++){
           if(strcmp(tez,tmp[i])==0){
              printf("%s\n",str[i]);
              flag=false;
           }
        }
        if(flag)printf("NOT A VALID WORD\n");
        printf("******\n");
    }
  //  system("pause");
    return 0;
}
