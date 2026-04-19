#include<stddef.h>

#ifndef GAMEIMPL
#define GAMEIMPL
#else

typedef struct{
	char * name;
	int amount;
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

void AddItem(Inventory i, Item a, int x, int y);
void RemoveItem(Inventory i, Item a);
void AddNode(struct Node * Root, Item item);
void RemoveNode (struct Node * Root, Item item);
void CreateInventory (int x, int y, Item item);

#endif
