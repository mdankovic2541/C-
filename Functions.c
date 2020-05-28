#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int vracaBrojRadnika() {
	int brojRadnika;
	printf("Unesite broj radnika koji rade u skoli:\n");
	scanf("%d", &brojRadnika);
	return brojRadnika;

}

SKOLA* unosPodataka() {
	int i;

	SKOLA* radnik = (SKOLA*)malloc(sizeof(SKOLA));  

	int brojRadnika = vracaBrojRadnika();

	radnik->n = brojRadnika;   

	radnik->p = (ZAPOSLENIK*)malloc(sizeof(ZAPOSLENIK) * brojRadnika);

	for (i = 0; i < brojRadnika; i++) { 		
		printf("\nIme %d. radnika:\t", i + 1);
		scanf("%s", radnik->p[i].ime);

		printf("\nPrezime %d. radnika:\t", i + 1);
		scanf("%s", radnik->p[i].prezime);

		printf("\nOIB %d. radnika:\t", i + 1);
		scanf("%s", radnik->p[i].OIB);

		printf("\nPlaca %d. radnika:\t", i + 1);
		scanf("%f", &radnik->p[i].placa);

	}

	return radnik;
}

float prosjekPlaca(SKOLA* radnik) {
	float prosjek = 0;
	int brojRadnika = vracaBrojRadnika();
	for (int i = 0; i < brojRadnika; i++) {
		prosjek += radnik->p[i].placa;
	}
	prosjek /= brojRadnika;
	
	return prosjek;
}

void ispisRadnika(SKOLA* radnik) {
	for (int i = 0; i < radnik->n; i++) {
		printf("Ime %d. radnika je : %s,\t", i + 1,radnik->p[i].ime);
		printf("Prezime %d. radnika je : %s,\t", i + 1 ,radnik->p[i].prezime);
		printf("OIB %d. radnika je : %s,\t", i + 1 ,radnik->p[i].OIB);
		printf("Placa %d. radnika je : %f,\t", i + 1,radnik->p[i].placa);
	}
}

void oslobadjanjeMem(SKOLA* radnik) {
	free(radnik->p);
	free(radnik);
}
