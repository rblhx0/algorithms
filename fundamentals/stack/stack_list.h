#ifndef stack_list_h
#define stack_list_h

struct node {
	void* data;
	struct node* next;
};

struct stack {
	struct node* top;
	int size;
};

void stack_list_init(struct stack*);
void stack_list_push(struct stack*, const void* data);
void* stack_list_pop(struct stack*);

#define STACK_SIZE(s) ((s)->size)


#endif
