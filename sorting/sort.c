#include <stdio.h>
#include "sort.h"

static void swap(int* elements, int i , int j) {
	int temp = elements[j];
	elements[j] = elements[i];
	elements[i] = temp;
}

void selsort(int* elements ,int size){
	for (int i = 0 ; i < size ; i++){
		int min = i;
		for (int j = i+1; j < size ; j++) {
			if (elements[j] < elements[min]) {
				min = j;
			}
		} 
		swap(elements,i,min);
	}
}

void inssort(int* elements, int size) {
	for (int i = 1 ; i<size; i++) {
		for (int j = i ; j > 0 && elements[j] < elements[j-1]; j-- ) {
			swap(elements,j,j-1);
		}
	}
}

void print(int* elements,int size) {
	printf("[ ");
	for (int i = 0 ; i < size; i++) {
		printf("%d ",elements[i]);
	}
	printf("]\n");
}
