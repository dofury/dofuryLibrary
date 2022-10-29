#pragma once

typedef struct _Book {
	char* title;
	char* author;
	char* genre;
}Book;

typedef struct _Node {
	Book book;
	struct NODE* next;
}Node;
