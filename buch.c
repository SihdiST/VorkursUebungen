#include<stdio.h>
#include<string.h>
#include "buch.h"

void editBook(Buch* pBook, char[] pISBN, char[] pName, char[] pAuthor){
	Book edit = createBook(pISBN, pName, pAuthor);
	*pBook = edit;
}

Buch createBook(char[] pISBN, char[] pName, char[] pAuthor){
	Buch new;
	String.copy(new.isbn, pISBN);
	String.copy(new.name, pName);
	String.copy(new.author, pAuthor);
	return new;
}

void print(Buch){

}

int main(void){
	return 0;
}
