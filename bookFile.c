#define _CRT_SECURE_NO_WARNINGS
#include "bookFile.h"

void fileSave()
{
    Node* node = bookList->head->next;
    bookFile = fopen("save.txt", "w");
    booksSave(node);
    fclose(bookFile);
}


void booksSave(Node* node)
{
    fputs("start*/", bookFile);
    for (int i = 0; i<bookList->count; i++)
    {
        Book* book = node->book;
        bookSave(book);

        node = node->next;
    }
    fputs("end*", bookFile);
}
void bookSave(Book* book)
{
    char text[37];
    strcpy(text, strcat(book->title, "/"));
    fputs(text, bookFile);
    strcpy(text, strcat(book->author, "/"));
    fputs(book->author, bookFile);
    strcpy(text, strcat(book->genre, "/"));
    fputs(book->genre, bookFile);
    fprintf(bookFile,"%d", book->take);
    fputs("/", bookFile);
}


void fileLoad()
{
    bookList = newList();
    initList(bookList);

    bookFile = fopen("save.txt", "r");
    getText();
    textToken();

}

void getText()
{
    fseek(bookFile, 0, SEEK_END);
    textSize = ftell(bookFile);

    texts = (char*)malloc(textSize + 1);
    memset(texts, 0, textSize + 1);

    fseek(bookFile, 0, SEEK_SET);
    fread(texts, textSize, 1, bookFile);
    fclose(bookFile);
}
void textToken()
{
    Book book;
    char* text;
    text = strtok(texts, "*");
    while(1)
    {
        text = strtok(NULL, "/");
        if (strcmp(text,"end*")==0)
            break;
        strcpy(book.title, text);
        text = strtok(NULL, "/");
        strcpy(book.author, text);
        text = strtok(NULL, "/");
        strcpy(book.genre, text);
        text = strtok(NULL, "/");
        book.take = text - '0';
        addBook(bookList, newBook(book.title, book.author, book.genre));
    }

}