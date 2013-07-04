//Graham扫描法求凸包,算法参照<算法导论>-P585
#include<iostream>
#include<vector>
#include <cmath>
#include <string>
#include<algorithm>
using namespace std;

class point {
public:
    int no, x, y;
    double theta;
    point(){};
    point(int n, int i, int j):no(n),x(i),y(j){};
};
point p0;
vector<point> qQ;

//向量叉积判定p1p2在点p1处是向左转还是向右转
bool nonleft_turn(point p0, point p1, point p2)
{
    int xa = p1.x-p0.x,  ya = p1.y-p0.y,
        xb = p2.x-p1.x,  yb = p2.y-p1.y;
    if (!(xa*yb - xb*ya < 0))
        return true;//nonleft-turn
    else     
        return false;//left-turn
}
//按坐标比较
bool coordinate_cmp(const point& a, const point& b)
{
    if (a.y == b.y) return (a.x < b.x);
    else    return (a.y < b.y);    
}

//相对与p0的极角比较
bool polor_angle_cmp1(const point& p1, const point& p2)
{ 
    if (p1.theta == p2.theta)//极角相同,极半径降序
        return (p1.x*p1.x + p1.y*p1.y) > (p2.x*p2.x + p2.y*p2.y);
    else
        return (p1.theta < p2.theta);
}

bool polor_angle_cmp2(const point& p1, const point& p2)
{ 
    return (p1.theta == p2.theta); //极角相同
}

vector<point> graham_scan(vector<point> Q)
{
    int i, num = Q.size(); //i-循环变量;num-点集大小
    int idxTop;
    vector<int> s(num);

    sort(Q.begin(), Q.end(), coordinate_cmp);    
    p0 = Q[0];//p0为最下方最靠左边的点
    
    //方便计算相对于p0的极角,转换成相对p0的坐标
    for (i = 0; i < num; ++i) {
        Q[i].x -= p0.x,   Q[i].y -= p0.y;
        Q[i].theta = atan2(1.0*Q[i].y, 1.0*Q[i].x);
     }

    //按相对与p0的极角排序, 极角相同则按极半径排序
    sort(Q.begin()+1, Q.end(), polor_angle_cmp1);
    //去除相对p0极角相同的点中极半径较小的那些点
    vector<point>::iterator itr = unique(Q.begin()+1, Q.end(), polor_angle_cmp2);
    if (itr != Q.end()) {
        Q.erase(itr, Q.end());
        num = Q.size();//更新点集大小
    }

    idxTop = -1;    
    s[++idxTop] = 0;    
    s[++idxTop] = 1;
    s[++idxTop] = 2;

    for (i = 3; i <= num-1; ++i) {
        while (nonleft_turn(Q[s[idxTop-1]],Q[s[idxTop]],Q[i]) == false) {
            --idxTop;
        }
        s[++idxTop] = i;
    }
    
    //将结果整理至凸包集合CH[Q]并作为返回值
    vector<point> CH(idxTop+1); //最后求得的凸包CH[Q]
    for (i = 0; i <= idxTop; ++i) {
        CH[i].no = Q[s[i]].no;
        CH[i].x  = Q[s[i]].x + p0.x;
        CH[i].y  = Q[s[i]].y + p0.y;
    }
    return CH;

}
//简单图形显示输入点的位置分布示意
void print_graph()
{
    short graph[40][25];    
    int x, y;
    memset(graph, 0 ,40*25*sizeof(short));
    for (x = 0; x < qQ.size(); ++x)
        graph[39-qQ[x].y][qQ[x].x] = qQ[x].no+10;
    
    cout<<string(75, '-')<<endl;
    for (x = 0; x <= 39; ++x) {
        for (y = 0; y <= 24; ++y)
            if (graph[x][y] >= 10) 
                printf("%c%-2d", '.', graph[x][y]-10 );
            else 
                printf("   ");
            cout<<endl;
    }
    cout<<string(75, '-')<<endl;  
}

int main()
{
    //////////////////////////////////////////////////////////////////////////
    //数据输入
    freopen("testdata.txt", "r", stdin);
    int no = -1, x, y;
    while (cin>>x>>y) {
        qQ.push_back(point(++no, x, y));
    }
    //////////////////////////////////////////////////////////////////////////
    //输出点的位置
     print_graph();
  
    //求凸包
    vector<point> CH = graham_scan(qQ);

    //输出凸包集合中的点
    cout<<"求得的凸包集合中的顶点(逆时针方向)依次为:"<<endl;
    for (int i = 0; i < CH.size(); ++i) {
        printf("P%-2d:(%2d,%2d)\n", CH[i].no, CH[i].x, CH[i].y);
    }
    //////////////////////////////////////////////////////////////////////////
    
    system("pause");
    return 0;
}

