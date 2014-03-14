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

/**
 * Affiche l'ensemble des notes, une par ligne
 *
 * @param int nbNotes Nombre de notes saisies
 * @param array tab Tableau des notes
 */
void afficherNotes(int nbNotes, float tab[]) {
	int i;
	printf("Voici les notes saisies :\n");
	for(i = 0; i < nbNotes; i++) {
		printf("\tnote %d : %2.2f\n", (i+1), tab[i]); 
	}
}

/**
 * Première fonction appelée par le programme
 *
 * @return int Code de fin
 */
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
/**
 * @var pointer pNotes Pointeur vers les notes allouées en mémoire
 */
float *pNotes;

/**
 * @var pointer pTmp Pointeur "temporaire" pour la réallocation de mémoire
 */
float *pTmp;

// L'algorithme

// Allocation dynamique d'un float en mémoire ! penser à libérer !
pNotes = malloc(1*sizeof(float)); 

printf("Veuillez saisir les notes, finir par le mot 'fin'\n");
while( strcmp(saisie, "fin") ) {
	gets(saisie);
	note = verificationSaisie(saisie);
	if (note >= 0) {
		// Je stocke la note dans pNotes à l'indice nbn
		pNotes[nbn] = note;
		// J'alloue un float supplémentaire dans le "tableau"
		pTmp = realloc(pNotes, (nbn+2)*(sizeof(float)));
		// Si l'allocation s'est bien passée
		if (pTmp != NULL) {
			// On fait pointer pNotes vers la nouvelle plage de mémoire
			pNotes = pTmp;
		} else {
			// On indique qu'il n'y plus de mémoire
			printf("Plus de m%cmoire disponible...", 130);
			// et on termine la boucle de saisie
			break;
		}	
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
	afficherNotes(nbn, pNotes);
	moy = som / nbn; // Calcul de la moyenne
	ety = sqrt( ( carsom / nbn ) - ( ( som * som ) /  ( nbn * nbn ) ) ); // Calcul de l'écart-type
	printf("La moyenne est : %f\n", moy); 
	printf("La note la plus basse : %f\n", min);
	printf("La note la plus haute : %f\n", max);
	printf("l'%ccart-type : %f\n", 130, ety);
} else {
	printf("Vous n'avez pas saisi de notes...\n");
}
// Libération de la mémoire allouée dynamiquement
free(pNotes);
return 0;
}