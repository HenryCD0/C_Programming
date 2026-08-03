
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
	
  // Note that from here on, you can access elements of the arr with
  // expressions like a[i]
	
  // initialize all elements
  for(int j = 0; j < n; j++) {
    arr[j] = j;
  }

  int pplplaying = n;
  int index = 0;
  int count;
  int saveidx;

  while(pplplaying > 1) {
    count = 0;
    while(count < k) {
      if(arr[index] != -1) {
        count++;
        saveidx = index;
      }
      index++;
      if(index == n) {
        index = 0;
      }
    }
    printf("%d\n", arr[saveidx]);
    arr[saveidx] = -1;
    pplplaying--;
  }
  for(int i = 0; i < n; i++) {
    if(arr[i] != -1) {
      printf("%d", arr[i]);
    }
  }
  
  free (arr);
}
#endif
