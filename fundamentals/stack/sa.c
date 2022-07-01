#include "stack_array.h"



int main() {
	struct stack S;
	int poped;
	stack_init(&S);
	stack_push(&S,1);
	stack_push(&S,19);
	stack_push(&S,222);
	stack_push(&S,88);
	stack_print(&S);
	stack_pop(&S,&poped);
	stack_pop(&S,&poped);
	stack_pop(&S,&poped);
	stack_print(&S);
	stack_free(&S);
}
