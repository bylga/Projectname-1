#include<stddef.h>

#ifndef GAMEIMPL
#define GAMEIMPL
#else

typedef struct{
	int amount;
	char * name;
	char type;
} Item;

typedef struct{
	Item * items;
	size_t capacity;
	size_t count;
	int x;
	int y;
	int level;
} Inventory;

#define AddItem(i, a) 

#define RemoveItem(i, a)

#endif
