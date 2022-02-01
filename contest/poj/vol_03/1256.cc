#include"iostream"
#include"algorithm"
using namespace std;
bool cmp(char a,char b){
     return tolower(a) == tolower(b) ? a < b : tolower(a) < tolower(b);
}

int main(){
    int N,l;
    char a[20];
    scanf("%d",&N);
    while(N--){
               scanf(" %s",a);
               l=strlen(a);
               sort(a,a+l,cmp);
               printf("%s\n",a);
               while(next_permutation(a,a+l,cmp)){
                  printf("%s\n",a);
               }    
    }
   // system("pause");
    return 0;
}
