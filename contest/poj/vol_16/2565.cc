#include"iostream"
#include"iomanip"
#include"string"
using namespace std;
int main(){
    int N,id;
    double S,t;
    string s;
    cin>>N>>S;
    while(cin>>id){
        t=0;
        int flag=0;
        for(int i=0;i<N;i++){
                cin>>s;
                if(s[0]=='-'){
                    flag=1;
                   continue;
                }
                t+=(s[0]-48)*3600+(s[2]-48)*600+(s[3]-48)*60+(s[5]-48)*10+s[6]-48;
        }
        if(flag){
                 printf("%3d: -\n",id);
                 continue;
        }
        t/=S;
        int se=(int)(t+0.5);
        int m=se/60;
        se%=60;
        cout<<setw(3)<<id<<": "<<m<<":";
        if(se<10)
            cout<<0<<se<<" min/km"<<endl;
        else
            cout<<se<<" min/km"<<endl;
        

        /*
        char ses[3]={'0','0','\0'};
        sprintf(ses,"%d",se);
        if(se/10==0) {ses[1]='0';}
        printf("%3d:%2d:%s min/km\n",id,m,ses);
        */
    }    
    
    return 0;
}
