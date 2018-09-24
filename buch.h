typedef struct buch{
	char[100] = isbn;
	char[100] = name;
	char[100] = author;
}Buch;

void editBook(Buch pBook);
Buch createBook(char[] pISBN, char[] pName, char[] pAuthor);
