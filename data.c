#include "data.h"
#include "screen.h"
#include "utility.h"

Node* newNode(void* book)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->book = book;
	node->prev = node->next = NULL;
	return node;
}

Book* newBook(char title[36], char author[36], char genre[36])
{
	Book* book = (Book*)malloc(sizeof(Book));

	strcpy_s(book->title, sizeof(book->title), title);
	strcpy_s(book->author, sizeof(book->author),author);
	strcpy_s(book->genre, sizeof(book->genre), genre);
	
	
	return book;
}
void deleteBook(Book* book)
{
	free(book);
}
void clear(List* list)
{
	Node* node = list->head->next;
	while (node != list->tail)
	{
		removeSet(list, node);
		node = list->head->next;
	}
}

void removeSet(List* list, Node* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	deleteBook(node->book);
	list->count--;
}

void deleteList(List* list)
{
	clear(list);
	free(list->head);
	free(list->tail);
	free(list);
}
/*
����Ʈ�� bookŸ���� �������� �ּҸ� �ְ� �������� �߰�
*/
void addBook(List* list, void* book)
{
	//���� ������ ��带 tail�տ� �Ŵ�ϴ�.
	Node* node = newNode(book);//���ο� ��� ����
	node->prev = list->tail->prev;//now�� prev�� tail �� ���� ����
	node->next = list->tail;//now�� next�� tail�� ����
	list->tail->prev->next = node;//tail�� ���� ����� next�� now�� ��
	list->tail->prev = node;//tail�� prev�� now�� ����
	list->count++;//������ ������ ������ 1 ����
}
/*
����Ʈ�� �������� ������ �� ��ȯ
*/
List* newList()
{
	List* list = (List*)malloc(sizeof(List));
	initList(list);
	return list;
}
/*
����Ʈ �ʱ�ȭ �Լ�
*/
void initList(List* list)
{
	list->head = newNode(NULL);
	list->tail = newNode(NULL);
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->count = 0;
}
