/*
  CTU Open Contest 2002
  =====================
  Sample solution for the problem: format

  from Mid-Central Europe Regional Contest, 1999
  Modified by: Martin Kacer, Oct 2002
*/

#include <stdio.h>

#define MAX_WIDTH 80 /* max width of the paragraph */
#define MAX_LENGTH 10000 /* max total length of all words of one paragraph */
#define MAX_WORDS MAX_LENGTH /* max number of words (worst case - 1 char words) */

#define IS_WORD_CHAR(C) (((C) >= 33) && ((C) <= 126))


int text[MAX_WORDS];
unsigned int badnesses[MAX_WORDS];

int badness(int width, int gaps, int chars) {
   int long_gaps, gap_size;

   if (gaps == 0)
      if (chars != width) return 500;
      else return 0;
   long_gaps = (width - chars)%gaps;
   gap_size = (width - chars)/gaps;
   return (gap_size - 1)*(gap_size - 1)*(gaps - long_gaps) +
         gap_size*gap_size*long_gaps;
}

int main(void) {
   int n, cnt, nl, wrd, i, j, sum, bd;
   char c;

   while (1) {
      scanf("%d", &n);
      if (n == 0) break;
      cnt = 0;
      nl = 0;
      wrd = 0;
      while (1) {
         c = getchar();
         if (c == '\n') {
            if (nl) break;
            nl = 1;
            if (wrd) {
               text[cnt++] = wrd;
               wrd = 0;
            }
         } else {
            nl = 0;
            if (IS_WORD_CHAR(c)) {
               ++wrd;
            } else if (wrd) {
               text[cnt++] = wrd;
               wrd = 0;
            }
         }
      }
      badnesses[0] = badness(n, 0, text[0]);
      i = 1;
      while (i < cnt) {
         badnesses[i] = (unsigned int)-1;
         j = i;
         sum = 0;
         while (j >= 0) {
            sum += text[j];
            if (sum + i - j > n) break;
            bd = badness(n, i - j, sum);
            --j;
				if (j >= 0) bd += badnesses[j];
            if (badnesses[i] > bd)
               badnesses[i] = bd;
         }
         ++i;
      }
      printf("Minimal badness is %d.\n", badnesses[cnt - 1]);
   }
   return 0;
}
