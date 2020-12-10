// 矩阵类 By 猛犸也钻地 @ 2013.04.24

#include <cmath>
#include <algorithm>
using namespace std;

template <int R, int C, class VAL = double> class Matrix {
public:
    VAL u[R][C];
    VAL* operator [](int i){return u[i];}
    const VAL* operator [](int i) const {return u[i];}
    Matrix(){}
    Matrix(const VAL& x){
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) u[i][j]=0;
        for(int i=min(R,C)-1;~i;i--) u[i][i]=x;
    }
    // 乘法
    template <int T> Matrix<R,T,VAL>&
    operator*=(const Matrix<C,T,VAL>& rhs){return *this=*this*rhs;}
    template <int T> Matrix<R,T,VAL>
    operator *(const Matrix<C,T,VAL>& rhs) const {
        Matrix<R,T,VAL> ret(0);
        for(int i=0;i<R;i++) for(int k=0;k<C;k++)
            for(int j=0;j<T;j++) ret[i][j]+=u[i][k]*rhs[k][j];
        return ret;
    }
    // 快速幂
    Matrix<R,C,VAL> pow(long long e) const {
        Matrix<R,C,VAL> ret(1),m=*this;
        for(;e;m*=m,e>>=1) if(e&1) ret*=m;
        return ret;
    }
    // 加法、减法
    Matrix<R,C,VAL>& operator +=(const Matrix<R,C,VAL>& rhs){
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) u[i][j]+=rhs[i][j];
        return *this;
    }
    Matrix<R,C,VAL>& operator -=(const Matrix<R,C,VAL>& rhs){
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) u[i][j]-=rhs[i][j];
        return *this;
    }
    Matrix<R,C,VAL> operator +(const Matrix<R,C,VAL>& rhs) const {
        Matrix<R,C,VAL> ret;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++)
            ret[i][j]=u[i][j]+rhs[i][j];
        return ret;
    }
    Matrix<R,C,VAL> operator -(const Matrix<R,C,VAL>& rhs) const {
        Matrix<R,C,VAL> ret;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++)
            ret[i][j]=u[i][j]-rhs[i][j];
        return ret;
    }
    // 转置、取反
    Matrix<C,R,VAL> operator ~() const {
        Matrix<C,R,VAL> ret;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) ret[j][i]= u[i][j];
        return ret;
    }
    Matrix<R,C,VAL> operator -() const {
        Matrix<R,C,VAL> ret;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) ret[i][j]=-u[i][j];
        return ret;
    }
    // 传入系数矩阵src和伴随矩阵adj，使用行变换进行高斯消元
    // 返回矩阵的秩，如果需要行列式的值，可以传入额外的指针p
    template <int T> friend
    int guass(Matrix<R,C,VAL>& src, Matrix<R,T,VAL>& adj, VAL* p = 0){
        const double EPS=1e-8;
        int i,j,k,r,x=-1;
        VAL det=1,at;
        for(i=0;i<C;i++){
            for(j=r=x+1;j<R;j++)
                if(abs(src[r][i])<abs(src[j][i])) r=j;
            if(EPS>abs(src[r][i])) continue; else x++;
            det*=at=src[r][i];
            for(k=0;k<C;k++) swap(src[x][k],src[r][k]/=at);
            for(k=0;k<T;k++) swap(adj[x][k],adj[r][k]/=at);
            for(j=0;j<R;j++) if(x!=j){
                at=-src[j][i];
                for(k=0;k<C;k++) src[j][k]+=src[x][k]*at;
                for(k=0;k<T;k++) adj[j][k]+=adj[x][k]*at;
            }
        }
        if(p) *p=det;
        return x+1;
    }
    // 求逆，若返回的矩阵为零，则表示不存在逆矩阵
    Matrix<R,C,VAL> inv() const {
        Matrix<R,C,VAL> l=*this,r(1);
        if(max(R,C)!=guass(l,r)) return VAL(0);
        return r;
    }
    // 求行列式的值
    VAL det() const {
        VAL ret;
        Matrix<R,C,VAL> l=*this;
        Matrix<R,0,VAL> r;
        if(max(R,C)!=guass(l,r,&ret)) return 0;
        return ret;
    }
};
