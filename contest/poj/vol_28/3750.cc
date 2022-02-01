#include"iostream"
#include"string"
using namespace std;
char str[65][20];
bool used[65];
int main(){
    int N,w,s;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
       scanf("%s",str[i]);
    }
    scanf("%d,%d",&w,&s);
    int f=(w+s-2)%N;
    cout<<str[f]<<endl;
    used[f]=true;
    int j;
    for(int i=1;i<N;i++){
       j=s;
       while(j){
          f++;
          if(used[f%N])continue;
          j--;
       }
       cout<<str[f%N]<<endl;
       used[f%N]=true;
    }
  //  system("pause");
    return 0;
}
