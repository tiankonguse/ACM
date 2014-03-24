#include <stdio.h>
/* by Michal Koucky */
/*  
    O(n^2 * log n) solution
    Take each point and try all direction from it, sort them ...

    Program supposes that no two points have the same positions
*/


int x[1024],y[1024];    /* x,y coordinate */
int n;                  /* number of points */

typedef struct{int x,y;} TYPE;

TYPE dir[1024];       /* direction of points */


/*** sorting ****/

/*
    sort(TYPE *pole,int n);    
   
      setridi pole[0]..pole[n-1] podle velikosti

      pro porovnani se pouziva makro isGE(i,j)

      pokud je potreba tridit obracene -> #define isGE  .. <= ..

      typ pole udava TYPE

*/

TYPE *spol;   /* pomocna promenna - tridene pole */
int sn;       /* aktualni pocet tridenych prvku */


#define isGE(i,j)     (((spol[i].x*spol[j].y>=spol[j].x*spol[i].y) && spol[j].y)||!spol[i].y)    /* funkce provede porovnani i>=j  */
#define swapx(i,j)    { int pom=spol[i].x;spol[i].x=spol[j].x;spol[j].x=pom; \
                            pom=spol[i].y;spol[i].y=spol[j].y;spol[j].y=pom; }


void down(int i)
{
    int vetsi, j;

    while(1){

       j = i << 1;
       if(j > sn) return;
       if(j+1 > sn) vetsi=1;
       else vetsi = isGE(j,j+1);

       if(vetsi) if isGE(i,j) return; else { swapx(j,i); i=j; }
       else if(isGE(i,j+1)) return; else { swapx(j+1,i); i=j+1; }
    }
}

void sort(TYPE *pole, int n)
{
   int i;

   spol = pole - 1;     /* spol = pole;  iff tridime pole[1]..pole[n] */
   sn = n;

   for(i=sn; --i; ) down(i);      /* pozn: down(sn) nema smysl -> tedy se 0 */
   for(; sn>1;){

       swapx(1,sn);
       sn--;
       down(1);
   }
}

/*** end of sort ***/


int solve()
/* solves one solution */
/* returns max */
{
    int i,m;
    int max=2;

    while(n>2){

        n--;
        for(i=n;i--;)
          {
             dir[i].x = x[n]-x[i];
             dir[i].y = y[n]-y[i];

             if(dir[i].y<0){            /* normalize */
                  dir[i].x=-dir[i].x;
                  dir[i].y=-dir[i].y;
             }

/*if(!dir[i].x && !dir[i].y)printf("!");  - two same points */
          }

        sort(dir,n);

        m=2;

        for(i=n-1;i--;)       /* find longest common part */
          if(dir[i].x*dir[i+1].y==dir[i+1].x*dir[i].y)m++;
          else{  
             if(m>max)max=m;
             m=2;
          }

        if(m>max)max=m;

    }

    return max;

}


int main()
{
    int i; 
	while(1)
	{

            scanf("%d",&n);
            if(!n)return 0;
            for(i=n;i--;)scanf("%d%d",&(x[i]),&(y[i]));
            printf("%i\n",solve());

	}
}	/* main */


