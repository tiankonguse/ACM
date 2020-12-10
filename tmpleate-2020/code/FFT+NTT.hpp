// 快速傅里叶变换(FFT)和数论变换(NTT) By 猛犸也钻地 @ 2014.04.02



// CF:
// http://codeforces.com/problemset/problem/286/E

// http://en.wikipedia.org/wiki/Fast_Fourier_transform


// 代码
// http://blog.csdn.net/pouy94/article/details/6784021

// Seter
// http://seter.is-programmer.com/posts/30349.html
// http://seter.is-programmer.com/posts/30953.html

// GAOA


#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
using namespace std;

template <typename T> int arrange(vector<T>& a){
    int n=a.size();
    for(int i=1,x=0,y=0;i<=n;i++){
        if(x>y) swap(a[x],a[y]);
        x^=i&-i;
        y^=n/(i&-i)>>1;
    }
    return n;
}

class FFT { // 快速傅里叶变换
public:
    typedef complex<double> complex_num;
    void fourier(vector<complex_num>& a, int o){ // 数组长度n必须是2的幂
        int n=arrange(a); // o是变换方向，+1为时域->频域，-1为频域->时域
        const double PI=acos(-1);
        for(int m=1;m<n;m+=m){
            complex_num w=1,e(cos(PI/m),sin(PI/m)*o);
            for(int x=0;x<n;w=1,x+=m+m)
            for(int y=0;y<m;y++,w*=e){
                complex_num t=w*a[x+y+m];
                a[x+y+m]=a[x+y]-t;
                a[x+y]+=t;
            }
        }
        if(o<0) for(int i=0;i<n;i++) a[i]/=n;
    }
    vector<int> convolution(const vector<int>& a, const vector<int>& b){
        int n=a.size(),m=b.size();
        int s=1<<(32-__builtin_clz(n+m-2)); // n+m必须大于等于2
        vector<complex_num> u(s),v(s);
        for(int i=0;i<n;i++) u[i]=a[i];
        for(int i=0;i<m;i++) v[i]=b[i];
        fourier(u,+1);
        fourier(v,+1);
        for(int i=0;i<s;i++) u[i]*=v[i];
        fourier(u,-1);
        vector<int> w(n+m-1);
        for(int i=0;i<n+m-1;i++) w[i]=int(u[i].real()+0.5);
        return w;
    }
};

class NTT { // 数论变换，能求模P下的精确卷积
public:     // 限制条件：P必须为素数，且存在整数k，使得P=n*k+1
    static const int P = 786433, G = 10;
    // G为原根，求原根的方法：暴力枚举寻找满足G^(P-1)=1的任意一个G
    int add(int x, int y){
        return x+y<P?x+y:x+y-P;
    }
    int pow(long long a, int e){
        int s=1%P;
        for(a=a%P;e;a=a*a%P,e>>=1)
            if(e&1) s=s*a%P;
        return s;
    }
    void fourier(vector<int>& a){ // 数组长度n必须是2的幂
        int n=arrange(a);
        for(int m=1;m<n;m+=m){
            int e=pow(G,(P-1)/m>>1);
            long long w=1;
            for(int x=0;x<n;w=1,x+=m+m)
            for(int y=0;y<m;y++,w=w*e%P){
                int t=w*a[x+y+m]%P;
                a[x+y+m]=add(a[x+y],P-t);
                a[x+y]=add(t,a[x+y]);
            }
        }
    }
    vector<int> convolution(const vector<int>& a, const vector<int>& b){
        int n=a.size(),m=b.size();
        int s=1<<(32-__builtin_clz(n+m-2)); // n+m必须大于等于2
        vector<int> u(s),v(s);
        for(int i=0;i<n;i++) u[i]=a[i];
        for(int i=0;i<m;i++) v[i]=b[i];
        fourier(u);
        fourier(v);
        long long inv=pow(s,P-2);
        for(int i=0;i<s;i++) u[i]=u[i]*inv%P*v[i]%P;
        reverse(u.begin()+1,u.end());
        fourier(u);
        u.erase(u.begin()+n+m-1,u.end());
        return u;
    }
};
