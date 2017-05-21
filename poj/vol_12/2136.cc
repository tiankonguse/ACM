#include"iostream"
using namespace std;
int al[26];
void print(int n){
    int p=-1;
    for(int i=0;i<26;i++){
       if(al[i]>=n){
          for(int j=0;j<p;j++)printf(" ");
          p=0;
          if(i==0)printf("*");
          else printf(" *");
       }
       else p+=2;
    }  
    printf("\n");
}
int main(){
    char c;
    int max=0;
    while(~scanf(" %c",&c)){
       if(c>='A' && c<='Z'){
          al[c-'A']++;
          if(al[c-'A']>max)max=al[c-'A'];
       }
    }
    for(int i=max;i>0;i--)
    print(i);
    for(int i=0;i<26;i++){
       if(i==25)printf("%c\n",i+'A');
       else printf("%c ",i+'A');
    }
    //system("pause");
    return 0;
}
