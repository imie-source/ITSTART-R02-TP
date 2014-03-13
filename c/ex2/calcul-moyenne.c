#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
char saisie[6];
float moy;
float som = 0;
int nbn = 0;
float min;
float max;
float ety;
float note;
float carsom = 0;

// L'algorithme

printf("Veuillez saisir les notes, finir par le mot 'fin'\n");
while( strcmp(saisie, "fin") ) {
	gets(saisie);
	note = verificationSaisie(saisie);
	if (note >= 0) {
		if (nbn == 0) {
			min = note;
			max = note;
		}
		som += note;
		carsom += (note*note);
		nbn++;
		if (note < min) {
			min = note;
		}
		if ( note > max ) {
			max = note;
		}
	} else {
		if ( strcmp(saisie, "fin") != 0) {
			printf("Veuillez saisir une note valide\n");
		}	
	}
}
if (nbn != 0) {
	moy = som / nbn; // Calcul de la moyenne
	ety = sqrt( ( carsom / nbn ) - ( ( som * som ) /  ( nbn * nbn ) ) ); // Calcul de l'écart-type
	printf("La moyenne est : %f\n", moy); 
	printf("La note la plus basse : %f\n", min);
	printf("La note la plus haute : %f\n", max);
	printf("l'%ccart-type : %f\n", 130, ety);
} else {
	printf("Vous n'avez pas saisi de notes...\n");
}
return 0;
}