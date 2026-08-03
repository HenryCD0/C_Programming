#include "sort.h"

void ssort(int * arr, int size) {
	/* For step 3, fill this in to perform a selection sort
	   For step 4, add conditional compilation flags to perform an ascending selection sort instead */

	#if ASCENDING
	for(int i = 0; i < (size -1); i++) {
		int lildex = i;
		for(int j = i + 1; j < size; j++) {
			if(arr[lildex] > arr[j]) {
				lildex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[lildex];
		arr[lildex] = temp;
		}

	#else
	for(int i = 0; i < (size -1); i++) {
		int bigdex = i;
		for(int j = i + 1; j < size; j++) {
			if(arr[bigdex] < arr[j]) {
				bigdex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[bigdex];
		arr[bigdex] = temp;
		}
	#endif
	}
