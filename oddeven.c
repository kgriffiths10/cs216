/*# Start of file oddeven.c */

/*# MIPSMARK 1.0 1/5/98 Copyright 1998 J. Waldron. */

/*  write a function "rearrange" that will rearrange the numbers in an array,
	such that all the even numbers come first.
	You may assume that the array will contain both odd and even numbers.
    USE the function "swap" provided. It will exchange the two integer values 
	pointed to by its two arguments. 
	Use this in "rearrange" A goal is to minimize the number of swaps.
    write a function "firstodd" that will return the index of the first 
	odd number in an array
    write a function "sum" that will sum the numbers in an array

The main program will use these functions to print the sum of even numbers
	and the sum of odd numbers. Each group of numbers may appear in any order.
*/
/*# Output format must be:		*/
/*# "evens=20 odds=25"		*/
#include <stdio.h>       /* for printf in C programs */
#include <stdlib.h>	 /* for exit() in C programs */

#define LENGTH	9

void rearrange	(int a[], int length);  // use swap to put even numbers first
int  firstodd 	(const int a[], int length);  // return index of first odd number in a
int  sum	(const int a[], int length);  // sum the numbers in a

int swapcount = 0;		// initalized global

void swap(int* x,int* y)	// swap the values pointed to
{   int	temp = *x;
	*x = *y;
	*y = temp;
	swapcount++;		// count how many times called
}

int main() {
  int arr[LENGTH] = {1,2,3,4,5,6,7,8,9};
  int fo;	// index of first odd, also number of even elements

  rearrange (arr, LENGTH);     	// Student's work
  // show what the student did
  printf("---Your rearranged array---\n");
  for (int i=0; i< LENGTH; i++)
    printf("%d,",arr[i]);
  printf("\n---------------------------\n");
  
  fo = firstodd(arr, LENGTH);	// Student's work
  printf("---- firstodd returns %d ----\n", fo);

  printf("Did %d swaps\n", swapcount);
  printf("evens=%d odds=%d\n", sum(arr, fo), sum(arr+fo, LENGTH-fo));
  return 0;
}

  
/*-------------- start cut ----------------------- */

/*  Student's Name:				*/

int  lasteven   (const int a[], int length){
	for (int i = length-1; i>=0; i--){
		if (!(a[i] & 1)){					// if a[i] and 1, las bit is zero
			return i;
		}
	}
}

void rearrange(int a[], int length) {
    
    int i = firstodd (a,length);            //First left, odd number in an array
    int j = lasteven (a,length);            //First right, even number in an array
	
	while (i<j)                             
    {
        swap(a+i,a+j);                      //Swap first left odd and first right even numbers
         i= firstodd (a,length);            //First left (first) odd number in an array
         j= lasteven (a,length);            //First right (last) even number in an array
    }
}


int firstodd(const int a[], int length) {
    int i;
    for (i = 0; i < length; i++) {			// For i less than length
        if (a[i] & 1)						// if a[i] and 1, last bit is odd
            return i;
    }
    							
}

int sum(const int a[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += a[i];
    }
    return sum;
}




/*--------------  end cut  -----------------------
# End of file oddeven.c		*/
