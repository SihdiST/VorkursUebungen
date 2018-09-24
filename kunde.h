typedef struct kunde{
	int kundenNr;
	char name [100];
	char vorname [100];
}Kunde;

//void editKunde(Kunde pKunde);

Kunde createKunde(int pNummer, char *pName, char *pVorname);
