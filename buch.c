#include<stdio.h>
#include "buch.h"

void editBook(Buch* pBook, char[] pISBN, char[] pName, char[] pAuthor){
	Buch edit = createBook(pISBN, pName, pAuthor);
	*pBook = edit;
}

Buch createBook(char[] pISBN, char[] pName, char[] pAuthor){
	Buch new;
	Buch.isbn = pISBN;
	Buch.name = pName;
	Buch.author = pAuthor;
	return new;
}

void print(Buch){

}

int main(void){
	return 0;
}
