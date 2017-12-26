#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

void error(char*message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode*create_node(element data, ListNode*link)
{
	ListNode*new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) error("메모리 할당 에러");
	new_node->data = data;
	new_node->link = link;
	return(new_node);
}

void display(ListNode*head)
{
	ListNode*p = head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

void insert_first(ListNode**phead, ListNode*node) 
{
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}

void insert_last(ListNode**phead, ListNode*node) {
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}


ListNode*search(ListNode*head, int x)
{
	ListNode*p;
	p = head;
	while (p != NULL)
	{
		if (p->data == x) return p;
		p = p->link;
	}
	return p;
}


int main()
{
	ListNode*list1 = NULL;

	//list=20->10->30
	insert_first(&list1, create_node(10, NULL));
	insert_first(&list1, create_node(20, NULL));
	insert_last(&list1, create_node(30, NULL));

	display(list1);
}