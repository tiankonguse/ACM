#include"iostream"
#include"cstdlib"
#include"string"
using namespace std;
int num[10];
string change(string a){
    int l,len=a.length();
    string re="";
    char t[10];
    char c;
    memset(num,0,sizeof(num));
    for(int i=0;i<len;i++){
        c=a[i];
        num[c-'0']++;
    }
    for(int i=0;i<=9;i++){
       if(num[i]){
          sprintf(t,"%d", num[i]*10+i);
          re+=t;
       }
    }
    return re;
}
string loop[16];
bool flag;
int main(){
    int time;
    while(cin>>loop[0]){
       if(loop[0]=="-1")break;
       time=0;
       while(++time){
           loop[time]=change(loop[time-1]);
           if(loop[time]==loop[time-1]){
              if(time==1)cout<<loop[0]<<" is self-inventorying"<<endl;
              else cout<<loop[0]<<" is self-inventorying after "<<time-1<<" steps"<<endl;
              break;
           }
           else{
              flag=false;
              for(int i=time-2;i>=0;i--){
                 if(loop[time]==loop[i]){
                     cout<<loop[0]<<" enters an inventory loop of length "<<time-i<<endl;
                     flag=true;
                     break; 
                 }
              }
              if(flag)break;
           }
           if(time==15){
              cout<<loop[0]<<" can not be classified after 15 iterations"<<endl;
              break;
           }
       }
    }
    return 0;
}
