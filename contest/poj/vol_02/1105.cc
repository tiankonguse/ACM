#include"iostream"
using namespace std;
char str[20],ter[200];
int num[10];
int data[8]={1,2,4,8,16,32,64,128};
int main(){
    int n,m,c=1;
    while(scanf("%d",&n)&&n){
       printf("S-Tree #%d:\n",c++);
       for(int i=0;i<n;i++){
          scanf(" %s",str);
          num[str[1]-'0']=n-i-1;
       }
       scanf(" %s",ter);
       scanf("%d",&m);
       while(m--){
          scanf(" %s",str);
          int cnt=0;
          for(int i=0;i<n;i++){
             if(str[i]=='1'){
                cnt+=data[num[i+1]];
             }
          }
          printf("%c",ter[cnt]);
       }
       printf("\n\n");
    }
    return 0;
}
