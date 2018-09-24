#include <stdio.h>
#include <string.h>
#include "kunde.h"

void editKunde(Kunde* pKunde, int pNummer, char *pName, char *pVorname){
	Kunde edit = createKunde( pNummer, pName, pVorname);
	*pKunde = edit;
}

Kunde createKunde(int pNummer, char *pName, char *pVorname){
	Kunde new;
	new.kundenNr = pNummer;
	strcpy(new.name, pName);
	strcpy(new.vorname, pVorname);
	return new;
}


