#include <fstream.h>
#include <string.h>
#include <ctype.h>

ifstream fin("e.in");
//#define fin cin

const int MAXL = 65537 * 2 + 1, pv[10] = {9711, 1237, 6537, 1231, 2173, 7691, 9991, 7321, 5761, 8767};

const int MAX = 25;

struct point {
   int x, y;
};

int n, pos[MAX][MAX], tot, ord[MAX];
point p1[MAX], p2[MAX];
int map[MAX][MAX];
char wmap[MAX][MAX], name[MAX], word[100000+5][10+5], used[100000+5];

struct hnode {
   char word[11];
   int id;
   hnode* next;
};

hnode* hash[20][MAXL] = {0};

void insert(char word[], int ord, int id) {
   int i, v = 0, l = strlen(word);
   for (i = 0; i < l; i++)
      if (pos[id][i + 1])
         v = (v + word[i] * pv[i]) % MAXL * pv[i] % MAXL;
   v = (v * 2047 + l) % MAXL;
   hnode* op = new hnode;
   strcpy(op->word, word);
   op->id = ord;
   op->next = hash[id][v];
   hash[id][v] = op;
}

hnode* find(point p1, point p2, int id) {
   int i, j, k, v = 0, l = p2.x - p1.x + p2.y - p1.y + 1;
   for (i = p1.x; i <= p2.x; i++)
      for (j = p1.y; j <= p2.y; j++)
         if (pos[id][k = i - p1.x + j - p1.y + 1])
           v = (v + wmap[i][j] * pv[k - 1]) % MAXL * pv[k - 1] % MAXL;
   v = (v * 2047 + l) % MAXL;
   return hash[id][v];
}



void in();
void create();



int sol;
char ans[MAX][10+5];

void search(int lev) {
   if (lev == n) {
      sol = 1;
      return;
   }

   hnode* op = find(p1[lev], p2[lev], lev);
   int i, j, k, ok;
   for (; op; op = op->next) {
      if (used[op->id]) continue;
      if ((int)strlen(op->word) != p2[lev].x - p1[lev].x + p2[lev].y - p1[lev].y + 1) continue;
      ok = 1;
      for (i = p1[lev].x; ok && i <= p2[lev].x; i++)
         for (j = p1[lev].y; j <= p2[lev].y; j++)
            if (pos[lev][k = i - p1[lev].x + j - p1[lev].y + 1])
               if (wmap[i][j] != op->word[k - 1]) {
                  ok = 0;
                  break;
            }
	
      if (ok) {
         for (i = p1[lev].x; ok && i <= p2[lev].x; i++)
            for (j = p1[lev].y; j <= p2[lev].y; j++)
               wmap[i][j] = op->word[i - p1[lev].x + j - p1[lev].y];
         strcpy(ans[lev], op->word);
         used[op->id] = 1;
         search(lev + 1);
         if (sol) return;
         used[op->id] = 0;
      }
   }
}



main() {
   in();
   create();

   memset(used, 0, sizeof(used));
   sol = 0;
   search(0);

//   if (sol == 0) cout << "No solution" << endl;

   int i, j;
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         if (ord[j] == i) {
            cout << ans[j] << endl;
            break;
         }

   return 0;
}

void in() {
   fin.getline(name, 100);
   ifstream fw(name);
   tot = 0;
   char cword[30];
   for (; fw >> cword;)
      if (strlen(cword) <= 10) {
         int i;
         for (i = 0; i < strlen(cword); i++)
            cword[i] = toupper(cword[i]);
         strcpy(word[tot++], cword);
      }

   fin >> n;
   int i, j;
   for (i = 0; i < n; i++) {
      ord[i] = i;
      fin >> p1[i].x >> p1[i].y; p2[i] = p1[i];
      char sign; fin >> sign >> j;
      if (sign == 'A') p2[i].x += j - 1;
      else p2[i].y += j - 1;
   }
}

void create() {
   memset(map, 0, sizeof(map));
   memset(pos, 0, sizeof(pos));
   int i, j, k, c;
   for (c = 0; c < n; c++) {
      int max = -1, id;
      for (i = c; i < n; i++) {
         int tot = 0;
         for (j = p1[i].x; j <= p2[i].x; j++)
            for (k = p1[i].y; k <= p2[i].y; k++)
               if (map[j][k])
                  tot++;
         if (tot > max) max = tot, id = i;
      }
      point tmp;
      tmp = p1[id], p1[id] = p1[c], p1[c] = tmp;
      tmp = p2[id], p2[id] = p2[c], p2[c] = tmp;
      i = ord[id], ord[id] = ord[c], ord[c] = i;
      i = c;

      pos[i][0] = p2[i].x - p1[i].x + p2[i].y - p1[i].y + 1;

      for (j = p1[i].x; j <= p2[i].x; j++)
         for (k = p1[i].y; k <= p2[i].y; k++) {
            if (map[j][k]) pos[i][j - p1[i].x + k - p1[i].y + 1] = 1;
            map[j][k] = 1;
         }

      for (j = 0; j < tot; j++)
         if (pos[i][0] == (int)strlen(word[j]))
            insert(word[j], j, i);
   }
}