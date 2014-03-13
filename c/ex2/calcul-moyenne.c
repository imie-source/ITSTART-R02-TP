#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float verificationSaisie(char *chaine) {
	// Définition des variables locales
	int lngChaine;
	int i;
	char c;
	// algo de la fonction verificationSaisie
	lngChaine = strlen(chaine);
	for(i = 0; i < lngChaine; i++) {
		c = chaine[i];
		if ( ( c < '0' ||  c > '9') &&
		     ( c != '.' ) &&
			 ( c != ',' ) ) {
			 return -1;
		}
		// Remplacement de la virgule par un point
		// pour la conversion en float via atof
		if (c == ',') {
			chaine[i] = '.';
		}
	}
	return atof(chaine);
}

int main() {

// Définition des variables globales

// L'algorithme

	note = verificationSaisie(saisie);

while(<cond>) {

}

}