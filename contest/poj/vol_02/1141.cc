#include"iostream"
#include"string"
using namespace std;
char str[101];
int state[101][101];
string ans[101][101];
int N;
int main(){
    scanf("%s",str);
    N=strlen(str);
    for(int i=0;i<N;i++){
        state[i][i]=2;
        if(str[i]=='('||str[i]==')')ans[i][i]="()";
        else ans[i][i]="[]";
    }
    for(int j=1;j<N;j++){
        for(int i=0;i+j<N;i++){
            state[i][i+j]=10000;
            for(int k=i;k<i+j;k++){
                if(state[i][k]+state[k+1][i+j]<state[i][i+j]){
                     state[i][i+j]=state[i][k]+state[k+1][i+j];
                     ans[i][i+j]=ans[i][k]+ans[k+1][i+j];
                }
            }
            if((str[i]=='('&&str[i+j]==')') ||(str[i]=='['&&str[i+j]==']')){
                if(state[i][i+j]>state[i+1][i+j-1]+2){
                   state[i][i+j]=state[i+1][i+j-1]+2;
                   ans[i][i+j]=str[i]+ans[i+1][i+j-1]+str[i+j];
                }
            }
        }
    }
    cout<<ans[0][N-1]<<endl;
   // system("pause");
    return 0;
}
