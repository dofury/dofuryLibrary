#pragma once

typedef struct _Book {
	char title[36];
	char author[36];
	char genre[36];
	int take;
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
void deleteList(List* list);
void removeSet(List* list, Node* node);
void clear(List* list);
Node* newNode(void* book);
Book* newBook(char title[36], char author[36], char genre[36]);
void editSet(Node* node, Book afterBook);
void deleteBook(Book* book);
