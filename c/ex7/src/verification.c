#include <string.h>
#include <stdlib.h>

#include "../include/verification.h"

/**
 * Vérifie si la chaîne passée en paramètre est une note ou pas
 *
 * Parcourt les caractères de la chaîne et vérifie un par un
 * si le caractères est un chiffre, un point ou une virgule
 *
 * @param char* chaine Chaîne à vérifier
 * @return float >= 0 si la chaîne est bien une note, -1 sinon
 */
float verificationSaisie(char *chaine) {
	// Définition des variables locales
	/**
	 * @var int lngChaine Longueur de la chaîne de caractères
	 */
	int lngChaine;
	/**
	 * @var int i index de parcours de la chaîne
	 */
	int i;
	/**
	 * @var char c caractère courant
	 */
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