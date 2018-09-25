#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "buch.h"
#include "kunde.h"

Buch nullbuch;
Kunde nullkunde;

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
	 
	//NULLBUCH //def in buch.h
	
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
	
	//NULLBUCH
	
	if(searchBook(pSearch, pSort, pBooks, pLength) != 0){
		int toDelete = (searchBook(pSearch, pSort, pBooks, pLength)) - 1;	
		pBooks[toDelete] = nullbuch;
	}
	else return;
}

Buch* createBookArr(int pLength){

	//NULLBUCH
	
	Buch *bookArr;
	bookArr =(Buch*)calloc(pLength, sizeof(Buch));
	
	for(int i = 0;i < pLength;i++) bookArr[i] = nullbuch;
	
	return bookArr;
}

void printBookArr(Buch arr[], int pLength){
	printf("\n\n##################### Buecherregal ###################\n\n");
	for(int i = 0;i < pLength;i++) printBook(arr[i]);
	printf("######################################################\n\n");
}

void deleteBookArr(Buch *pBookArr){
	free(pBookArr);
}

//######################################################

int searchKunde(char pSearch[], int pSort, Kunde pKunde[], int pLength){
if(pSort == 0){
		int i = 0;
		while(i < pLength){
			if(strcmp(pSearch, pKunde[i].kundenNr) == 0) return i + 1;
			i++;
		} 
		return 0;
	}
	else if(pSort == 1){
		int i = 0;
		while(i < pLength){
			if(strcmp(pSearch, pKunde[i].name) == 0) return i + 1;
			i++;
		} 
		return 0;
	}
	else if(pSort == 2){
		int i = 0;
		while(i < pLength){
			if(strcmp(pSearch, pKunde[i].vorname) == 0) return i + 1;
			i++;
		} 
		return 0;
	}
	else return 0;
}


void addKunde(int pNummer, char *pName, char *pVorname){
	Kunde add = createKunde(pNummer, *pName, *pVorname);	
}

void deleteKunde(){
	
	//NULLKUNDE
	
	if(searchKunde(pSearch, pSort, pKunde, pLength) != 0){
		int toDelete = (searchKunde(pSearch, pSort, pKunde, pLength)) - 1;	
		pKunde[toDelete] = nullkunde;
	}
	else return;
}

Kunde* createKundeArr(int pLength){

	//NULLKUNDE
	
	Kunde *KundeArr;
	KundeArr =(Kunde*)calloc(pLength, sizeof(Kunde));
	
	for(int i = 0;i < pLength;i++) bookArr[i] = nullkunde;
	
	return KundeArr;
}

void printKundeArr(Kunde arr[], int pLength){
	printf("\n\n##################### Buecherregal ###################\n\n");
	for(int i = 0;i < pLength;i++) printKunde(arr[i]);
	printf("######################################################\n\n");
}

void deleteKundeArr(Kunde *pKundeArr){
	free(pKundeArr);
}




int main(void){
	//NULLBUCH
	
	nullbuch.isbn[0] = 'N';
	nullbuch.isbn[1] = 'U';
	nullbuch.isbn[2] = 'L';
	nullbuch.isbn[3] = 'L';
	nullbuch.isbn[4] = '\0';
	
	nullbuch.name[0] = 'N';
	nullbuch.name[1] = 'U';
	nullbuch.name[2] = 'L'; 
	nullbuch.name[3] = 'L';
	nullbuch.name[4] = '\0';
	
	nullbuch.author[0] = 'N';
	nullbuch.author[1] = 'U';
	nullbuch.author[2] = 'L';
	nullbuch.author[3] = 'L';
	nullbuch.author[4] = '\0';
	
	Buch *bookArr = createBookArr(2);
	printBookArr(bookArr, 2);
	addBook("123456789", "W3 R N00bs", "Jonas Hännes & Peter Altmaier", bookArr, 2);
	printBookArr(bookArr, 2);
	
	printBook(bookArr[searchBook("123456789", 0, bookArr, 2) - 1]);
	deleteBook("123456789", 0, bookArr, 2);
	printBookArr(bookArr, 2);
	
	deleteBookArr(bookArr);
	
	
	//printf("\n\nNullbuch:\n\n");
	//printBook(nullbuch);
	
	return 0;
}
