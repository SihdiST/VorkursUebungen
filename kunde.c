#include <stdio.h>
#include <string.h>
#include "kunde.h"

void editKunde(Kunde* pKunde, int pNummer, String pName, String pVorname){
	Kunde edit = createKunde(int pNummer, String pName, String pVorname);
	*pKunde = edit;
}

Kunde createKunde(int pNummer, String pName, String pVorname){
	Kunde new;
	new.kundenNr = pNummer;
	strcpy(new.name, pName);
	strcpy(new.vorname, pVorname);
	return new;
}

int main(void){
	return 0;
}
