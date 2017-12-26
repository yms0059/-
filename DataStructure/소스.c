#include<stdio.h>
#include<stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element list[MAX_LIST_SIZE];//배열 정의
	int length;                 //현재 배열에 저장된 자료들의 개수
}ArrayListType;                //구조체 이름

							   //오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//리스트 초기화
void init(ArrayListType *L)//L은 구조체를 가리키는 포인터
{
	L->length = 0; //구조체 L에접근 값에 들어가서현재 배얄에 저장되어있는 자려개수를 0으로 구조체 ArrayListType의 주소를 받아온다 L은 구저체를 가리키는 포인터다
				   //(*L).length = 0;
}
//리스트가 비어있으면 1을 반환
//그렇지 않으면 0을 반환
int is_empty(ArrayListType *L) //구조체가 비어있는지 확인 
{
	return L->length == 0;     //구조체의 주소를 받아와서 (return 값은 int true 만약에 Length가0이면 1을 반환 그렇지 않으면 0을반환)
}
//리스트가 가득 차 있으면 1을 반환
//그렇지 않으면 0을 반환
int is_full(ArrayListType*L)
{
	return L->length == MAX_LIST_SIZE;  //구조체가 가득차있으면 1을 반환 아니면 0을 반환
}

void dispaly(ArrayListType*L)
{
	int i;
	for (i = 0; i< L->length; i++)
	{
		printf("%d\n", L->list[i]);
	}
}

//삽입함수
void add(ArrayListType *L, int position, element item) //구조체를 가리키는 포인터,몇번째 삽입할것인지,십입하고자하눈 자료
{
	if (!is_full(L) && (position >= 0) && (position <= L->length)) //Add하수를 사용할수 있는지와/
	{
		int i;
		for (i = (L->length - 1); i >= position; i--)//맨끝 
			L->list[i + 1] = L->list[i];//빈칸을 만들고
		L->list[position] = item;
		L->length++;//Length증가
	}
}

element deleted(ArrayListType*L, int positon)//삭제하고싶은 포지션
{
	int i;
	element item;

	if (positon < 0 || positon >= L->length)
		error("위치오류");
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





