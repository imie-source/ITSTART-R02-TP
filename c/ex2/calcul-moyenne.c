#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float verificationSaisie(char *chaine) {
	// D�finition des variables locales
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
 * Premi�re fonction appel�e par le programme
 *
 * @return int Code de fin
 */
int main() {

// D�finition des variables globales
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
 * @var pointer pNotes Pointeur vers les notes allou�es en m�moire
 */
float *pNotes;

/**
 * @var pointer pTmp Pointeur "temporaire" pour la r�allocation de m�moire
 */
float *pTmp;

// L'algorithme

// Allocation dynamique d'un float en m�moire ! penser � lib�rer !
pNotes = malloc(1*sizeof(float)); 

printf("Veuillez saisir les notes, finir par le mot 'fin'\n");
while( strcmp(saisie, "fin") ) {
	gets(saisie);
	note = verificationSaisie(saisie);
	if (note >= 0) {
		// Je stocke la note dans pNotes � l'indice nbn
		pNotes[nbn] = note;
		// J'alloue un float suppl�mentaire dans le "tableau"
		pTmp = realloc(pNotes, (nbn+2)*(sizeof(float)));
		// Si l'allocation s'est bien pass�e
		if (pTmp != NULL) {
			// On fait pointer pNotes vers la nouvelle plage de m�moire
			pNotes = pTmp;
		} else {
			// On indique qu'il n'y plus de m�moire
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
	ety = sqrt( ( carsom / nbn ) - ( ( som * som ) /  ( nbn * nbn ) ) ); // Calcul de l'�cart-type
	printf("La moyenne est : %f\n", moy); 
	printf("La note la plus basse : %f\n", min);
	printf("La note la plus haute : %f\n", max);
	printf("l'%ccart-type : %f\n", 130, ety);
} else {
	printf("Vous n'avez pas saisi de notes...\n");
}
// Lib�ration de la m�moire allou�e dynamiquement
free(pNotes);
return 0;
}