#include"iostream"
#include"stack"
using namespace std;
int main(){
    stack<int> s;
    s.push(0);
    int N,M,a,b;
    long c=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
            cin>>a>>b;
            if(b>s.top()){
                s.push(b);  
            }
            else if(b<s.top()){
                 while(b<s.top()){
                    s.pop();
                    c++;

                    if(s.top()==0)break;
                 }
                 if(b!=s.top()){
                                s.push(b);
                 }
            }
    }
    while(s.top()!=0){
                      s.pop();
                      c++;
    }
    cout<<c<<endl;
}

