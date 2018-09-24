#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "buch.h"
#include "kunde.h"


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

void addBook(char pISBN[], char pName[], char pAuthor[], Buch *pBooks, int pLength){
	if((searchBook(pISBN, 0, pBooks, pLength) != 0) && (searchBook(pName, 1, pBooks, pLength) != 0) &&  (searchBook(pAuthor, 2, pBooks, pLength) != 0)) return;
	Buch add = createBook(pISBN, pName, pAuthor);
	 
	NULLBUCH //def in buch.h
	
	int i = 0;
	while(i < pLength){
		if(cmpBooks(pBooks[i], nullbuch) == 0){
			pBooks[i] = add;
			return;
		}
		i++;
	}
	printf("Datenbank voll.\n");
	
}

void deleteBook(char pSearch[], int pSort, Buch *pBooks, int pLength){
	
	NULLBUCH
	
	if(searchBook(pSearch, pSort, pBooks, pLength) != 0){
		int toDelete = (searchBook(pSearch, pSort, pBooks, pLength)) - 1;	
		pBooks[toDelete] = nullbuch;
	}
	else return;
}

Buch* createBookArr(int pLength){

	NULLBUCH
	
	Buch *bookArr;
	bookArr =(Buch*)calloc(pLength, sizeof(Buch));
	
	for(int i = 0;i < pLength;i++) bookArr[i] = nullbuch;
	
	return bookArr;
}

void printBookArr(Buch arr[], int pLength){
	printf("##################### Buecherregal ###################\n\n");
	for(int i = 0;i < pLength;i++) printBook(arr[i]);
	printf("######################################################\n\n");
}

int main(void){
	NULLBUCH
	Buch *bookArr = createBookArr(1);
	printBookArr(bookArr, 1);
	addBook("123456789", "W3 R N00bs", "Jonas Hännes & Peter Altmaier", bookArr, 1);
	printBookArr(bookArr, 1);
	printf("\n\nNullbuch:\n\n");
	printBook(nullbuch);
	
	return 0;
}
