#include"iostream"
#include"string"
using namespace std;
int high[100],low[100];
int main(){
    string s1,s;
    bool flag;
    int n,ch=0,cl=0;
    while(cin>>n,n){
        cin>>s1>>s;
        if(s=="high"){
           high[ch++]=n;
        }
        else if(s=="low"){
           low[cl++]=n;
        }
        else{
           flag=true;
           for(int i=0;i<ch;i++){
              if(n>=high[i]){
                flag=false;
                break;
              }
           }
           if(flag){
            for(int i=0;i<cl;i++){
              if(n<=low[i]){
                flag=false;
                break;
              }
            }
           }
           if(flag)printf("Stan may be honest\n");
           else printf("Stan is dishonest\n");
           ch=cl=0;
        }
    }
    return 0;
}
