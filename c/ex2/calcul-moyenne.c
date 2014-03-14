#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

/**
 * Affiche l'ensemble des notes, une par ligne
 *
 * @param int nbNotes Nombre de notes saisies
 * @param array tab Tableau des notes
 */
void afficherNotes(int nbNotes, float tab[]) {
	/**
	 * @var int i index de parcours des notes
	 */
	int i;
	printf("Voici les notes saisies :\n");
	for(i = 0; i < nbNotes; i++) {
		printf("\tnote %d : %2.2f\n", (i+1), tab[i]); 
	}
}

/**
 * Première fonction appelée par le programme
 *
 * Effectue la saisie des notes, puis le calcul de la moyenne,
 * du min, du max et de l'écart-type de l'ensemble des notes
 *
 * @author Serge COUDÉ
 * @return int Code de fin
 */
int main() {

// Définition des variables globales
/**
 * @var array saisie Tableau de caractères pour la saisie de note
 */ 
char saisie[6];
/**
 * @var float moy Moyenne des notes
 */
float moy;
/**
 * @var float som Somme des notes
 */
float som = 0;
/**
 * @var int nbn Nombre des notes
 */
int nbn = 0;
/**
 * @var float min Note la plus basse
 */
float min;
/**
 * @var float max Note la plus haute
 */
float max;
/**
 * @var float ety Ecart-type de l'ensemble des notes
 */
float ety;
/**
 * @var float note Note 
 */
float note;
/**
 * @var float carsom Somme des carrés des notes
 */
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

printf("Veuillez saisir les notes, finir par le mot 'fin'\n");
while( strcmp(saisie, "fin") ) {
	gets(saisie);
	note = verificationSaisie(saisie);
	if (note >= 0) {
		// Je stocke la note dans pNotes à l'indice nbn
		if (nbn == 0) {
			/* On n'a pas encore alloué de mémoire, on utilise
			   donc malloc
			  */
			pNotes = malloc(1*sizeof(float)); 
			if (pNotes == NULL) {
				// On indique qu'il n'y plus de mémoire
				printf("Plus de m%cmoire disponible...", 130);
				// et on termine le programme avec un code erreur
				return -1;
			}
		} else {
			// J'alloue un float supplémentaire dans le "tableau"
			pTmp = realloc(pNotes, (nbn+1)*(sizeof(float)));
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
		}
		// Maintenant, j'ai la mémoire disponible pour stocker la note
		pNotes[nbn] = note;
		nbn++; 
		
		if (nbn == 1) {
			min = note;
			max = note;
		}
		som += note;
		carsom += (note*note);
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