#include<stddef.h>
#define pair(a,b) struct{a;b;}pair

typedef struct{
	char * name;
	int amount;
} Item;

typedef struct{
	int x;
	int y;
	int level;
	Item * items;
	size_t count;
	size_t capacity;
} Inventory;

int AddItem(Inventory i, Item a, int x, int y);
int RemoveItem(Inventory i, Item a);

#ifndef GAMEIMPL
#define GAMEIMPL
#else
/*
int AddItem(Inventory & i, Item a, int x, int y){
	if (i->count == 0){
		items = malloc(sizeof(Item) * 256);
		if (items == NULL) return -1;
		i->capacity = 256;
		level = CurLevel;
		i->x = x;
		i->y = y;
	}
	if (i->count >= i->capacity) {capacity *= 2; realloc(i->items, sizeof(Item) * capacity * 2);}

	i->items[count] = a;
	i->count += 1;

	return 0;
}
*/
#endif
