/*# Start of file merge.c */

/*# MIPSMARK 1.0 1/5/98 Copyright 1998 J. Waldron. */

/*  	Write a C function to merge 2 arrays, assumed to be ordered by ascending values,
	and store the result in a 3rd array, so it in turn is ordered. 
    Follow the function prototype given above the cut line.
	Put your entire function between thge cut lines	*/
/*# Output format must be:		*/
/*# "/-1/1/2/2/3/4/7/8/11"		*/
#include <stdio.h>       /* for printf in C programs */
#include <stdlib.h>	 /* for exit() in C programs */


#define LEN1	4
#define LEN2	5

int* merge (const int[], int , const int[], int); //allocates and returns an arrray

int main() {
  int a[LEN1] = {1,2,3,8};
  int b[LEN2] = {-1,2,4,7,11};
  int* m;	// to hold pointer to merged arrayy,  should free
  int* mp;	// point to successive result elements

  m = merge( a, LEN1, b, LEN2);
  mp = m;
  for (int i=0; i<LEN1+LEN2; i++)
     printf ("/%d",*mp++);
  free(m);
  printf("\n");
  return 0;
}

  
/* Any changes above this line will be discarded by
 mipsmark. Put your answer between dashed lines. */
/*-------------- start cut ----------------------- */

/*  Student's Name: 	*/

int* merge (const int a[], int lenA, const int b[], int lenB) { //allocates and returns an arrray
  int *counter;
  int z;
  int x;
  int y;

  /* Allocating memory for counter */
  counter = (int *) malloc((lenA + lenB) * sizeof(int));

  z = 0;
  x = 0;
  y = 0;

 // Merging
  while (z < lenA && x < lenB) {
    if (a[z] < b[x]) {	// if element a < element b, append
      counter[y++] = a[z++];
    } else {
      counter[y++] = b[x++];
    }
  }

  while (z < lenA) { // if there are remianing elements in a 
    counter[y++] = a[z++];
  }

  while (x < lenB) { // if there are remianing elements in b
    counter[y++] = b[x++];
  }
  
  return counter; // counter = merged array
}

/*--------------  end cut  -----------------------
# Any changes below this line will be discarded by
# mipsmark. Put your answer between dashed lines.

   End of file merge.c		*/
