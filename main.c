#include<stdio.h>
#include "buch.h"
#include "kunde.h"

int searchBook(char[] pSearch, int pSort, Buch[] pBooks, int pLength){
	if(pSort == 0){
		int i = 0;
		while(i < pLength){
			if(strcmp(pSearch, pBooks[i].isbn) == 0) return i;
			i++;
		} 
		return NULL;
	}
	else if(pSort == 1){
		int i = 0;
		while(i < pLength){
			if(strcmp(pSearch, pBooks[i].name) == 0) return i;
			i++;
		} 
		return NULL;
	}
	else if(pSort == 2){
		int i = 0;
		while(i < pLength){
			if(strcmp(pSearch, pBooks[i].author) == 0) return i;
			i++;
		} 
		return NULL;
	}
}

void addBook(char[] pISBN, char[] pName, char[] pAuthor, Buch[] pBooks, int pLength){
	if((searchBook(pISBN, 0, pBooks, pLength) != NULL) && (searchBook(pName, 1, pBooks, pLength) != NULL) &&  (searchBook(pAuthor, 2, pBooks, pLength) != NULL)) return;
	Buch add = createBook(pISBN, pName, pAuthor);
	
	int i = 0;
	while(i < pLength){
		if(pBooks[i] == NULL){
			pBooks[i] = add;
			return;
		}
		i++;
	}
	printf("Datenbank voll.");
	
}

void deleteBook(char[] pSearch, int pSort, Buch[] pBooks, int pLength){
	if(searchBook(pSearch, pSort, pBooks, pLength) != NULL){
		int toDelete = searchBook(pSearch, pSort, pBooks, pLength);	
		pBooks[toDelete] = NULL;
	}
	else return;
}

int main(void){
	return 0;
}
