#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"


static void* alloc(void* ptr, size_t new_size){
		void* temp = realloc(ptr, sizeof(int) * new_size);
		if ( temp == NULL ) {
			return NULL;
		}	
		return temp;
}

void stack_init(struct stack* S){ 
	S->capacity = 0;
	S->size     = 0;
	S->items    = NULL;
}

int stack_push(struct stack* S,int item){
	if ( STACK_SIZE(S) >= STACK_CAP(S) ) {
		S->capacity = STACK_CAP(S) == 0 ? 1 : S->capacity * 2;
		S->items = alloc(S->items,S->capacity);
	}	
	S->items[S->size] = item;
	S->size++;
	return 0;
}

int stack_pop(struct stack* S, int* item) {
	S->size--;
	int poped = S->items[S->size];

	if (  STACK_SIZE(S) < STACK_CAP(S) / 2 ) {
		S->capacity = S->capacity / 2;
		S->items = alloc(S->items,S->capacity);
	}
	*item = poped;
	return 0;
}

void stack_print(struct stack* S) {
	for ( int i = 0 ; i < STACK_SIZE(S) ; i++) {
		printf("%d -> ",S->items[i]);
	}
	printf("\n");
}

void stack_free(struct stack* S) {
	free(S->items);
}

