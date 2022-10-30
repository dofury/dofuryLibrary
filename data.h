#pragma once

typedef struct _Book {
	char title[36];
	char author[36];
	char genre[36];
}Book;

typedef struct _Node {
	void* book;
	struct _Node *next;
	struct _Node *prev;
}Node;

typedef struct _List {
	Node* head;
	Node* tail;
	int count;
}List;

List* bookList;
List* newList();
void initList(List* list);
void addBook(List* list, void* book);
Node* newNode(void* book);
Book* newBook(char title[36], char author[36], char genre[36]);
void deleteBook(Book* book);
