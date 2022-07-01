#ifndef bag_h
#define bag_h


struct node {
	struct node* next;
	double data;
};

struct Bag {
	struct node* items;
	int size;
};

void bag_init(struct Bag*);
void bag_destroy(struct Bag*);

int bag_add(struct Bag*,int );
void bag_print(struct Bag*);

#define BAG_SIZE(bag) ((bag)->size)
#define BAG_IS_EMPTY(bag) ((bag)->size == 0)
#define NODE_DATA(node) ((node)->data)
#define NODE_NEXT(node) ((node)->next)
#define BAG_FIRST(bag) ((bag)->items)

#endif
