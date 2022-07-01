#ifndef stack_array_h
#define stack_array_h


struct stack {
	int* items;
	int size;
	int capacity;
};

void stack_init(struct stack*);
int stack_push(struct stack*,int);
int stack_pop(struct stack*,int*);
void stack_print(struct stack*);
void stack_free(struct stack*);

#define STACK_CAP(s) ((s)->capacity)
#define STACK_SIZE(s) ((s)->size)

#endif
