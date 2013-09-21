/*************************************************************************
    > File Name: B.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 18:58:21
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

//typedef long long myLL;
//int n;
//myLL str[1];
//myLL mygcd(myLL a,myLL b) {
//    if(b==0)return a;
//    return mygcd(b,a%b);
//}
//
//myLL myeuler(myLL x) {
////    int i;
//    myLL res=x;
////    myLL _max = (myLL)(sqrt(x*1.0)+1);
//    for(int i=2; i*i<=x; i+= (i==2)?1:2) {
//        if(x%i==0) {
//            res = res/i*(i-1);
//            while(x%i==0)x/=i;
//        }
//    }
//    if(x>1)res = res/x*(x-1);
//    return res;
//}
//
//myLL myf(myLL x,myLL y,myLL p) {
//
//    myLL a=1,b=x%p;
//    if(p<=2||x<2)return x;
//    while(y) {
//        if(y&1)a=a*b%p;
//        y>>=1;
//        b=b*b%p;
//    }
//    return a;
//}
//
////abc mod m = abc mod n mod m, where n = φ(m)
//
//
//myLL myget(int pos,myLL mod) {
//    if(pos == n)return 1;
//    myLL tmp = mod/mygcd(str[pos],mod);
//    tmp = myget(pos+1,myeuler(tmp));
//    //cout<<pos<<" "<<tmp<<" "<<mod<<endl;
//    return myf(str[pos],tmp,mod);
//}

int main() {
        int t,n,m,k,tmp,mm;
        cin>>t;
        while(t--){
            cin>>n>>mm;
            m=mm;
            while(m--){
                cin>>k;
                while(k--){
                    cin>>tmp;
                }
            }
//            cout<<(mm&1?"Ferrero":"Eleonora")<<endl;
            cout<<"Eleonora"<<endl;
        }
    return 0;
}
