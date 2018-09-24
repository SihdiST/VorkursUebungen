
typedef struct{
	char isbn[100];
	char name[100];
	char author[100];
}Buch;

//#define NULLBUCH Buch nullbuch; nullbuch.isbn[0] = nullbuch.name[0] = nullbuch.author[0] = 'N'; nullbuch.isbn[1] = nullbuch.name[1] = nullbuch.author[1] ='U'; nullbuch.isbn[2] = nullbuch.name[2] = nullbuch.author[2] ='L';nullbuch.isbn[3] = nullbuch.name[3] = nullbuch.author[3] = 'L';

void editBook(Buch* pBook, char pISBN[], char pName[], char pAuthor[]);
Buch createBook(char pISBN[], char pName[], char pAuthor[]);
int cmpBooks(Buch pCmp1, Buch pCmp2);
