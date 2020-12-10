// 计算几何(基础) By 猛犸也钻地 @ 2013.09.11

#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/* ---------------------------- 注意事项 ---------------------------- //

1.命名约定
    圆：圆心在u，一般情况下半径r大于等于0
    直线：经过点u和v的直线，u不重合于v
    射线：起点在u，途经点v，u不重合于v
    线段：起点在u，终点在v，u不重合于v
    散点：点的可空集合，不存在重点
    简单多边形：至少有三个点，沿顺时针或逆时针排列，边不重合，图形不自交
    凸多边形：各内角均小于180度的多边形，意味着没有三点共线
    平面：由不共线的三点uvw所表示
  所有函数都会默认传入的参数已满足上面的命名约定

2.误差处理
  一种处理方式是，在比较运算之前，如果存在加减法
  则直接对加减运算之前的数字进行比较，以避开(大数-大数)>EPS的情况出现
  如果担心误差影响到后继的计算，可以用cmp函数代替加减运算，以修正误差
  另外必须注意的是，在给定义域有限的函数传递参数时(比如asin等)
  必须进行参数修正，否则传入1.0000000001这类数值时就会出现NAN

// -------------------- 下面这些部分基本都会用到 -------------------- */

typedef double NUM; // 整数几何：typedef long long NUM;
// 因为浮点比较时用的是相对误差，所以EPS不要放得太宽
const NUM EPS = 1e-12, MAGIC = 2.71828e18, PI = acos(-1);

inline NUM sqr(NUM a){return a*a;}
inline NUM cmp(NUM a, NUM b){
    return (1+fabs(a))*EPS<fabs(a-b)?a-b:0; // 整数几何：return a-b;
}

struct VEC {NUM x,y;} NOVEC = {MAGIC,MAGIC}; // 二维向量或坐标
struct RAY {VEC u,v;} NORAY = {NOVEC,NOVEC}; // 二维直线、射线或线段
struct CIR {VEC u; NUM r;} NOCIR = {NOVEC,MAGIC}; // 二维圆

inline NUM sqr(const VEC& a){return sqr(a.x)+sqr(a.y);}
inline NUM abs(const VEC& a){return sqrt(sqr(a));}
inline NUM cmp(const VEC& a, const VEC& b){
    NUM at=cmp(a.x,b.x);
    return !at?cmp(a.y,b.y):at;
}

inline VEC operator *(NUM u, const VEC& a){return (VEC){a.x*u,a.y*u};}
inline VEC operator *(const VEC& a, NUM u){return (VEC){a.x*u,a.y*u};}
inline VEC operator /(const VEC& a, NUM u){return (VEC){a.x/u,a.y/u};}
inline VEC operator +(const VEC& a, const VEC& b){
    return (VEC){a.x+b.x,a.y+b.y};
}
inline VEC operator -(const VEC& a, const VEC& b){
    return (VEC){a.x-b.x,a.y-b.y};
}
inline NUM operator *(const VEC& a, const VEC& b){
    return cmp(a.x*b.y,+a.y*b.x); // 带误差修正的叉积运算
}
inline NUM operator %(const VEC& a, const VEC& b){
    return cmp(a.x*b.x,-a.y*b.y); // 带误差修正的点积运算
}

// ----------------- 下面这些部分根据题目选择性使用 ----------------- //

// 将非零向量a的长度缩放至u单位
// a绕坐标原点，逆时针旋转90度
// a绕坐标原点，逆时针旋转u弧度
VEC resize(const VEC& a, NUM u){return u/abs(a)*a;}
VEC rotate(const VEC& a){return (VEC){-a.y,a.x};}
VEC rotate(const VEC& a, NUM u){
    return (VEC){a.x*cos(u)-a.y*sin(u)
                ,a.x*sin(u)+a.y*cos(u)};
}

// 求向量a在向量b上的投影
// 求点在直线上的投影(到直线的最近点)
// 求点在圆周上的投影(到圆周的最近点)
// 判断点在直线上的投影点，能否落在线段上
VEC project(const VEC& a, const VEC& b){return a%b/sqr(b)*b;}
VEC project(const VEC& p, const RAY& l){
    VEC o=l.v-l.u;
    return (p-l.u)%o/sqr(o)*o+l.u;
}
VEC project(const VEC& p, const CIR& c){
    if(!cmp(p,c.u)) return NOVEC;
    return resize(p-c.u,c.r)+c.u;
}
int segment(const VEC& p, const RAY& l){
    return (p-l.u)%(p-l.v)<=0;
}

// 求点p相对于原点o的所在象限
int quadrant(const VEC& p, const VEC& o){
    NUM dx=cmp(p.x,o.x);
    NUM dy=cmp(p.y,o.y);
    if(dx>0 && dy>=0) return 1;
    if(dx<=0 && dy>0) return 2;
    if(dx<0 && dy<=0) return 3;
    if(dx>=0 && dy<0) return 4;
    return 0; // 返回0表示在原点处
}

// 位置排序，首先按照在正方向o上的投影长度，其次按照o上的投影高度排序
// 极角排序，首先按照[0,360)内的角度大小，其次按照距离原点o的远近排序
struct PosCmp {
    VEC o;
    PosCmp(const VEC& o = (VEC){1,0}):o(o){}
    bool operator ()(const VEC& l, const VEC& r) const {
        NUM s=cmp(l%o,r%o);
        if(!s) s=cmp(l*o,r*o);
        return s<0;
    }
};
struct AngCmp {
    VEC o;
    AngCmp(const VEC& o = (VEC){0,0}):o(o){}
    bool operator ()(const VEC& l, const VEC& r) const {
        int u=quadrant(l,o);
        int v=quadrant(r,o);
        if(u!=v) return u<v;
        NUM s=(r-o)*(l-o);
        if(!s) s=cmp(sqr(l-o),sqr(r-o));
        return s<0;
    }
};

// 求两直线的交点
// 求直线与圆的交点，交线段的方向与原先直线方向相同
// 求两圆相交的交点，交线段的端点u和v分别在圆心a到b连线方向的左侧和右侧
VEC intersect(const RAY& a, const RAY& b){
    VEC t=a.u-a.v,s=b.u-b.v;
    NUM o=s*t;
    if(!o) return NOVEC;
    return a.u+(a.u-b.u)*s/o*t;
}
RAY intersect(const RAY& l, const CIR& c){
    VEC s=project(c.u,l);
    NUM o=cmp(sqr(c.r),sqr(s-c.u));
    if(o<0) return NORAY;
    VEC t=resize(l.v-l.u,sqrt(o));
    return (RAY){s-t,s+t};
}
RAY intersect(const CIR& a, const CIR& b){
    NUM l=sqr(a.u-b.u);
    NUM w=(1+(sqr(a.r)-sqr(b.r))/l)*0.5;
    NUM o=cmp(sqr(a.r)/l,sqr(w));
    if(o<0) return NORAY;
    VEC t=rotate(a.u-b.u)*sqrt(o);
    VEC s=a.u-w*(a.u-b.u);
    return (RAY){s-t,s+t};
}

// 判断点和线的位置关系，在直线外为0，直线上为1，线段内为2
// 判断点和圆的位置关系，在圆外部为0，圆周上为1，圆内部为2
// 判断点和简单多边形的位置关系，外部为0，边上为1，内部为2
int relation(const VEC& p, const RAY& l){
    if((p-l.u)*(p-l.v)) return 0;
    return (p-l.u)%(p-l.v)>0?1:2;
}
int relation(const VEC& p, const CIR& c){
    NUM o=cmp(sqr(c.r),sqr(c.u-p));
    return o<=0?o?0:1:2;
}
int relation(const VEC& p, const vector<VEC>& u){
    int n=u.size(),ret=0;
    for(int i=0,j=n-1;i<n;j=i++){
        VEC s=u[i]-p,t=u[j]-p;
        NUM l=cmp(u[i].x,p.x);
        NUM r=cmp(u[j].x,p.x),o=s*t;
        if(!o && s%t<=0) return 1;
        if((o>0 && l<=0 && r>0)
        || (o<0 && r<=0 && l>0)) ret^=2;
    }
    return ret;
}

// 由直线构造方程ax+by+c=0
// 由方程ax+by+c=0构造直线
// 由直径上的两点构造一个圆
// 由三角形的顶点构造外接圆
// 由散点构造一个最小覆盖圆，复杂度O(n)
pair<pair<NUM,NUM>,NUM> make_line(const RAY& l){
    NUM a=-l.u.y+l.v.y;
    NUM b=+l.u.x-l.v.x;
    NUM c=-l.u.x*a-l.u.y*b;
    return make_pair(make_pair(a,b),c);
}
RAY make_line(NUM a, NUM b, NUM c){
    if(!cmp(a,0) && !cmp(b,0)) return NORAY;
    if(!cmp(a,0)) return (RAY){{0,-c/b},{1,-c/b}};
    if(!cmp(b,0)) return (RAY){{-c/a,0},{-c/a,1}};
    return (RAY){{0,-c/b},{-c/a,0}};
}
CIR make_circle(const VEC& a, const VEC& b){
    return (CIR){(a+b)/2,abs(a-b)/2};
}
CIR make_circle(const VEC& a, const VEC& b, const VEC& c){
    NUM x=(c-b)%(a-c),y=(c-b)*(a-b);
    if(!y) return NOCIR;
    VEC m=(a+b)/2+x/y/2*rotate(a-b);
    return (CIR){m,abs(a-m)};
}
CIR min_covering_circle(vector<VEC> u){
    random_shuffle(u.begin(),u.end());
    int n=u.size(),i,j,k,z=1%n;
    CIR ret;
    for(ret=make_circle(u[0],u[z]),i=2;i<n;i++) if(!relation(u[i],ret))
    for(ret=make_circle(u[0],u[i]),j=1;j<i;j++) if(!relation(u[j],ret))
    for(ret=make_circle(u[i],u[j]),k=0;k<j;k++) if(!relation(u[k],ret))
        ret=make_circle(u[i],u[j],u[k]);
    return ret;
}

// 求三点的内切圆
// 求点到圆的两个切点，切点u和v分别在点到圆心连线方向的左侧和右侧
// 求两圆的两条公切线，切线段的方向与圆心a到b连线方向相同，位于左右两侧
//     默认是外公切线，若将其中的一个圆半径设为负数，则求出的是内公切线
CIR tangent_circle(const VEC& a, const VEC& b, const VEC& c){
    if((a-b)*(a-c)==0) return NOCIR;
    NUM x=abs(b-c),y=abs(c-a),z=abs(a-b);
    VEC m=(a*x+b*y+c*z)/(x+y+z);
    return (CIR){m,fabs((m-a)*(a-b)*1.0/z)};
}
RAY tangent(const VEC& p, const CIR& c){
    NUM l=sqr(p-c.u),e=cmp(l,sqr(c.r));
    if(e<0) return NORAY;
    NUM x=c.r/l,y=sqrt(e)/l;
    VEC s=p-c.u,t=rotate(s);
    RAY lr={c.u+c.r*(x*s-y*t),
            c.u+c.r*(x*s+y*t)};
    return lr;
}
pair<RAY,RAY> tangent(const CIR& a, const CIR& b){
    NUM o=a.r-b.r,l=sqr(a.u-b.u),e=cmp(l,sqr(o));
    if(e<0) return make_pair(NORAY,NORAY);
    NUM x=o/l,y=sqrt(e)/l;
    VEC s=b.u-a.u,t=rotate(s);
    RAY ll={a.u+a.r*(x*s+y*t),
            b.u+b.r*(x*s+y*t)};
    RAY rr={a.u+a.r*(x*s-y*t),
            b.u+b.r*(x*s-y*t)};
    return make_pair(ll,rr);
}
