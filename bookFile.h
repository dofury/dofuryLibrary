#pragma once
#include "data.h"
#include "utility.h"
void fileSave();
int fileLoad();
FILE* bookFile;
void booksSave(Node* node);
void bookSave(Book* book);
char* texts;
int textSize;
void getText();
void textToken();
int takeCheck(char* text);