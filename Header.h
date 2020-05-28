#ifndef HEADER_H
#define HEADER_H
typedef struct zaposlenik {  	
	char ime[20];
	char prezime[20];
	float placa;
	char OIB[11];
} ZAPOSLENIK;

typedef struct skola { 	
	ZAPOSLENIK* p;  			
	int n;
} SKOLA;

int vracaBrojRadnika();
SKOLA* unosPodataka();
float prosjekPlaca(SKOLA*);
void ispisRadnika(SKOLA*);
void oslobadjanjeMem(SKOLA*);
#endif