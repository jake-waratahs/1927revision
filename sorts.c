//COMP1927 study -> Sorting algorithms
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sorts.h"

#define TRUE 1
#define FALSE 0



static int partition(int array[], int lo, int hi);
static void swap(int *a, int *b);
static void merge(int array[], int lo, int med, int hi);

int main(int argc, char *argv[]) {
	int array[10] = {25, 15, 6, 12, 7, 66, 32, 54, 60, 10};

	mergeSort(array, 0, 10);

	printArray(array, 0, 10);

	return EXIT_SUCCESS;
}


void bubbleSort(int array[], int lo, int hi){
	int passes = 0;
	int swapFlag = TRUE;
	while (swapFlag && passes < hi - lo){
		swapFlag = FALSE;
		int i;
		for (i = lo; i < hi - lo - passes; i++){
		
			if (array[i] > array[i+1]){
				swap(&array[i], &array[i+1]);
				swapFlag = TRUE;
			}
		
		}

		if (!swapFlag){
			break;
		}
	
	}
}

void insertionSort(int array[], int lo, int hi){
	hi--;
	int total = hi;
	while (lo <= hi){
		int i = hi;
		while (i < total && array[i+1] < array[i]){
			swap(&array[i+1], &array[i]);
			i++;
		}
		hi--;
	}
}

void selectionSort(int array[], int lo, int hi){
	while (hi > lo){
		int i;
		int max = array[lo];
		int maxIndex = lo;

		for (i = lo; i < hi; i++){

			if (array[i] > max){
				max = array[i];
				maxIndex = i;
			}
		}

		swap(&array[maxIndex], &array[hi-1]);
		hi--;
	}
}

void quickSort(int array[], int lo, int hi){
	if (hi > lo){
		int i = partition(array, lo, hi);
		quickSort(array, lo, i);
		quickSort(array, i+1, hi);
	}
}

static int partition(int array[], int lo, int hi){
	int pivot = array[lo];
   int lowerLimit = lo + 1;
   int upperLimit = hi - 1;
   while (lowerLimit < upperLimit) {
      while (array[lowerLimit] < pivot && lowerLimit < hi){
      	lowerLimit++;
      }
      while (pivot < array[upperLimit] && upperLimit > lowerLimit){
			upperLimit--;
      }
      if (lowerLimit != upperLimit){
	      swap(&array[lowerLimit],&array[upperLimit]);
		}
   }
   if (array[lowerLimit] < pivot){
   	upperLimit = lowerLimit;
   } else {
   	upperLimit = lowerLimit - 1;
   }
   swap(&array[lo],&array[upperLimit]);
   return upperLimit;
}

void mergeSort(int array[], int lo, int hi){
	if (hi-1 > lo){
		int mid = (hi + lo) / 2;
		mergeSort(array, lo, mid);
		mergeSort(array, mid, hi);
		merge(array, lo, mid, hi);
	}
}

static void merge(int array[], int lo, int mid, int hi){
	int firstIndex = lo;
	int secondIndex = mid;
	int newIndex = 0;
	int *new = malloc(sizeof(int) * (hi - lo));
	assert(new != NULL);
	while (firstIndex < mid && secondIndex < hi){
		if (array[firstIndex] <= array[secondIndex]){ //Equals sign included for stability
			new[newIndex] = array[firstIndex];
			firstIndex++;
		} else {
			new[newIndex] = array[secondIndex];
			secondIndex++;
		}
		newIndex++;
	}

	while (firstIndex < mid){
		new[newIndex] = array[firstIndex];
		firstIndex++;
		newIndex++;
	}

	while (secondIndex < hi){
		new[newIndex] = array[secondIndex];
		secondIndex++;
		newIndex++;
	}

	int i;
	for (i = lo; i < hi; i++){
		array[i] = new[i - lo];
	}

	free(new);
	printArray(array, lo, hi);
}

void printArray(int array[], int lo, int hi){
	int i;
	for (i = lo; i < hi - 1; i++){
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[hi - 1]);
}

static void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}