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

#define AddItem(i, a) da_append(i.items, a, i.capacity, i.count);
#define RemoveItem(i, a) 

#define da_append(xs, a, capacity) do{\
	if (capacity == 0) {capacity = 256; xs = malloc(sizeof(*a) * capacity);}\
	for (size_t i = 0; i < capacity; i++){\
		if (xs[i].name == NULL){\
			xs[i] = *a;\
			a->name = NULL;\
			break;\
		} else if (strcmp(xs[i].name, a->name) == 0){\
			a->name = NULL;\
			xs[i].amount += a->amount;\
			break;\
		}\
	}\
	if (a->name != NULL && count != capacity){\
		xs[count] = *a;\
		count++;\
	} else if (a->name != NULL){\
		capacity *= 2;\
		count++;\
		xs = realloc(*a * capacity);\
		xs[count] = *a;\
	}\
	free(a);\
} while(0);


#endif
