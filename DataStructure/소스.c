#include<stdio.h>
#include<stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element list[MAX_LIST_SIZE];//�迭 ����
	int length;                 //���� �迭�� ����� �ڷ���� ����
}ArrayListType;                //����ü �̸�

							   //���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//����Ʈ �ʱ�ȭ
void init(ArrayListType *L)//L�� ����ü�� ����Ű�� ������
{
	L->length = 0; //����ü L������ ���� �������� ��⿡ ����Ǿ��ִ� �ڷ������� 0���� ����ü ArrayListType�� �ּҸ� �޾ƿ´� L�� ����ü�� ����Ű�� �����ʹ�
				   //(*L).length = 0;
}
//����Ʈ�� ��������� 1�� ��ȯ
//�׷��� ������ 0�� ��ȯ
int is_empty(ArrayListType *L) //����ü�� ����ִ��� Ȯ�� 
{
	return L->length == 0;     //����ü�� �ּҸ� �޾ƿͼ� (return ���� int true ���࿡ Length��0�̸� 1�� ��ȯ �׷��� ������ 0����ȯ)
}
//����Ʈ�� ���� �� ������ 1�� ��ȯ
//�׷��� ������ 0�� ��ȯ
int is_full(ArrayListType*L)
{
	return L->length == MAX_LIST_SIZE;  //����ü�� ������������ 1�� ��ȯ �ƴϸ� 0�� ��ȯ
}

void dispaly(ArrayListType*L)
{
	int i;
	for (i = 0; i< L->length; i++)
	{
		printf("%d\n", L->list[i]);
	}
}

//�����Լ�
void add(ArrayListType *L, int position, element item) //����ü�� ����Ű�� ������,���° �����Ұ�����,�����ϰ����ϴ� �ڷ�
{
	if (!is_full(L) && (position >= 0) && (position <= L->length)) //Add�ϼ��� ����Ҽ� �ִ�����/
	{
		int i;
		for (i = (L->length - 1); i >= position; i--)//�ǳ� 
			L->list[i + 1] = L->list[i];//��ĭ�� �����
		L->list[position] = item;
		L->length++;//Length����
	}
}

element deleted(ArrayListType*L, int positon)//�����ϰ���� ������
{
	int i;
	element item;

	if (positon < 0 || positon >= L->length)
		error("��ġ����");
	item = L->list[positon];
	for (i = positon; i < (L->length - 1); i++)
		L->list[i] = L->list[i + 1];
	L->length--;
	return item;
}

int main()
{
	ArrayListType list1;
	ArrayListType *plist;

	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	add(&list1, 0, 30);
	dispaly(&list1);

	plist = (ArrayListType*)malloc(sizeof(ArrayListType));
	init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	dispaly(plist);

}





