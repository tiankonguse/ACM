// 模运算下的整数类 By 猛犸也钻地 @ 2012.10.31

class Imp {
public:
    static const int MOD = 1000000007;
    typedef long long LL;
    int u;
    Imp(){};    // 以下所有函数的传入参数都必须在[0,MOD)之间
    Imp(int v):u(v){}   // 且运算符左侧类型必须是Imp
    operator int&(){return u;}
    operator const int&() const {return u;}
    Imp operator +(int v) const {return u+v<MOD?u+v:u+v-MOD;}
    Imp operator -(int v) const {return u<v?u-v+MOD:u-v;}
    Imp operator *(int v) const {return u*LL(v)%MOD;}
    Imp operator /(int v) const {return u*RR(v)%MOD;}
    Imp operator -() const {return u?MOD-u:0;}
    Imp& operator +=(int v){u+=u+v<MOD?v:v-MOD; return *this;}
    Imp& operator -=(int v){u-=u<v?v-MOD:v; return *this;}
    Imp& operator *=(int v){u=u*LL(v)%MOD; return *this;}
    Imp& operator /=(int v){u=u*RR(v)%MOD; return *this;}
    static LL RR(int x){
        return x>1?RR(MOD%x)*(MOD-MOD/x)%MOD:x;
    }
};
