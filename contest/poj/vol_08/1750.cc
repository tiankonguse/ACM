#include"iostream"
using namespace std;
char str0[11],str[11];
int main(){
    int i,j,s=0;
    scanf("%s",str0);
    printf("%s\n",str0);
    while(~scanf("%s",str)){
        for(i=0,j=0;str0[i],str[j];i++,j++){
            if(str0[i]!=str[i])break;
        }
        if(i>s)s++;
        else s=i;
        for(i=0;i<s;i++)printf(" ");
        printf("%s\n",str);
        memcpy(str0,str,sizeof(str));
    }
    return 0;
}
