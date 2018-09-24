#include<stdio.h>
#include<string.h>
#include "buch.h"
#include "kunde.h"

Buch nullbuch;

int searchBook(char pSearch[], int pSort, Buch pBooks[], int pLength){
	if(pSort == 0){
		int i = 0;
		while(i < pLength){
			if(strcmp(pSearch, pBooks[i].isbn) == 0) return i + 1;
			i++;
		} 
		return 0;
	}
	else if(pSort == 1){
		int i = 0;
		while(i < pLength){
			if(strcmp(pSearch, pBooks[i].name) == 0) return i + 1;
			i++;
		} 
		return 0;
	}
	else if(pSort == 2){
		int i = 0;
		while(i < pLength){
			if(strcmp(pSearch, pBooks[i].author) == 0) return i + 1;
			i++;
		} 
		return 0;
	}
	else return 0;
}

void addBook(char pISBN[], char pName[], char pAuthor[], Buch pBooks[], int pLength){
	if((searchBook(pISBN, 0, pBooks, pLength) != 0) && (searchBook(pName, 1, pBooks, pLength) != 0) &&  (searchBook(pAuthor, 2, pBooks, pLength) != 0)) return;
	Buch add = createBook(pISBN, pName, pAuthor);
	 
	//nullbuch //def in buch.h
	
	int i = 0;
	while(i < pLength){
		if(cmpBooks(pBooks[i], nullbuch) == 0){
			pBooks[i] = add;
			return;
		}
		i++;
	}
	printf("Datenbank voll.");
	
}

void deleteBook(char pSearch[], int pSort, Buch pBooks[], int pLength){
	
	//nullbuch
	
	if(searchBook(pSearch, pSort, pBooks, pLength) != 0){
		int toDelete = (searchBook(pSearch, pSort, pBooks, pLength)) - 1;	
		pBooks[toDelete] = nullbuch;
	}
	else return;
}

int main(void){
	
	
	nullbuch.isbn[0] = 'N';
	nullbuch.isbn[1] = 'U';
	nullbuch.isbn[2] = 'L';
	nullbuch.isbn[3] = 'L';
	
	nullbuch.name[0] = 'N';
	nullbuch.name[1] = 'U';
	nullbuch.name[2] = 'L'; 
	nullbuch.name[3] = 'L';
	
	nullbuch.author[0] = 'N';
	nullbuch.author[1] = 'U';
	nullbuch.author[2] = 'L';
	nullbuch.author[3] = 'L';
	
	return 0;
}
