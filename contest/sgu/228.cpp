#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
#define N 25
double eps = 1e-6;
struct point
{
  double x , y;
  void input()
  {
    scanf("%lf%lf",&x, &y);
  }
  void print()
  {
    printf("%f %f\n", x, y);
  }
  point (double x = 0 , double y = 0): x(x) , y(y) {};
}p[N];
point operator + (point a , point b) { return point(a.x + b.x , a.y + b.y);}
point operator - (point a , point b) { return point(a.x - b.x , a.y - b.y);}
point operator * (double k , point b) { return point(k * b.x , k * b.y);}
double Cross(point a , point b) {return a.x * b.y - a.y * b.x;}
double length(point a) {return sqrt(a.x * a.x + a.y * a.y);}
double dis(point a , point b) {return length(a - b);}
const double pi = acos(-1.0);
bool operator < (point a , point b)
{
  if (abs(a.x - b.x) < eps)
    return a.y < b.y;
  return a.x < b.x;
}

point rotate(point v , double q)
{
  return point(cos(q)*v.x - sin(q)*v.y , sin(q)*v.x + cos(q)*v.y);
}

int n , na , nb; double theta;
point A , B;

void work()
{
  scanf("%d%d%d",&n,&na,&nb);
  if (na < nb)
    A.input() , B.input();
  else B.input() , A.input() , swap(na , nb);
  theta = pi * (nb - na) / (double)n;
  point vec = B - A;
  vec = (0.5 / sin(theta)) * rotate(vec , -pi/2 + theta) + A;
  A = A - vec;
  A = rotate(A , 2 * pi * na / (double)n);
  for (int i = 1 ; i <= n ; ++ i)
  {
    A = rotate(A , -2 * pi / (double)n);
    (A + vec).print();
  }
}

int main()
{
  freopen("1.txt" , "r" , stdin);
    work();
  return 0;
}

