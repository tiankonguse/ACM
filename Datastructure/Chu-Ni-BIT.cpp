struct CHU_2_BIT
{
    int n;
    LL B[N] , C[N];
    void init(int size) {
        n = size;
        memset(B , 0 , sizeof(B));
        memset(C , 0 , sizeof(C));
    }
    CHU_2_BIT() {}
    CHU_2_BIT(int size) {
        init(size);
    }
    void _add(LL* c , int x , LL w) {
        for ( ; x <= n ; x += x & -x)
            c[x] += w;
    }
    LL _sum(LL* c , int x) {
        LL res = 0;
        for ( ; x > 0 ; x -= x & -x)
            res += c[x];
        return res;
    }
    void add(int l , int r , LL w) {
        _add(B , l , w) , _add(B , r + 1 , -w);
        _add(C , l , w * l) , _add(C , r + 1 , -w * (r + 1));
    }
    LL sum(int l , int r) {
        LL res = 0;
        res += (r + 1) * _sum(B , r) - l * _sum(B , l - 1);
        res -= _sum(C , r) - _sum(C , l - 1);
        return res;
    }
}T;
