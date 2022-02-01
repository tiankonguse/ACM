#include"iostream"
#include"cmath"
#define Pi 3.14159265358979323846
using namespace std;
struct Circle
{
    double r,x,y;
} a,b;

double distanc(Circle n,Circle m)
{
    double dis=sqrt((n.x-m.x)*(n.x-m.x)+(n.y-m.y)*(n.y-m.y));
    return dis;
}
double Areaone(Circle &M)
{
    return M.r*M.r*Pi;
}

double Area(Circle A,Circle B)
{
    double area=0.0;
    Circle M=(A.r>B.r)?A:B;
    Circle N=(A.r>B.r)?B:A;
    double dis=distanc(M,N);
    if((dis<M.r+N.r)&&(dis>M.r-N.r))
    {
        double cosM1 = (M.r*M.r+dis*dis-N.r*N.r)/(2.0*M.r*dis);
        double cosN1 = (N.r*N.r+dis*dis-M.r*M.r)/(2.0*N.r*dis);
        double M1 = acos(cosM1); //弧度值
        double N1 = acos(cosN1);
        double TM =0.5*M.r*M.r*sin(2.0*M1); //三角形面积
        double TN =0.5*N.r*N.r*sin(2.0*N1);
        double FM =(M1/Pi)*Areaone(M); //扇形面积
        double FN =(N1/Pi)*Areaone(N);
        area=FM+FN-TM-TN;
    }
    else if(dis<=M.r-N.r)
    {
        area=Areaone(N);
    }
    return area;
}
int main()
{
    while(~scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&a.r,&b.x,&b.y,&b.r))
    {
        printf("%.3lf\n",Area(a,b));
    }
    return 0;
}
