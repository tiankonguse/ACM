#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

ifstream fin("puzzle.in");
ifstream fans("puzzle.out");

const int MAX = 25;

char name[100], word[100000+5][MAX], ans[MAX][MAX], map[MAX][MAX] = {0};
int tot;

int cmp(const void* e1, const void* e2) {
   return strcmp((const char*)e1, (const char*)e2);
}

main() {
   fin >> name;
   ifstream fw(name);
   int n, i, j;
   for (tot = 0; fw >> word[tot]; tot++)
      for (i = 0; i < strlen(word[tot]); i++)
         word[tot][i] = toupper(word[tot][i]);
   qsort(word, tot, sizeof(word[0]), cmp);

   fin >> n;
   for (i = 0; i < n; i++) {
      fans >> ans[i];
      if (fans.fail() || !bsearch(ans[i], word, tot, sizeof(word[0]), cmp)) {
         cout << "No" << endl;
         return 0;
      }
   }
   if (fans >> ans[n]) {
      cout << "No" << endl;
      return 0;
   }

   for (i = 0; i < n; i++)
      for (j = i + 1; j < n; j++)
         if (strcmp(ans[i], ans[j]) == 0) {
            cout << "No" << endl;
            return 0;
         }

   for (i = 0; i < n; i++) {
      int x0, y0, x1, y1, l;
      char sign;
      fin >> x0 >> y0 >> sign >> l;
      x1 = x0, y1 = y0;
      if (sign == 'A') x1 += l - 1;
      else y1 += l - 1;
      int x, y;
      for (x = x0; x <= x1; x++)
         for (y = y0; y <= y1; y++)
            if (map[x][y] && map[x][y] != ans[i][x - x0 + y - y0]) {
//               cout << x - x0 + y - y0 << endl;
//               cout << map[x][y] << ' ' << ans[i][x - x0 + y - y0] << endl;
//               cout << ans[i] << endl;
               cout << "No" << endl;
               return 0;
            }
            else map[x][y] = ans[i][x - x0 + y - y0];
   }

   cout << "Yes" << endl;

   return 0;
}