#include"iostream"
#include"stack"
using namespace std;
bool used[27];
char str[1024];
int main(){
    int N,cnt,d,w;
    while(scanf("%d",&N)&&N){
       memset(used,false,sizeof(used));
       scanf(" %s",str);
       cnt=w=0;
       for(int i=0;str[i];i++){
          d=str[i]-'A';
          if(!used[d]){
             if(cnt==N)w++;
             else{
                 used[d]=true;
                 cnt++;
             }
          }
          else{
              cnt--;
              used[d]=false;
          }
       }
       if(w==0)printf("All customers tanned successfully.\n");
       else printf("%d customer(s) walked away.\n",w/2);
    }
    return 0;
}
