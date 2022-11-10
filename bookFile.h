#pragma once
#include "data.h"
#include "utility.h"
void fileSave();
void fileLoad();
FILE* bookFile;
void booksSave(Node* node);
void bookSave(Book* book);
char* texts;
int textSize;
void getText();
void textToken();