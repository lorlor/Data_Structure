/************************************************************************
 * link_list.c - linked list example.
 * Author:	Lor(a.k.a Butcher Cat);
 * E-mail:	wt_lor@163.com( Maybe ButcherCat@lortech.com);
 * Date:	12-07-2014;
 * Location:	Room 403, Buuilding 9, Shandong University of Technology.
 *
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define False	0
#define True	1

struct node {
	int data;
	struct node *next;
};

typedef struct node Node;

int initLinkList(Node *list, int n)
{
	Node *head = NULL;
	list->next = head;
	if(n < 0){
		printf("Invalid input: n should be gr8er than 0\n");
		return False;
	}
	if(0 == n){
		return True;	
	}
	if(n > 0){
		Node *cur = (Node *)malloc(sizeof(Node));
		cur->next = (Node *)malloc(sizeof(Node));
		if(cur ==NULL ){
			perror("malloc: cur");
			return False;
		}
		if(cur->next == NULL){
			perror("malloc: cur->next");
			return False;
		}
		head = cur;
		while(0 != n){
			printf("Please input your data in order:\n");
			printf("Value n:%d\n",n);
			scanf("%d",&cur->data);
			cur = cur->next;
			if(1 == n)
				cur = NULL;
			n--;
		}
	}
	return True;
}

int main()
{
	Node *l;
	int n;
	printf("Please input the initial number of your link:\n");
	scanf("%d",&n);
	initLinkList(l,n);
//	traverseLinkList(l);

	return 0;
}
