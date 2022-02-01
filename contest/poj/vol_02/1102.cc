#include"iostream"
using namespace std;
int num[10][5]={{1,4,0,4,1},
                {0,3,0,3,0},
                {1,3,1,2,1},
                {1,3,1,3,1},
                {0,4,1,3,0},
                {1,2,1,3,1},
                {1,2,1,4,1},
                {1,3,0,3,0},
                {1,4,1,4,1},
                {1,4,1,3,1}};
void print(int n,int size,int k){
   int i;
   switch(n){
       case 0:if(!k)return;
              for(i=0;i<size+2;i++)printf(" ");
              break;
       case 1:printf(" ");
              for(i=0;i<size;i++)printf("-");
              if(!k)return;
              printf(" ");
              break;
       case 2:printf("|");
              if(!k)return;
              for(i=0;i<size+1;i++)printf(" ");
              break;
       case 3:for(i=0;i<size+1;i++)printf(" ");
              printf("|");
              break;
       case 4:printf("|");
              for(i=0;i<size;i++)printf(" ");
              printf("|");
              break;
   }
}
int main(){
    int size,len;
    char s[11];
    while(scanf("%d %s",&size,s) && size){
       len=strlen(s);
       for(int i=0;i<len;i++){
               print(num[s[i]-'0'][0],size,len-i-1);
               if(i!=len-1)printf(" ");
       }
       printf("\n");
       for(int i=0;i<size;i++){
          for(int j=0;j<len;j++){
               print(num[s[j]-'0'][1],size,len-j-1);
               if(j!=len-1)printf(" ");
          }
           printf("\n");
       }
       for(int i=0;i<len;i++){
               print(num[s[i]-'0'][2],size,len-i-1);
               if(i!=len-1)printf(" ");
       }
       printf("\n");
       for(int i=0;i<size;i++){
          for(int j=0;j<len;j++){
               print(num[s[j]-'0'][3],size,len-j-1);
               if(j!=len-1)printf(" ");
          }
           printf("\n");
       }
       for(int i=0;i<len;i++){
               print(num[s[i]-'0'][4],size,len-i-1);
               if(i!=len-1)printf(" ");
       }
       printf("\n\n");
    }
    return 0;
}
