#include "bag.h"
#include <stdio.h>
#include <stdlib.h>


static struct node* new_node(int data){
	struct node* new = malloc(sizeof(struct node));	
	if ( new == NULL ) {
		return NULL;
	}
	new->data = data;
	new->next = NULL;
	return new;
}

void bag_init(struct Bag* B) {
	B->size = 0;
	B->items = NULL;
}

int bag_add(struct Bag* B,int data) {
	struct node* new = new_node(data);
	if ( new == NULL ) {
		return 0;
	}

	if ( BAG_IS_EMPTY(B) ) {
		B->items = new;
		B->items->next = NULL;
		B->size++;
		return 1;
	}

	new->next = B->items;
	B->items = new;
	B->size++;
	return 1;
}

void bag_print(struct Bag* B) {
	struct node* temp = B->items;
	do {
		printf("%f -> ",temp->data);	
		temp = temp->next;
	}while(temp != NULL);
	printf("\n");
}
