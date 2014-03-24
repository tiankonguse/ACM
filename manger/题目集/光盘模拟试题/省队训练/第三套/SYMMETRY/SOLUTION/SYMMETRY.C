/*
  CTU Open Contest 2002
  =====================
  Sample solution for the problem: symmetry

  Pavel Kos, Oct 2002
*/


#include <stdio.h>
#include <stdlib.h>


#define MAX_COUNT 100000

typedef int Point[2];

Point points[MAX_COUNT];


int compare(const void * a, const void * b) {
   const Point * aa = (const Point *)a, * bb = (const Point *)b;

   if ((*aa)[0] < (*bb)[0]) return -1;
   else if ((*aa)[0] > (*bb)[0]) return 1;
   else if ((*aa)[1] > (*bb)[1]) return -1;
   else if ((*aa)[1] < (*bb)[1]) return 1;
   else return 0;
}

void test(int count, int xx, int yy) {
   int i = (count + 1)/2;

   while (i--) {
      if ((points[i][0] + points[count - i - 1][0] != xx) ||
            (points[i][1] + points[count - i - 1][1] != yy)) {
         printf("This is a dangerous situation!\n");
         return;
      }
   }
   printf("V.I.P. should stay at ("%.1f,%.1f").\n", xx/2.0, yy/2.0);
}

int main(void) {
   int n, i, x1, x2, xx, y1, y2, yy;

   for (;;) {
      scanf("%d", &n);
      if (!n) break;
      for (i = 0; i < n; ++i) {
         scanf("%d%d", &xx, &yy);
         if (i == 0) {
            y1 = y2 = yy;
         } else {
            if (yy < y1) y1 = yy;
            if (yy > y2) y2 = yy;
         }
         points[i][0] = xx;
         points[i][1] = yy;
      }
      qsort(points, n, sizeof(Point), compare);
      x1 = points[0][0];
      x2 = points[n - 1][0];
      xx = x1 + x2;
      yy = y1 + y2;
      test(n, xx, yy);
   }
   return 0;
}
