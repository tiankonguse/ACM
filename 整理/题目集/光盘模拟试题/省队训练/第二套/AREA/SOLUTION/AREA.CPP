#include <fstream.h>

ifstream fin("c.in");
#define fin cin

struct point {
   int x, y;
};

int cross(point p1, point p2) {
   return p1.x * p2.y - p1.y * p2.x;
}

const int MAX = 100+5;

int n;
point p[MAX];

main() {
   fin >> n;
   int i;
   for (i = 0; i < n; i++)
      fin >> p[i].x >> p[i].y;
   p[n] = p[0];

   int area = 0;
   for (i = 0; i < n; i++)
      area += cross(p[i], p[i + 1]);

   cout << area / 2 << endl;

   return 0;
}