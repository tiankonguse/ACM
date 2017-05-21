#include"iostream"
#include"string"
#include"cstdlib"
using namespace std;
int wei[12];
string l1,l2,l3,r1,r2,r3,a1,a2,a3;
bool check(){
    int l,r;
    l=r=0;
    for(int i=0;i<l1.length();i++)l+=wei[l1[i]-'A'];
    for(int i=0;i<r1.length();i++)r+=wei[r1[i]-'A'];
    if(a1=="even" && l!=r)return false;
    if(a1=="up" && l<=r)return false;
    if(a1=="down" && l>=r)return false;
    
    l=r=0;
    for(int i=0;i<l2.length();i++)l+=wei[l2[i]-'A'];
    for(int i=0;i<r2.length();i++)r+=wei[r2[i]-'A'];
    if(a2=="even" && l!=r)return false;
    if(a2=="up" && l<=r)return false;
    if(a2=="down" && l>=r)return false;
    
    l=r=0;
    for(int i=0;i<l3.length();i++)l+=wei[l3[i]-'A'];
    for(int i=0;i<r3.length();i++)r+=wei[r3[i]-'A'];
    if(a3=="even" && l!=r)return false;
    if(a3=="up" && l<=r)return false;
    if(a3=="down" && l>=r)return false;
    
    return true;
}
int main(){
    int T,res;
    char c;
    cin>>T;
    while(T--){
        cin>>l1>>r1>>a1>>l2>>r2>>a2>>l3>>r3>>a3;
        memset(wei,0,sizeof(wei));
        for(int i=0;i<12;i++){
            wei[i]=-1;
            if(check()){
                res=i;
                break;
            }
            wei[i]=1;
            if(check()){
                res=i;
                break;
            }
            wei[i]=0;
        }
        c=res+'A';
        if(wei[res]<0)
         cout<<c<<" is the counterfeit coin and it is light."<<endl;
        else
         cout<<c<<" is the counterfeit coin and it is heavy."<<endl;
    }
  //  system("pause");
    return 0;
}
