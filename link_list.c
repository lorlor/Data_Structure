#include <stdio.h>

typedef struct {
	int data;
	struct node *next;
} *node,Link;

int initLinkList(Link *list)
{
	node elem;
	elem->next = NULL;
	list->next = elem->next;
	list->data = elem->data;
	return 0;
}

int main()
{
	Link l;
	initLinkList(&l);
}
