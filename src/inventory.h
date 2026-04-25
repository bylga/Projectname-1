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

void AddItem(Inventory * i, Item * a);
void RemoveItem(Inventory * i, Item * a);

void AddNode(struct Node * Root, Item * item);
void RemoveNode (struct Node * Root, struct Node * prev);

Inventory CreateInventory (Item * item, int x, int y);
/*
void RemoveItem(Inventory * i, Item * a){
	if (i->item.name == a->name){
		RemoveNode(i->Root);
	}
}
*/
#endif
