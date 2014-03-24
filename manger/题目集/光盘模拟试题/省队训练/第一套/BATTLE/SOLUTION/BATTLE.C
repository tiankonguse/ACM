/*
  CTU Open Contest 2002
  =====================
  Sample solution for the problem: battle

  Jan Cada, Oct 2002
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum { SEA=0, NEWSHIP, ENDSHIP, ISSHIP };

int main()
{
 while(1)
    {
      int R, C, r, c, II;
      char *lastrow, *row;
      II=0;
      scanf( "%d%d\n", &R, &C);
      if(R==0) break;
      lastrow = (char*) malloc(C+10);
      row     = (char*) malloc(C+10);
      memset( lastrow, '.', C);
      for( r=0; r<R; ++r) 
	{
          char *tmp;
          int laststate = SEA;
          int actualstate;
	  gets(row); 
	  /* /          printf("%s\n%s\n", lastrow, row); */
          if(II == -1) continue;
	  for( c=0; c<C; ++c)
	    {
	      actualstate = (lastrow[c]=='#'?2:0) + (row[c]=='#'?1:0);
	      /* //	      printf("[%d,%d]<%d,%d,%d>{%d,%d}\n", r, c, laststate, actualstate, II, lastrow[c], row[c] ); */
	      if(actualstate && laststate && (actualstate!=laststate))
		{ II = -1; break; }
	      else if((actualstate == NEWSHIP)&&(laststate == SEA))
                II++; 
	      laststate = actualstate;
	    }
          tmp = lastrow; lastrow = row; row = tmp; /* // swap buffers */
	}
      free(row);
      free(lastrow);
      if( II == -1) 
       printf("Bad placement.\n");
      else 
       printf("There are %d ships.\n",II);
    }
  return 0;
}

