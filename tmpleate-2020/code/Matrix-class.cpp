struct Matrix
{
    int n , m ;
    double a[N][N];
    Matrix() {memset(a , 0 , sizeof(a));}
    Matrix(int _n , int _m) {
        n = _n , m = _m , memset(a , 0 , sizeof(a));
    };
    double* operator[] (int i) {
        return a[i];
    }
};
Matrix operator * (Matrix A , Matrix B)
{
    Matrix ans(A.n , B.m);
    for (int i = 0 ; i < A.n ; ++ i)
        for (int j = 0 ; j < A.m ; ++ j)
            for (int k = 0 ; k < B.m ; ++ k)
                ans[i][k] += A[i][j] * B[j][k];
    return ans;
}
