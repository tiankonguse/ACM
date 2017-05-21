#include"iostream"
using namespace std;
int main(){
    char map[100],a[100];    
    scanf("%s",map);
    getchar();
    scanf("%[^\n]",a);
    for(int i=0;i<strlen(a);i++){
            
            if(a[i]>='A' && a[i]<='Z')printf("%c",map[a[i]-'A']+ ('A'-'a'));
            else if(a[i]>='a' && a[i]<='z')printf("%c",map[a[i]-'a']);
            else printf("%c",a[i]);
    }
    printf("\n");
   // system("pause");
    return 0;
}
