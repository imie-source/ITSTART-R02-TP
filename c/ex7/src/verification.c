#include <string.h>
#include <stdlib.h>

#include "../include/verification.h"

/**
 * V�rifie si la cha�ne pass�e en param�tre est une note ou pas
 *
 * Parcourt les caract�res de la cha�ne et v�rifie un par un
 * si le caract�res est un chiffre, un point ou une virgule
 *
 * @param char* chaine Cha�ne � v�rifier
 * @return float >= 0 si la cha�ne est bien une note, -1 sinon
 */
float verificationSaisie(char *chaine) {
	// D�finition des variables locales
	/**
	 * @var int lngChaine Longueur de la cha�ne de caract�res
	 */
	int lngChaine;
	/**
	 * @var int i index de parcours de la cha�ne
	 */
	int i;
	/**
	 * @var char c caract�re courant
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