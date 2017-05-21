#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
__int64 solve(__int64 x){
    __int64 p=2,res=1,cnt;
    for(;p<40000;p+=2){
        cnt=0;
        while(x%p==0){
            cnt++;
            x/=p;
        }
        res=res*(2*cnt+1);
        if(p==2)p=1;
        if(x==1)break;
    }
    if(x>1)res=res*3;
    return res/2+1;
}
int main(){
    int T;
    __int64 n;
    scanf("%d",&T);
    for(int sc=1;sc<=T;sc++){
        cin>>n;
        cout<<"Scenario #"<<sc<<":"<<endl;
        cout<<solve(n)<<endl<<endl;
    }
    return 0;
}
