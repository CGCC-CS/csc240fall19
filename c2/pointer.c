#include<stdio.h>
#include<stdlib.h>

int main(void) {
  int num = 6;  /* integer */
  int * ptr;    /* pointer to an integer (or integer pointer) */
  char * cptr;  /* character poitner */
  char str[] = "1234567890";
  int * aptr;

  /* & : reference operator - returns the address */
  /* * : dereference operator - returns an alias */

  ptr = &num;
  printf("num = %d, %p, %lu\n", num, (void *) &num, sizeof(num));
  printf("ptr = %p, %p, %lu, *ptr=%d\n", (void *) ptr, (void *) &ptr, sizeof(ptr), *ptr);

  /* *ptr is an alias num */
  *ptr = 20;
  printf("\n*ptr = 20;\n");
  printf("num = %d, %p, %lu\n", num, (void *) &num, sizeof(num));
  printf("ptr = %p, %p, %lu, *ptr=%d\n", (void *) ptr, (void *) &ptr, sizeof(ptr), *ptr);

  printf("\nptr:\n");
  printf("ptr = %p\n", (void *) ptr);
  printf("*ptr = %d\n", *ptr);
  printf("&num = %p\n", (void *) &num);
  printf("*(&num) = %d\n", *(&num));
  printf("&(*ptr) = %p\n", (void *) &(*ptr));
  /* COMPILE ERROR printf("&(*num) = %p\n", (void *) &(*num)); */

  /* Don't try this at home 
  aptr = *ptr;
  printf("&(*aptr) = %p\n", (void *) &(*aptr));
  printf("*aptr = %d\n", *aptr);
  */

  /* Allocate memory */
  printf("\nAllocating memory: \n");
  cptr = malloc(10 * sizeof(char));
  for (int ii=0;ii<9;ii++) {
    *(cptr+ii) = 'A' + ii;
  }
  *(cptr+9) = '\0';
  
  printf("str=%s\n", str);
  printf("cptr=%s\n", cptr);


  /* Allocate memory for an array */
  aptr = malloc(10 * sizeof(int));   /* Make sure you allocate enough bytes */
  for (int ii=0;ii<9;ii++) {
    *(aptr+ii) = ii * 10;
  }
  printf("aptr = ");
  for (int ii=0;ii<9;ii++) {
    printf("[%d] ", *(aptr+ii));
  }
  printf("\n");

  free(cptr); 
  return 0;
}
