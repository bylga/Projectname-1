#include<stddef.h>

#ifndef GAMEIMPL
#define GAMEIMPL
#else

typedef struct{
	int amount;
	char * name;
	char type;
} Item;

struct{
	struct Node * left;
	struct Node * right;
	Item item;
} Node;

typedef struct{
	struct Node * Root;
	size_t count;
	int x;
	int y;
	int level;
} Inventory;

void RemoveNode (struct Node * Root, struct Node * prev, Item * a);
void AddNode(struct Node * Root, Item * item);

#define AddItem(i, a) AddNode(i->Root, a)
#define RemoveItem(i, a) RemoveNode(i->Root, NULL, a)
#define INIT_NODE(n) n.left=NULL;n.right=NULL;

#endif
