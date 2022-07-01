#include "bag.h"
#include <stdio.h>
#include <math.h>


int main() {
	struct Bag numbers;
	bag_init(&numbers);
	for ( int i = 0 ; i < 10 ; i++) {
		int temp;
		scanf("%d",&temp);
		bag_add(&numbers,temp);
	}

	int size = BAG_SIZE(&numbers);
	double sum = 0;

	struct node* temp = BAG_FIRST(&numbers);
	for ( int i = 0 ; i < size ; i++) {
		sum += NODE_DATA(temp);
		temp = NODE_NEXT(temp);
	}
	
	double mean = sum/size;

	sum = 0.0;
	temp = BAG_FIRST(&numbers);
	for ( int i = 0 ; i < size ; i++) {
		sum += (NODE_DATA(temp) - mean ) *(NODE_DATA(temp) - mean );
		temp = NODE_NEXT(temp);
	}
	
	double std = sqrt(sum / (size-1));

	printf("mean: %f\nstd: %f\n", mean,std);


}
