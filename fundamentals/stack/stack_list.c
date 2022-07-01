#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"


void stack_list_init(struct stack* s) {
	s->size = 0;
	s->top = NULL;
}

void stack_list_push(struct stack* s, const void* data){
	struct node* new = malloc(sizeof(struct node));
	if (new == NULL) {
		return;
	}
	
	new->data = (void*) data;
	new->next = s->top;
	s->top = new;
	s->size++;

}

void* stack_list_pop(struct stack* s) {
	if ( STACK_SIZE(s) == 0 ) {
		return NULL;
	}
	void* result = s->top->data;
	struct node* temp = s->top;
	s->top = temp->next;
	free(temp);
	return result;
}
