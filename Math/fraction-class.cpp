struct frac
{
    LL a , b;
    frac() { a = 0 , b = 1;}
    frac(LL _a , LL _b) {a = _a , b = _b;}
    void maintain()
    {
        long long G = __gcd(a , b);
        a /= G , b /= G;
        if (b < 0) a = -a , b = -b;
    }
    bool operator < (const frac& R) const{
        return a * R.b < b * R.a;
    }
    frac operator + (const frac& R) const{
        frac res(a * R.b + b * R.a , R.b * b);
        res.maintain();
        return res;
    }
    frac operator - (const frac& R) const{
        frac res(a * R.b - b * R.a , R.b * b);
        res.maintain();
        return res;
    }
    frac operator * (const frac& R) const{
        frac res(a * R.a , R.b * b);
        res.maintain();
        return res;
    }
    frac operator / (const frac& R) const{
        frac res(a * R.b , R.a * b);
        res.maintain();
        return res;
    }
    frac& operator - ()
    {
        a = -a;
        return *this;
    }
    frac& operator ! ()
    {
        swap(a , b);
        if (b < 0) a = -a , b = -b;
        return *this;
    }
    LL operator = (LL R)
    {
        a = R , b = 1;
        return R;
    }
};
