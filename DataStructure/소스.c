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

void insert_node(ListNode**phead, ListNode*p, ListNode*new_node)  //phead�����͸� ����Ű�� ������/�����带 ����Ű�� ������/���Ե� ���ο� ��带 ����Ű�� ���
{
	if (*phead == NULL) //���鸮��Ʈ�� ���
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL)//p�� NULL�̸� ù ��° ���� ����
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	else
	{
		new_node->link = p->link;
		*phead = new_node;
	}
}

void remove_node(ListNode**phead, ListNode*p, ListNode*remove)  //phead�����͸� ����Ű�� ������/������ ����� ������/���ŵ� ���
{
	if (p == NULL) //���鸮��Ʈ�� ���
	{
		*phead = (*phead)->link;
	}
	else
	{
		p->link = remove->link;
		free(remove);
	}
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

void display_recur(ListNode*head)//��ȯ���� ����Ʈ Ž�� �˰��� 
{
	ListNode*p = head;
	if (p != NULL)
	{
		printf("%d->", p->data);
		display_recur(p->link);
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

ListNode*concat(ListNode*head1, ListNode*head2)
{
	ListNode *p;
	if (head1 == NULL)return head2;
	else if (head2 == NULL)return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode*reverse(ListNode *head)
{
	ListNode *p, *q, *r;
	p = head;   //p�� ���� ó������ ���� ���
	q = NULL;   //q�� �������� ���� ���
	while (p != NULL) {
		r = q;    //r�� �������� �� ���, r�� q,q�� p�� ���ʷ� ���󰣴�.
		q = p;
		p = p->link;
		q->link = r;  //q�� ��ũ ������ �ٲ۴�.
	}
	return q;  //q�� �������� �� ����Ʈ�� ��� ������
}

ListNode*create_node(element data, ListNode*link)
{
	ListNode*new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) error("�޸� �Ҵ� ����");
	new_node->data = data;
	new_node->link = link;
	return(new_node);
}

int main()
{
	ListNode*list1 = NULL, *list2 = NULL, *list3 = NULL;
	ListNode*p;

	//list1= 30->20->10
	insert_node(&list1, NULL, create_node(10, NULL));
	insert_node(&list1, NULL, create_node(20, NULL));
	insert_node(&list1, NULL, create_node(30, NULL));
	display(list1);

	//list1=2-->10
	remove_node(&list1, NULL, list1);
	display(list1);

	//list2= 80->70->60
	insert_node(&list2, NULL, create_node(60, NULL));
	insert_node(&list2, NULL, create_node(70, NULL));
	insert_node(&list2, NULL, create_node(80, NULL));
	display(list2);

	//list1=list1+list2
	list3 = concat(list1, list2);
	display(list3);

	//list1�� ��������
	list3 = reverse(list3);
	display(list3);
	//list1���� 20Ž��
	p = search(list3, 110);
	printf("Ž������:%d\n", p->data);
}