#include <stdio.h>
#include "include/affichernotes.h"

/**
 * Affiche l'ensemble des notes, une par ligne
 *
 * @param int nbNotes Nombre de notes saisies
 * @param array tabRes Tableau des résultats
 */
void afficherNotes(int nbNotes, struct resultat tabRes[]) {
	/**
	 * @var int i index de parcours des notes
	 */
	int i;
	printf("Voici les notes de la classe saisies :\n");
	for(i = 0; i < nbNotes; i++) {
		printf("\tnote %d (%s): %2.2f\n", 
			   (i+1), 
			   tabRes[i].prenomEleve, 
			   tabRes[i].noteEleve); 
	}
}