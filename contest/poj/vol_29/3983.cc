#include "cstdio"
#include"cstdlib"
#include"cstring"
#include"iostream"
const int N = 4;
#define eps 1E-6
inline float abs(float x) { return x >= 0.0 ? x : -x; }
template <class T, int N> class STACK {
   protected:
      T a[N];
      int  n;
   public:
      STACK( ) { reset( ); }
      void reset( ) { n = 0; }
      void push(T x) { if(n < N) a[n++] = x;}
      T pop( ) { if(n > 0) return a[--n];}
};

const char opr[ ] = "+-*/";
int a[N];
STACK<float, N> opnstk;

int b[N], K = 0;

const char stkmode[5][22] = {
//   "n#n#n#n = a1b2c3d",
   "nnnn### = a3(b2(c1d))",
   "nnn#n## = a3((b1c)2d)",
   "nnn##n# = (a2(b1c))3d",
   "nn#nn## = (a1b)3(c2d)",
   "nn#n#n# = ((a1b)2c)3d",
};

void gen24( )
{
   bool calc(float, char, float, float&);
   int i, jn, jo, p0, p1, p2;
   char enumopr[3], op;
   float a1, a2, c;
   const char *p;


   for(i = 0; i < 5; ++i)

   for(p0 = 0; p0 < 4; ++p0) { enumopr[0] = opr[p0];
   for(p1 = 0; p1 < 4; ++p1) { enumopr[1] = opr[p1];
   for(p2 = 0; p2 < 4; ++p2) { enumopr[2] = opr[p2];

      opnstk.reset( );

      for(jn = jo = 0, p = stkmode[i]; *p != ' '; ++p) switch(*p) {
         case 'n':
            opnstk.push(b[jn++]); break;

         case '#':
            a2 = opnstk.pop( ); a1 = opnstk.pop( ); op = enumopr[jo++];
            if(calc(a1, op, a2, c)) opnstk.push(c); else goto loc_1;
         }

      if(abs(c - 24) < eps) {
         while(*++p != 0) switch(*p) {
            case '(':
            case ')':
               putchar(*p);
               break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
               printf("%d", b[*p - 'a']);
               break;
            case '1':
            case '2':
            case '3':
               printf("%c", enumopr[*p - '1']);
               break;
            }
         putchar('\n');
         goto loc_2;
         }

      loc_1: continue;
      }}}

   loc_2: return;
}

bool calc(float a, char op, float b, float& c)
{
   static bool bRet;

   switch(bRet = true, op) {
      case '+':  c = a + b;  break;
      case '-':  c = a - b;  break;
      case '*':  c = a * b;  break;
      case '/':
      if(abs(b) > eps) c = a / b;  else bRet = false;
      }

   return bRet;
}

int main( )
{

      for(int i = 0; i < N; ++i) scanf("%d", &b[i]);

      K = 0; gen24();


   loc_0: return 0;
}
