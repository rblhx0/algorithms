#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"


int isoperator(char c) {
	return c == '+' || c=='-'|| c == '*' || c == '/';
}

int main(int argc, char** argv) {
	if ( argc == 1 ) {
		return -1;
	}

	struct stack operators;
	struct stack operands;
	stack_list_init(&operators);
	stack_list_init(&operands);
	
	char* trav = argv[1];
	for ( ; *trav != '\0' ; trav++) {
		if (*trav == ' ' || *trav == '(') {
			continue;
		}else if (*trav == ')') {
			double a = *(double*)stack_list_pop(&operands);
			double b = *(double*)stack_list_pop(&operands);
			char op = *(char*)stack_list_pop(&operators);
			switch ( op ) {
				case '*':{
					double* op = malloc(sizeof(double));
					*op = b * a;
					stack_list_push(&operands,(void*)op);
					break;
						 }
				case '/':{
					double* op = malloc(sizeof(double));
					*op = b / a;
					stack_list_push(&operands,(void*)op);
					break;
						 }
				case '+':{
					double* op = malloc(sizeof(double));
					*op = b + a;
					stack_list_push(&operands,(void*)op);
					break;
						 }
				case '-':{
					double* op = malloc(sizeof(double));
					*op = b - a;
					stack_list_push(&operands,(void*)op);
					break;
						 }
				default:
					break;
			}
		}else if (isoperator(*trav)) {
			char* op = malloc(sizeof(char));
			*op = *trav;
			stack_list_push(&operators,(void*)op);
		}else{
			double* op = malloc(sizeof(double));
			*op = strtod(trav,NULL);
			stack_list_push(&operands,(void*)op);
		}
	}
	printf("%f\n",*(double*) stack_list_pop(&operands));
}
