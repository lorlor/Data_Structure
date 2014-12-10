/************************************************************************
 * link_list.c - 
 * 		linked list example.
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

/* Function initLinkList
 * 	Usage: to create a link list named list as the first parameter;
 * 	Parameter:
 *		n: numbers of element used to initialize the [link list];
 *		head: a temparory parameter, representing the head of [link list],
 *			its data scope stores the length of [link list].*/
int initLinkList(Node *list, int n)
{
	Node *head = (Node *)malloc(sizeof(Node));
	printf("%x\n",head);
	list->next = head;
	if(n < 0){
		printf("Invalid input: n should be gr8er than 0\n");
		return False;
	}
	if(0 == n){
		head->data = 0;
		head->next = NULL;
		return True;	
	}
	if(n > 0){
		Node *cur = (Node *)malloc(sizeof(Node));
		if(cur ==NULL ){
			perror("malloc: cur");
			return False;
		}
		head->data = n;
		head->next = cur;
		while(0 != n){
			if(n == 1){
				printf("Please input your data in order\n");
				scanf("%d",&cur->data);
				cur->next = NULL;
			}
			else{
				cur->next = (Node *)malloc(sizeof(Node));
				printf("Please input your data in order:\n");
				printf("Value n:%d\n",n);
				scanf("%d",&cur->data);
				cur->next->next = NULL;
				cur = cur->next;
			}
			n--;
		}
		printf("%d\n",head->data);
	}
	return True;
}

/* Function traverseLinkList -
 *	Usage: scanning the [link list] created by function initLinkList() in order;*/
int traverseLinkList(Node *list)
{
	Node *temp = list->next->next;
	printf("Start\n");
	while(temp->next != NULL){
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data);

	printf("Stop\n");

	return True;
}

/* Function insertElem - 
 * 	Usage: insert an element at the location whose index is [index];
 */
int insertElem(Node *list, int index, int e)
{
	if(index < 0 || index > list->next->data){
		printf("Invalid input: your input out of range\n");
		printf("Exiting ...\n");
		return False;
	}
	else{
	/* Some notices:
	 * 	1. If pointer cur = list->next, the [e] will be inserted at
	 * 	[index];
	 * 	2. If pointer cur = list->next->next, the [e] will be 
	 * 	inserted at [index + 1].
	 */
		Node *cur = list->next;
		int i;
		while(index != 1){
			cur = cur->next;
			index--;
		}
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->data = e;
		temp->next = cur->next;
		cur->next = temp;
		list->next->data += 1;
	}

	return True;

}

/* Function removeElem -
 * 	Usage: delete an element at the [index] from the [link list] and don't return it;
 */
int removeElem(Node *list, int index)
{
	if(index < 0 || index > list->next->data){
		printf("Invalid input: your input out of range\n");
		printf("Exiting ... \n");
		return False;
	}
	else{
		Node *prev = list->next;
		while(index != 1){
			prev = prev->next;
			index--;
		}
		prev->next = prev->next->next;
		list->next->data -= 1;
	}
	return True;
}

/* Function popElem -
 *	Usage: delete an element at the [index] from the [link list] and return it [e_temp];
 */
int popElem(Node *list, int index)
{
	if(index < 0 || index > list->next->data){
		printf("Invalid input: your input out of range\n");
		printf("Exiting ... \n");
		return False;
	}
	else {
		int e_temp;
		Node *prev = list->next;
		Node *temp = (Node *)malloc(sizeof(Node));
		while(index != 1){
			prev = prev->next;
			index--;
		}
		temp = prev->next;
		prev->next = prev->next->next;
		list->next->data -= 1;
		e_temp = temp->data;
		free(temp);

		return e_temp;
	}
}

int main()
{
	Node *l;
	int n,index,tmp;
	printf("Please input the initial number of your link:\n");
	scanf("%d", &n);

	/* Demonstration of function initLinkList() and traverseLinkList(). */
	initLinkList(l, n);
	traverseLinkList(l);
	
	/* Demonstration of function insertElem(). */
	printf("Please input the index you wanna insert:\n");
	scanf("%d", &index);
	insertElem(l, index, 4);
	traverseLinkList(l);

	/* Demonstration of function removeElem(). */
	removeElem(l, 5);
	traverseLinkList(l);

	/* Demonstration of function popElem(). */
	tmp = popElem(l, 2);
	printf("%d\n",tmp);
	traverseLinkList(l);

	return 0;
}
