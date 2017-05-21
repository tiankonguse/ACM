#include"iostream"
#include"algorithm"
#include"string"
using namespace std;
bool cmp(char a,char b){
     return tolower(a) == tolower(b) ? a < b : tolower(a) < tolower(b);
}
int main(){
    char s[201];
    while(~scanf("%s",s)){
    int len=strlen(s);
    sort(s,s+len,cmp);
    do{
       printf("%s\n",s);
    }
    while(next_permutation(s,s+len));
}
 //   system("pause");
    return 0;
}
