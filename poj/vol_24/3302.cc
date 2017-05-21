#include"iostream"
using namespace std;
bool check(char *a,char *b,int l1,int l2){
    int p1=0,p2=0;
    for(p1=0;p1<l1;p1++){
       if(a[p1]==b[p2])p2++;
       if(p2==l2)return true;
    }
    return false;
}
int main(){
    int N,l1,l2;
    char a[200],b[200],br[200];
    scanf("%d",&N);
    while(N--){
       scanf(" %s%s",a,b);
       l1=strlen(a);
       l2=strlen(b);
       for(int i=0;i<l2;i++){
          br[i]=b[l2-i-1];
       }
       if(check(a,b,l1,l2) || check(a,br,l1,l2))printf("YES\n");
       else printf("NO\n");
    }
    return 0;
}
