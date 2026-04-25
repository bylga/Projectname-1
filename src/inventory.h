#include<stddef.h>

#ifndef GAMEIMPL
#define GAMEIMPL
#else

typedef struct{
	int amount;
	char * name;
	char type;
} Item;

#define INIT_NODE(n, a) n->left=NULL;n->right=NULL;n->item=a

typedef struct Node Node;
struct Node{
	Node * left;
	Node * right;
>>>>>>> refs/remotes/origin/master
	Item item;
};

typedef struct{
	Node * Root;
	size_t count;
	int x;
	int y;
	int level;
} Inventory;

void RemoveNode (Node * Root, Node * prev, Item * a);
void AddNode(Node *, Item *, Node *);

#define AddItem(i, a) AddNode(i->Root, &a, NULL)
#define RemoveItem(i, a) RemoveNode(i->Root, NULL, a)

void AddNode(Node * Root, Item * item, Node * itemNode){
	if (itemNode == NULL) {Node * newNode = malloc(sizeof(Node)); itemNode = newNode;}
	INIT_NODE(itemNode, *item);
	if (Root->right != NULL){
		int v = strcmp(Root->item.name, item->name);
		switch (v > 0){
			case (0): 
			switch (v == 0){
				case (1):
				if (itemNode != NULL) free(itemNode);
				Root->right->item.amount += item->amount;
				break;
				case (0):
				AddNode(Root->left, item, itemNode);
				break;
			}
			break;

			case (1):
			if (Root->left != NULL){
				AddNode(Root->left, item, itemNode);
			}
			else{
				Root->left = itemNode;
			}
			break;
		}
	} else{
			Root->left = itemNode;
	}
}

#endif
