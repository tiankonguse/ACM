// 扩展欧几里德/逆元/解模线性方程(组) By 猛犸也钻地 @ 2012.01.28

// std::algorithm里自带最大公约数函数__gcd(a,b)
// 扩展欧几里德，求一组x和y，满足ax+by=gcd(a,b)
int exgcd(int a, int b, int& x, int& y){
    if(!b) return x=1,y=0,a;
    int u=exgcd(b,a%b,y,x);
    return y-=a/b*x,u;
}

// 求x在模m下的乘法逆元，须保证gcd(x,m)==1，否则不存在逆元
int inverse(int x, int m){
    int r,v;
    return exgcd(x,m,r,v)==1?(r+m)%m:0;
}

// 求线性方程ax+by=c的一组解
bool equation(int a, int b, int c, int &x, int &y){
    int r=exgcd(a,b,x,y);
    if(c%r) return false;
    x*=c/r; y*=c/r;
    return true;
}

// 求满足同余方程组x%m[i]=r[i]的最小的非负整数解x，返回-1说明无解
int equation(int n, int m[], int r[]){
    int ans=0,lcm=1,x,y;
    for(int i=0;i<n;i++){
        int g=exgcd(lcm,m[i],x,y);
        if((r[i]-ans)%g || r[i]>=m[i]) return -1;
        x*=(r[i]-ans)/g; y=m[i]/g;
        ans+=(x%y+y)%y*lcm;
        ans%=lcm*=y;
    }
    return ans;
}
