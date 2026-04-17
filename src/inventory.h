#include<stddef.h>
#define pair(a,b) struct{a;b;}pair

typedef struct{
	char * start;
	size_t len;
} String_v;

typedef struct{
	String_v name;
	int amount;
	size_t count;
	size_t capacity;
} Items;

typedef struct{
	Items* items;
	pair(int x, int y);
	int level;
} Inventory;


