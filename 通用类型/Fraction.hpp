// 分数类 By 猛犸也钻地 @ 2011.11.25

#include <utility>
#include <algorithm>
using namespace std;
using namespace rel_ops;

template <class VAL = long long> class Frac {
public:
    VAL num,den;
    Frac(){}
    Frac(const VAL& x, const VAL& y = 1){
        den=__gcd(x,y);
        num=x/den,den=y/den;
        if(den<0) num=-num,den=-den;
    }
    bool operator <(const Frac& rhs) const {
        return num*rhs.den<rhs.num*den;
    }
    bool operator==(const Frac& rhs) const {
        return num==rhs.num && den==rhs.den;
    }
    Frac operator +(const Frac& rhs) const {
        return Frac(num*rhs.den+den*rhs.num,den*rhs.den);
    }
    Frac operator -(const Frac& rhs) const {
        return Frac(num*rhs.den-den*rhs.num,den*rhs.den);
    }
    Frac operator *(const Frac& rhs) const {
        return Frac(num*rhs.num,den*rhs.den);
    }
    Frac operator /(const Frac& rhs) const {
        return Frac(num*rhs.den,den*rhs.num);
    }
    Frac operator -() const {return Frac(-num,den);}
    Frac& operator +=(const Frac& rhs){return *this=*this+rhs;}
    Frac& operator -=(const Frac& rhs){return *this=*this-rhs;}
    Frac& operator *=(const Frac& rhs){return *this=*this*rhs;}
    Frac& operator /=(const Frac& rhs){return *this=*this/rhs;}
};
