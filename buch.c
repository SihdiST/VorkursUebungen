#include<stdio.h>
#include<string.h>
#include "buch.h"

void editBook(Buch* pBook, char pISBN[], char pName[], char pAuthor[]){
	Book edit = createBook(pISBN, pName, pAuthor);
	*pBook = edit;
}

Buch createBook(char pISBN[], char pName[], char pAuthor[]){
	Buch new;
	strcpy(new.isbn, pISBN);
	strcpy(new.name, pName);
	strcpy(new.author, pAuthor);
	return new;
}

int cmpBooks(Buch pCmp1, Buch pCmp2){
	if((strcmp(pCmp1.isbn, pCmp2.isbn) == 0) && (strcmp(pCmp1.name, pCmp2.name) == 0) && (strcmp(pCmp1.author, pCmp2.author) == 0)) return 0;
	else return 1; 
}

void print(Buch){

}

int main(void){
	return 0;
}
