typedef struct{
	char isbn[100];
	char name[100];
	char author[100];
}Buch;

void editBook(Buch* pBook, char[] pISBN, char[] pName, char[] pAuthor);
Buch createBook(char[] pISBN, char[] pName, char[] pAuthor);
