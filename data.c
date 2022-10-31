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
리스트에 book타입의 데이터의 주소를 넣고 동적으로 추가
*/
void addBook(List* list, void* book)
{
	//새로 생성한 노드를 tail앞에 매답니다.
	Node* node = newNode(book);//새로운 노드 생성
	node->prev = list->tail->prev;//now의 prev를 tail 앞 노드로 설정
	node->next = list->tail;//now의 next를 tail로 설정
	list->tail->prev->next = node;//tail의 이전 노드의 next를 now로 설
	list->tail->prev = node;//tail의 prev를 now로 설정
	list->count++;//보관한 데이터 개수를 1 증가
}
/*
리스트를 동적으로 생성한 후 반환
*/
List* newList()
{
	List* list = (List*)malloc(sizeof(List));
	initList(list);
	return list;
}
/*
리스트 초기화 함수
*/
void initList(List* list)
{
	list->head = newNode(NULL);
	list->tail = newNode(NULL);
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->count = 0;
}
