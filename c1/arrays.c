#include<stdio.h>

int main(void) {

  /* Initializing array declarations */
  int a[4] = {1, 2, 3, 4};
  double b[] = {2.4, 3.14, 9.9999};  /* b is the size of the initializer */
  /* What happens if we declare an array with a size smaller than the initializer? */

  unsigned int ii;

  /* What happens when we go past the end of the array? */
  for (ii=0;ii<6;ii++) {
    printf("a[%d]=%d (%x)\t\tb[%d]=%f\n", ii, a[ii], a[ii], ii, b[ii]);
  }
  printf("\n");

  /* Are these sizes what you expect ? */
  printf("Size of int=%lu\t", sizeof(int));   
  printf("Size of a=%lu\n", sizeof(a));   
  printf("Size of double=%lu\t", sizeof(double));   
  printf("Size of b=%lu\n", sizeof(b));   
  printf("\n");

  /* what does (sizeof(a)/sizeof(int) do? */
  for (ii=0;ii<(sizeof(a)/sizeof(int));ii++) {
    printf("a[%d]=%d (%x)\n", ii, a[ii], a[ii]);
  }
  printf("\n\n");

  return 0;
}
