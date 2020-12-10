// 大整数类 By 猛犸也钻地 @ 2011.11.24

#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

class BigNum {
public:
    static const int MOD = 100000000;
    static const int BIT = 8, SIZE = 105;
    mutable int n,o;
    long long u[SIZE];
    BigNum(){}
    BigNum(const string& s){
        memset(this,0,sizeof(BigNum));
        int num=0,cnt=1;
        for(int i=s.size()-1;~i;i--){
            if(s[i]=='-') o^=1;
            if(s[i]>='0' && s[i]<='9'){
                num+=(s[i]-'0')*cnt;
                cnt*=10;
                if(cnt==MOD) u[n++]=num,num=0,cnt=1;
            }
        }
        if(!n || cnt>=10) u[n++]=num;
        if(!u[0] && n==1) o=0;
    }
    BigNum(long long x){
        memset(this,0,sizeof(BigNum));
        if(x<0) o=1,x=-x;
        do u[n++]=x%MOD; while(x/=MOD);
    }
    operator string() const {
        static char s[SIZE*BIT+10];
        char* c=s+sprintf(s,"%s%d",o?"-":"",int(u[n-1]));
        for(int i=n-2;~i;i--) c+=sprintf(c,"%0*d",BIT,int(u[i]));
        return s;
    }
    int operator [](int pos) const {
        static int e[BIT]={1};
        for(static int i=1;i<BIT;i++) e[i]=e[i-1]*10;
        return u[pos/BIT]/e[pos%BIT]%10;
    }
    int length() const {
        int ret=(n-1)*BIT+1;
        for(int x=u[n-1]/10;x;x/=10) ret++;
        return ret;
    }
    friend int cmp(const BigNum& l, const BigNum& r){
        if(l.o!=r.o) return (l.o?-1:1);
        if(l.n!=r.n) return (l.o?-1:1)*(l.n-r.n);
        for(int i=l.n-1;~i;i--) if(l.u[i]-r.u[i])
                return (l.o?-1:1)*(l.u[i]-r.u[i]);
        return 0;
    }
    // 运算符
    bool operator < (const BigNum& r) const {return cmp(*this,r)<0;}
    bool operator > (const BigNum& r) const {return cmp(*this,r)>0;}
    bool operator <=(const BigNum& r) const {return cmp(*this,r)<=0;}
    bool operator >=(const BigNum& r) const {return cmp(*this,r)>=0;}
    bool operator ==(const BigNum& r) const {return cmp(*this,r)==0;}
    bool operator !=(const BigNum& r) const {return cmp(*this,r)!=0;}
    BigNum operator +(const BigNum& r) const {return BigNum(*this)+=r;}
    BigNum operator -(const BigNum& r) const {return BigNum(*this)-=r;}
    BigNum operator *(int x) const {return BigNum(*this)*=x;}
    BigNum operator /(int x) const {return BigNum(*this)/=x;}
    BigNum& operator *=(const BigNum& r){return *this=*this*r;}
    BigNum& operator /=(const BigNum& r){return *this=*this/r;}
    BigNum& operator %=(const BigNum& r){return *this=*this%r;}
    BigNum& operator %=(int x){return *this=*this%x;}
    BigNum operator -() const {
        BigNum s=*this;
        if(s.u[0] || s.n>=2) s.o^=1;
        return s;
    }
    BigNum& operator +=(const BigNum& r){
        if(r.n==1 && !r.u[0]) return *this;
        if(r.o^o) return r.o^=1,*this-=r,r.o^=1,*this;
        if(r.n>n) n=r.n;
        for(int i=0;i<r.n;i++) u[i]+=r.u[i];
        for(int i=0;i<n;i++) if(u[i]>=MOD) u[i+1]++,u[i]-=MOD;
        if(u[n]) n++;
        return *this;
    }
    BigNum& operator -=(const BigNum& r){
        if(r.n==1 && !r.u[0]) return *this;
        if(r.o^o) return r.o^=1,*this+=r,r.o^=1,*this;
        if(cmp(*this,r)*(r.o?-1:1)<0){
            o^=1,n=r.n;
            for(int i=0;i<r.n;i++) u[i]=r.u[i]-u[i];
        }else{
            for(int i=0;i<r.n;i++) u[i]=u[i]-r.u[i];
        }
        for(int i=0;i<n;i++) if(u[i]<0) u[i+1]--,u[i]+=MOD;
        while(!u[n-1] && n>=2) --n;
        if(!u[0] && n==1) o=0;
        return *this;
    }
    BigNum operator *(const BigNum& r) const {
        BigNum s=0;
        if(!u[n-1] || !r.u[r.n-1]) return s;
        s.n=r.n+n-1;
        s.o=r.o^o;
        for(int i=0;i<n;i++) for(int j=0;j<r.n;j++)
            s.u[i+j]+=u[i]*r.u[j];
        for(int i=0;i<s.n;i++) if(s.u[i]>=MOD){
            s.u[i+1]+=s.u[i]/MOD;
            s.u[i]%=MOD;
            if(i==s.n-1) s.n++;
        }
        return s;
    }
    BigNum operator /(const BigNum& r) const {
        BigNum e[35],s=0,c=0;
        int m=0,ro=r.o,lo=o;
        r.o^=ro,o^=lo;
        for(e[m]=r;MOD>>++m;e[m]=e[m-1]+e[m-1]);
        for(int i=n-1;~i;i--){
            int tag=0;
            (s*=MOD)+=u[i];
            for(int x=m-1;~x;x--) if(s>=e[x]) s-=e[x],tag|=1<<x;
            (c*=MOD)+=tag;
        }
        r.o^=ro,o^=lo;
        if(c.u[0] || c.n>=2) c.o=r.o^o;
        return c;
    }
    BigNum operator %(const BigNum& r) const {
        BigNum e[35],s=0;
        int m=0,ro=r.o,lo=o;
        r.o^=ro,o^=lo;
        for(e[m]=r;MOD>>++m;e[m]=e[m-1]+e[m-1]);
        for(int i=n-1;~i;i--){
            (s*=MOD)+=u[i];
            for(int x=m-1;~x;x--) if(s>=e[x]) s-=e[x];
        }
        r.o^=ro,o^=lo;
        if(s.u[0] || s.n>=2) s.o=o;
        return s;
    }
    BigNum& operator *=(int x){
        if(!x) return *this=0;
        if(x<0) o^=1,x=-x;
        for(int i=0;i<n;i++) u[i]*=x;
        for(int i=0;i<n;i++) if(u[i]>=MOD){
            u[i+1]+=u[i]/MOD;
            u[i]%=MOD;
            if(i==n-1) n++;
        }
        if(!u[0] && n==1) o=0;
        return *this;
    }
    BigNum& operator /=(int x){
        if(x<0) o^=1,x=-x;
        for(int i=n-1;i;u[i--]/=x) u[i-1]+=u[i]%x*MOD;
        for(u[0]/=x;n>=2;n--) if(u[n-1]) break;
        if(!u[0] && n==1) o=0;
        return *this;
    }
    int operator %(int x) const {
        long long c=0;
        for(int i=n-1;~i;i--) c=(c*MOD+u[i])%x;
        return (1-o-o)*int(c);
    }
};
