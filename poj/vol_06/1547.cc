#include"iostream"
#include"string"
#include"algorithm"
using namespace std;
struct child{
   string s;
   int v;
}ch[10];
int cmp(child a,child b){
    return a.v>b.v;
}
int main(){
    int N,a,b,c;
    string s,s1,s2;
    while(cin>>N){
       if(N==-1)break;
       for(int i=0;i<N;i++){
           cin>>a>>b>>c>>s;
           ch[i].v=a*b*c;
           ch[i].s=s;
       }
       sort(ch,ch+N,cmp);
       cout<<ch[0].s<<" took clay from "<<ch[N-1].s<<"."<<endl;
    }
    return 0;
}
