#include <iostream>
#include <string>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    string s;
    char c;
    int sum=0,t;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='X')sum+=10;
        else if(s[i]>='0' && s[i]<='9') sum+=(s[i]-'0')*(10-i);
        else t=10-i;
    }
    int res=-1;
    for(int i=0;i<=9;i++){
        if((t*i+sum)%11==0)res=i;
    }
    if(res==-1 && t==1 && (sum+10)%11==0)printf("X\n");
    else printf("%d\n",res);
    return 0;
}
