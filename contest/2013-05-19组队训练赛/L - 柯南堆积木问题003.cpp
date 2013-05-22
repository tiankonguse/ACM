#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned char status;
typedef long long ll;

const int maxn = 256, mod = 1000000007;
const status mask = 0B11111111;

template <class T>
struct Matrix {
    int size;
    T* t;
    Matrix() {
        size = -1;
    }
    Matrix(int n) {
        size = n;
        t = new T[n*n];
        fill(t, t + size * size, T(0));
    }
    Matrix(const Matrix<T>& a) {
        size = a.size;
        t = new T[size*size];
        copy(a.t, a.t + size * size, t);
    }
    ~Matrix() {
        if(size != -1)
            delete t;
    }
    Matrix<T>& resize(int n) {
        if(size != -1)
            delete t;
        size = n;
        t = new T[n*n];
        fill(t, t + size * size, T(0));
    }
    T* operator[](int row) {
        return t + row * size;
    }
    Matrix<T>& operator = (const Matrix<T>& a) {
        if(size != -1)
            delete t;
        size = a.size;
        t = new T[size*size];
        copy(a.t, a.t + size * size, t);
    }
    Matrix<T> operator *(Matrix<T>& b)  {
        Matrix<T> c(size), &a = *this;
        for(int k = 0; k < size; k++) {
            for(int i = 0; i < size; i++) {
                if((*this)[i][k] == T(0))continue;
                for(int j = 0; j < size; j++) {
                    c[i][j] += a[i][k] * b[k][j];
                    if(c[i][j] >= mod)c[i][j] %= mod;//mod 运算，正常的模板没有
                }
            }
        }
        return c;
    }
    Matrix<T> operator ^(int pow) {
        Matrix<T> tmp(*this), res(size);
        for(int i = 0; i < size; i++)
            res[i][i] = 1;
        for(; pow; pow >>= 1) {
            if(1 & pow) {
                res = res * tmp;
            }
            tmp = tmp * tmp;
        }
        return res;
    }
    void print() {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                printf("%lld ", (*this)[i][j]);
            }
            puts("");
        }
    }
};

bool check(status s) {
    if(s == mask || s == 0B00000000)return true;
    int x = s << 8 | s, cnt, i, j;
    while(x & 0B00000001)x >>= 1;
    for(i = 0; i < 8; i++) {
        if(x&(1 << i)) {
            for(j = i; j < 8 && (x&(1 << j)); j++);
            if((j - i) & 1)return false; //奇数个1
            i = j - 1;
        }
    }
    return true;
}
struct Index{
    int size,index,*t;
    Index(int n){
        t=new int[n];
        size=n;
        fill(t,t+size,-1);
        index=0;
    }
    inline int operator[](int x){
        if(x>size){puts("error");return -1;}//error
        if(t[x]==-1)t[x]=index++;
        return t[x];
    }
};

Matrix<ll> base(70);

bool visited[maxn];
Index idx(maxn);
status legal[maxn];

void dfs(status s) {
    visited[s] = true;
    status r = ~s,next=0B00000000; //这次为0的地方，下次必须为1
    for(;;){
        if((next & r) == r && check(next & s)) { //对于下次必须为1的地方，都有1
            base[idx[next]][idx[s]]++;//这种转移方式数+1
            if(!visited[next])//没访问过
                dfs(next);//访问下个状态
        }
        if(next==mask)break;
        next++;
    }
}

void init() {
    status next = 0B00000000;
    fill(visited, visited + maxn, false);
    dfs(mask);
    base[idx[mask]][idx[mask]]++;//对于初始状态全部1的，转移有两种，而dfs只会得到一种
}


int main() {
    init();
    //scanf("%*d");
    int n,cs=1;
    while(~scanf("%d", &n)) {
        Matrix<ll> c;
        c = base ^ n;
    //  printf("Case %d: ",cs++);
        printf("%lld\n", c[idx[mask]][idx[mask]]);
    }
    return 0;
}
