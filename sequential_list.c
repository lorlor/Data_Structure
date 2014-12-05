#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE	100
#define False	0
#define True	1

typedef struct {
	int * base;
	int length;
} SqList;

int len(SqList *sl)
{
	return sl->length;
}

int isEmpty(SqList *sl)
{
	if (sl->length != 0)
		return False;
	else
		return True;
}

int initSequList(SqList *sl)
{
	sl->base = calloc(MAXSIZE,sizeof(int));
	if(sl->base == NULL)
		return False;
	sl->length = 0;
	return True;
}

int searchSequList(SqList sl, int e)
{
	int temp;
	for(temp = 0; temp < sl.length; temp++)
		if(sl.base[temp] == e)
			return temp + 1;
	

	return 0;
}

int insertSequList(SqList *sl, int index, int e)
{
	if(index < 1 || index > sl->length+1)
		return False;
	if(sl->length == MAXSIZE)
		return False;
	int temp;
	for(temp = sl->length - 1; temp >= index - 1; temp--)
		sl->base[temp+1] = sl->base[temp];
	sl->base[index] = e;
	++sl->length;
	return True;
}

int popSequList(SqList *sl, int index, int e)
{
	if(index > sl->length || index < 1)
		return False;
	int temp;
	e = sl->base[index-1];
	for(temp = index - 1; temp < sl->length; temp++)
		sl->base[temp] = sl->base[temp+1];
	--sl->length;
	return True;
			
}

int destroySequList(SqList sl)
{
	free(sl.base);
	sl.length = 0;

	return 0;
}

int main()
{
	int a[] = {1,2,3,4},tmp;
	int elem_tmp;
	for(tmp = 0; tmp < 4; tmp++)
		printf("%d\t",a[tmp]);
	printf("\n");

	SqList s;
	initSequList(&s);

	s.base = a;
	s.length = 4;

	// Demonstration of function len(SqList *sl).
	printf("Length is %d\n",len(&s));
	
	// Demonstration of function searchSequList(SqList sl, int e).
	tmp = searchSequList(s, 3);
	printf("Index is %d\n",tmp);

	// Demonstration of function insertSequList(SqList *sl, int index, int e).
	insertSequList(&s, 3, 5);

	for(tmp = 0; tmp < s.length; tmp++)
		printf("%d\t",s.base[tmp]);
	printf("\n");

	// Demonstration of function popSequList(SqList *sl, int index, int e).
	popSequList(&s, 2, elem_tmp);
	for(tmp = 0; tmp < s.length; tmp++)
		printf("%d\t",s.base[tmp]);
	printf("\n");

	// Demonstration of function isEmpty(SqList *sl).
	if(isEmpty(&s))
		printf("This is an empte sequential list.\n");
	else
		printf("This isn't an empty sequential list.\n");
	
//	destroySequList(s);

	return 0;
	
}
