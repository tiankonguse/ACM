#include"iostream"
#include"string"
#include"cmath"
using namespace std;
int main(){
    int T,l1,l2,l3,k,s,max,a,b;
    char c;
    string s0,s1,s2,s3;
    cin>>T;
    for(int i=1;i<=T;i++){
            cin>>s1>>s2;
            l1=s1.length();
            l2=s2.length();
            s0="";
            s3="";
            for(int j=0;j<abs(l1-l2);j++){
                    s0+='0';
            }
            if(l1<l2){
                      max=l2;
                      s1=s0+s1;
            }
            else{
                 max=l1;
                 s2=s0+s2;
            }
            k=0;
            for(int j=max-1;j>=0;j--){
                    a=s1[j]-48;
                    b=s2[j]-48;
                    s=a+b+k;
                    if(s>=2){
                         s-=2;
                         k=1;
                    }
                    else{
                         k=0;
                    }
                    c=s+48;
                    s3=c+s3;
            }
            if(k==1)s3="1"+s3;
            l3=s3.length();
            for(int j=0;j<l3-1;j++){
                    if(s3[0]=='0')s3=s3.substr(1);
            }
              
            cout<<i<<" "<<s3<<endl;
    }
    system("pause");
    return 0;
}
