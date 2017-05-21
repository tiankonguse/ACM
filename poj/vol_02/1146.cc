#include"iostream"
#include"algorithm"
using namespace std;
int main(){
    int len;
    char str[55];
    while(scanf(" %s",str)){
       if(str[0]=='#')break;
       len=strlen(str);
       if(!next_permutation(str,str+len))printf("No Successor\n");
       else printf("%s\n",str);
    }
    return 0;
}
