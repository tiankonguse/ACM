#include"iostream"
#include"cstdio"
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int main(){
    bool flag;
    char op;
    int c1,c2,d1,d2,l,g,h;
    while(~scanf("%d/%d%c%d/%d",&c1,&d1,&op,&c2,&d2)){
        l=lcm(d1,d2);
        c1*=l/d1;
        c2*=l/d2;
        if(op=='+')g=c1+c2;
        else g=c1-c2;
        if(g<0){flag=true;g=-g;}
        else flag=false;
        h=gcd(g,l);
        g/=h;
        l/=h;
        if(flag)printf("-");
        if(l==1)printf("%d\n",g);
        else printf("%d/%d\n",g,l);
    }
    return 0;
}
