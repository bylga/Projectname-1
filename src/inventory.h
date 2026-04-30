#include<stddef.h>
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

#define AddItem(i, a) da_append(i->items, a, i->capacity, i->count);
#define RemoveItem(i, a) da_remove(i.items, a, i.capacity, i.count);

#define da_append(xs, a, capacity, count) do{\
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
		xs = realloc(xs, sizeof(*a) * capacity);\
		xs[count] = *a;\
	}\
	free(a);\
} while(0);

#define da_remove(xs, a, capacity) do{\
	assert(capacity != 0);\
	for (size_t i = 0; i < capacity; i++){\
		static size_t changed = 0;\
		if (strcmp(xs[i].name, a.name) == 0) {\
			xs[i].amount -= a.amount;\
			if (xs[i].amount == 0) xs[i].name = NULL;\
			changed = 1;\
			break;\
		}\
		if (i == capacity - 1 && changed != 1) assert(1 == 2);\
	}\
} while (0);

