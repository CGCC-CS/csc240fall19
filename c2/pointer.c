#include<stdio.h>
#include<stdlib.h>

int main(void) {

  int num = 6;  /* integer */
  int * ptr;    /* pointer to an integer (or integer pointer) */
  char * cptr;
  char str[] = "123456789";
  int * aptr;
  int ii;

  /* & : reference operator - returns the address */
  /* * : dereference operator - returns an alias */

  ptr = &num;
  printf("num = %d, %p, %lu\n", num, (void *) &num, sizeof(num));
  printf("ptr = %p, %p, %lu, *ptr=%d\n", (void *) ptr, (void *) &ptr, sizeof(ptr), *ptr);

  /* *ptr is an alias of num */
  *ptr = 20;
  printf("\n*ptr=20\n");
  printf("num = %d, %p, %lu\n", num, (void *) &num, sizeof(num));
  printf("ptr = %p, %p, %lu, *ptr=%d\n", (void *) ptr, (void *) &ptr, sizeof(ptr), *ptr);
  
  printf("ptr:\n");
  printf("ptr = %p\n", (void *) ptr); 
  printf("*ptr = %d\n", *ptr); 
  printf("*(&ptr) = %p\n", (void *) *(&ptr)); 
  printf("&(*ptr) = %p\n", (void *) &(*ptr)); 

  printf("num:\n");
  printf("num = %d\n", num); 
  printf("&num = %p\n", (void *) &num); 
  printf("*(&num) = %d\n", *(&num)); 
  /* COMPILE ERROR: printf("&(*num) = %p\n", (void *) &(*num));  */

  /* Allocating memory */
  printf("\nAllocating memory:\n");
  cptr = (char *) malloc(10);  /* allocate 10 bytes */
  for(ii=0;ii<9;ii++) { 
    *(cptr+ii) = 'A' + ii;
  }
  *(cptr+9) = '\0';   /* This makes cptr a C-style string */

  printf("str=%s\n", str);
  printf("cptr=%s\n", cptr);

  /* Allocaate an array */
  aptr = (int *) malloc(10 * sizeof(int));  /* Make sure you allocate enough bytes */
  for(ii=0;ii<10;ii++) { 
    *(aptr+ii) = ii * 10;
  }
  printf("aptr = ");
  for(ii=0;ii<10;ii++) { 
    printf("[%d] ", *(aptr+ii));
  }
  printf("\n");



  return 0;
}
